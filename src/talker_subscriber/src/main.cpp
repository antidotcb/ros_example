#include "TalkerSubscriber.h"

int main(int argc, char **argv) {
  example::program_arguments.Store(argc, argv);
  example::subscriber::TalkerSubscriber node;
  node.Init();
  node.Run(1.0);
  return 0;
}