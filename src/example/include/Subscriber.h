#pragma once

#include <ros/ros.h>

namespace example {

class Subscriber {
 public:
  explicit Subscriber(const ros::Subscriber& subscriber) : subscriber_{subscriber} {}

 private:
  ros::Subscriber subscriber_;
};

}  // namespace example
