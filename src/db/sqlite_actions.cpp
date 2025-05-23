#include <sqlite3.h>
#include <string>
#include "../../headers/sqlite_wrap.h"

static int select_callback(void *data, int argc, char **argv, char **colname) {
  int amount = NOT_FOUND_AMOUNT;
  int* amount_ptr = (int*)data;
  amount = std::stoi(argv[argc - 1]);
  *amount_ptr = amount;
  return 0;
}

static std::string get_column_str(int column) {
  switch(column){
    case CURRENCY:
      return "CURRENCY";
    case RECOMMENDATIONS:
      return "RECS";
    default:
      return "";
  }
}

namespace sql {
  int get(sqlite3 **DB, int userID, int* amount, int column) {
    char* errmsg;
    int res = 0;
    std::string column_str = "";
    *amount = NOT_FOUND_AMOUNT;

    column_str = get_column_str(column);
    if (column_str == "") {
      return -1;
    }

    std::string sql = "SELECT " + column_str + " FROM RECS_CURR WHERE USER_ID = " + std::to_string(userID) + ";";
    res = sqlite3_exec(*DB, sql.c_str(), select_callback, amount, &errmsg);
    if (res != SQLITE_OK) {
      printf("%s\n", errmsg);
      sqlite3_free(errmsg);
      return res;
    }

    return 0;
  }

  int modify(sqlite3 **DB, int userID, int amount, int column) {
    int old_amount;
    int res;
    char* errmsg;
    std::string column_str = "";
    std::string sql;
    column_str = get_column_str(column);
    
    res = sql::get(DB, userID, &old_amount, column);
    
    if (res != 0) {
      return res;
    }

    if (old_amount == NOT_FOUND_AMOUNT) {
      sql = "INSERT INTO RECS_CURR(USER_ID, RECS, CURRENCY) VALUES (" + std::to_string(userID);

      if (column == CURRENCY) {
        sql = sql + ", 0, " + std::to_string(amount) + ");";
      } 
      
      else if (column == CURRENCY) {
        sql = sql + ", " + std::to_string(amount) + ", 0);";
      }

      res = sqlite3_exec(*DB, sql.c_str(), NULL, 0, &errmsg);

      if (res != SQLITE_OK) {
        printf("%s\n", errmsg);
        sqlite3_free(errmsg);
        return res;
      }
    } else {
      sql = "UPDATE RECS_CURR SET " + column_str + " = " + std::to_string(old_amount + amount) + " WHERE USER_ID = " + std::to_string(userID) + ";";
      
      res = sqlite3_exec(*DB, sql.c_str(), NULL, 0, &errmsg);

      if (res != SQLITE_OK) {
        printf("%s\n", errmsg);
        sqlite3_free(errmsg);
        return res;
      }
    }
    return 0;
  }
}
