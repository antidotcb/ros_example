#include "Node.h"
#include "ProgramArguments.h"

namespace example {

Node::Node(const std::string& name) : handle_{nullptr} {
  ros::init(program_arguments.argc, program_arguments.argv, name);
}

Node::~Node() { ros::shutdown(); }

void Node::Init() { handle_.reset(new ros::NodeHandle()); }

void Node::Run(const double frequency) {
  ros::Rate loop_rate{frequency};

  while (ros::ok()) {
    Cycle();
    ros::spinOnce();
    loop_rate.sleep();
  }

  Stop();
}

void Node::Stop() {}

}  // namespace example
