#pragma once

namespace example {

struct ProgramArguments {
  int argc;
  char **argv;
  void Store(int _argc, char **_argv);
};

extern ProgramArguments program_arguments;

}  // namespace example
