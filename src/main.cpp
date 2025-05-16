#include <dpp/dpp.h>
#include "../env/env.h"
#include "../headers/commands.h"

int main() {
  dpp::cluster bot(BOT_TOKEN);
  bot.on_log(dpp::utility::cout_logger());

  cmd::create_commands(&bot);

  cmd::setup_commands(&bot);
  
  bot.start(dpp::st_wait);
}