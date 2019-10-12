#include "TalkerPublisher.h"

namespace example {
namespace publisher {

PublisherNode::PublisherNode() : Node("publisher_node") {}

void PublisherNode::Init() {
  Node::Init();
  publisher_ = std::move(CreatePublisher<std_msgs::String>("publish"));
  ROS_INFO("Publisher initialized.");
}

void PublisherNode::Stop() {
  Node::Stop();
  ROS_INFO("Publisher stopped.");
}

std_msgs::String PublisherNode::PrepareMessage() const {
  std_msgs::String message;
  std::stringstream ss;
  ss << "Test message";
  message.data = ss.str();
  return message;
}

void PublisherNode::Cycle() {
  auto message = PrepareMessage();
  publisher_->Publish(message);
  ROS_INFO("%s %s", "Published: ", message.data.c_str());
}

}  // namespace publisher
}  // namespace example
