#include "../../headers/commands.h"
#include <dpp/colors.h>
#include <dpp/message.h>

dpp::embed create_add_embed() {
  dpp::embed embed = dpp::embed()
    .set_color(dpp::colors::green)
    .set_title("Test")
    .set_description("This is a placeholder")
    .set_timestamp(std::time(nullptr));

  return embed;
};

void cmd::add(const dpp::slashcommand_t *event) {
  dpp::message msg(event->command.channel_id, create_add_embed());
  msg.set_flags(dpp::m_ephemeral);
  event->reply(msg);
}