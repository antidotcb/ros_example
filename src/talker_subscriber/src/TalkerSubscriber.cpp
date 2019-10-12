//
// Created by dbilyk on 12.10.19.
//

#include "TalkerSubscriber.h"
#include <cassert>

namespace example {
namespace subscriber {

TalkerSubscriber::TalkerSubscriber() : Node{"subscriber"} {}

void TalkerSubscriber::Init() {
  Node::Init();
  constexpr size_t kQueueLength = 1000U;
  publish_subscriber_ = Subscribe("publish", kQueueLength, &TalkerSubscriber::OnMessage, this);
  ROS_INFO("Subscriber initialized.");
}

void TalkerSubscriber::Stop() {
  Node::Stop();
  ROS_INFO("Subscriber stopped.");
}

void TalkerSubscriber::Cycle() {}

void TalkerSubscriber::OnMessage(const std_msgs::String::ConstPtr& message) {
  assert(message);
  ROS_INFO("Received: %s", message->data.c_str());
}

void TalkerSubscriber::Run(double frequency) {
  (void)frequency;
  ros::spin();
}

}  // namespace subscriber
}  // namespace example
