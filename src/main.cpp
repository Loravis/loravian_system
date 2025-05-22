#include <dpp/dpp.h>
#include <sqlite3.h>
#include "../env/env.h"
#include "../headers/commands.h"
#include "../headers/sqlite_wrap.h"

int main() {
  int res = 0;
  sqlite3* DB;

  // Initialize SQLite database
  res = sql::init(SQL_FILE_PATH.c_str(), &DB);

  if (res) {
    std::cerr << "Init failed. Shutting down...\n";
    return 0;
  }

  // Initialize bot
  dpp::cluster bot(BOT_TOKEN);
  bot.on_log(dpp::utility::cout_logger());
  // TODO: Create commands only if necessary
  cmd::create_commands(&bot);
  cmd::setup_commands(&bot);
  bot.start(dpp::st_wait);
}