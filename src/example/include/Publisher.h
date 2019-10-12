#pragma once

#include <ros/ros.h>

namespace example {

template <typename T>
class Publisher {
 public:
  static constexpr const size_t kDefaultHistorySize = 1000U;

  Publisher(ros::NodeHandle ros_node, const std::string &topic, size_t history = kDefaultHistorySize)
      : subscribers_{0U} {
    publisher_ = ros_node.advertise<T>(topic, history, boost::bind(&Publisher::onSubscribe, this, _1),
                                       boost::bind(&Publisher::onDisconnect, this, _1));
  }

  void Publish(const T &message) { publisher_.publish(message); }

  size_t subscribers() const { return subscribers_; }

 protected:
  void onSubscribe(const ros::SingleSubscriberPublisher &status) {
    subscribers_++;
    ROS_INFO("%s %s", status.getSubscriberName().c_str(), "connects");
  }

  void onDisconnect(const ros::SingleSubscriberPublisher &status) {
    subscribers_--;
    ROS_INFO("%s %s", status.getSubscriberName().c_str(), "disconnects");
  }

 private:
  size_t subscribers_;
  ros::Publisher publisher_;
};

}  // namespace example
