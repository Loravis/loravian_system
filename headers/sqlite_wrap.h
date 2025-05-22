#include <sqlite3.h>

namespace sql {
  int init(const char* path, sqlite3** DB);
  int add_currency(sqlite3** DB, int userID, int amount);
}