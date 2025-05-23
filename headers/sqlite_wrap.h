#ifndef SQLITE_WRAPPER
#define SQLITE_WRAPPER

#include <sqlite3.h>

#define NOT_FOUND_AMOUNT -9999

enum {
  CURRENCY = 1,
  RECOMMENDATIONS = 2
};

namespace sql {
  int init(const char* path, sqlite3** DB);
  int modify(sqlite3** DB, int userID, int amount, int column);
  int get(sqlite3** DB, int userID, int* amount, int column);
}

#endif