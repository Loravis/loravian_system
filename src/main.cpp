#include <dpp/dpp.h>
#include "../env/env.h"
#include "../headers/commands.h"
#include "../headers/sqlite_wrap.h"

int main() {
  int res = 0;

  // Initialize SQLite database
  res = sql::init(SQL_FILE_PATH.c_str());

  if (res) {
    std::cerr << "Init failed. Shutting down...\n";
    return 0;
  }

  // Initialize bot
  dpp::cluster bot(BOT_TOKEN);
  bot.on_log(dpp::utility::cout_logger());
  cmd::create_commands(&bot);
  cmd::setup_commands(&bot);
  bot.start(dpp::st_wait);
}