#include "../../headers/commands.h"
#include <dpp/colors.h>
#include <dpp/message.h>

dpp::embed create_test_embed() {
  dpp::embed embed = dpp::embed()
    .set_color(dpp::colors::green)
    .set_title("Hello, world!")
    .set_description("This is an indicator that the bot is alive and working! if you can see this, it means that everything is set up correctly.")
    .set_timestamp(std::time(nullptr));

  return embed;
};

void cmd::test(const dpp::slashcommand_t *event) {
  dpp::message msg(event->command.channel_id, create_test_embed());
  msg.set_flags(dpp::m_ephemeral);
  event->reply(msg);
}