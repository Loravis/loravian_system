#include "../../headers/commands.h"
#include <dpp/appcommand.h>

void cmd::setup_commands(dpp::cluster *bot) {
  bot->on_slashcommand([](const dpp::slashcommand_t& event) {
    if (event.command.get_command_name() == "test") {
      cmd::test(&event);
    } else if (event.command.get_command_name() == "add") {
      cmd::add(&event);
    }
  });
}

void cmd::create_commands(dpp::cluster *bot) {
  bot->on_ready([bot](const dpp::ready_t& event) {
    if (dpp::run_once<struct register_bot_commands>()) {
      bot->global_command_create(dpp::slashcommand("test", "Test the bot.", bot->me.id));

      // Add currency or recommendations
      dpp::slashcommand cmd_add("add", "(ADMIN) Add currency or promotion recommendations to users.", bot->me.id);
      cmd_add.add_option(
        dpp::command_option(dpp::co_string, "option", "Select what to add", true)
          .add_choice(dpp::command_option_choice("Currency", std::string("currency")))
          .add_choice(dpp::command_option_choice("Recommendation", std::string("recommendation")))
      );
      cmd_add.add_option(
        dpp::command_option(dpp::co_string, "username", "User(s) to add to. Separate multiple users with a space.", true)
      );
      cmd_add.add_option(
        dpp::command_option(dpp::co_integer, "amount", "The amount to add", true)
      );
      bot->global_command_create(cmd_add);
    }
  });
}