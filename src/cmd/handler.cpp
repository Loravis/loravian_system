#include "../../headers/commands.h"

void cmd::setup_commands(dpp::cluster *bot) {
  bot->on_slashcommand([](const dpp::slashcommand_t& event) {
    if (event.command.get_command_name() == "test") {
      cmd::test(&event);
    }
  });
}

void cmd::create_commands(dpp::cluster *bot) {
  bot->on_ready([bot](const dpp::ready_t& event) {
    if (dpp::run_once<struct register_bot_commands>()) {
      bot->global_command_create(dpp::slashcommand("test", "Test the bot.", bot->me.id));
    }
  });
}