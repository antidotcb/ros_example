#include "ProgramArguments.h"

namespace example {
ProgramArguments program_arguments;

void ProgramArguments::Store(const int _argc, char** const _argv) {
  argc = _argc;
  argv = _argv;
}

}
