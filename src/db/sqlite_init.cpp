#include <iostream>
#include <filesystem>
#include <sqlite3.h>
#include "../../headers/sqlite_wrap.h"

namespace sql {
  int init(const char* path, sqlite3** DB) {
    int res = 0;
    bool create_db = false;
    char* errmsg;

    std::string sql = "CREATE TABLE RECS_CURR(USER_ID INT PRIMARY KEY NOT NULL, RECS INT, CURRENCY INT);";

    if (!std::filesystem::exists(path)) {
      create_db = true;
    }

    res = sqlite3_open(path, DB);

    if (res) {
      std::cout << "Database connection failed: " << sqlite3_errmsg(*DB) << '\n';
      return -1;
    }

    if (!create_db) {
      return 0;
    }

    res = sqlite3_exec(*DB, sql.c_str(), NULL, 0, &errmsg);

    if (res != SQLITE_OK) {
      std::cerr << errmsg << '\n';
      sqlite3_free(errmsg);
      sqlite3_close(*DB);
      return -1;
    }

    return 0;
  }
}