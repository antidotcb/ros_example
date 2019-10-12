#include "TalkerPublisher.h"

int main(int argc, char **argv) {
  example::program_arguments.Store(argc, argv);
  example::publisher::PublisherNode node;
  node.Init();
  node.Run(1.0);
  return 0;
}