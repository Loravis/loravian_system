#include "../../headers/commands.h"

void cmd::test(const dpp::slashcommand_t *event) {
  event->reply("Hello world!");
}