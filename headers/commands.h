#ifndef COMMANDS
#define COMMANDS

#include <dpp/dpp.h>

namespace cmd {
  void setup_commands(dpp::cluster* bot);
  void create_commands(dpp::cluster* bot);

  void test(const dpp::slashcommand_t* event);
}

#endif