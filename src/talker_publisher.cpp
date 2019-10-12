//
// Created by dbilyk on 12.10.19.
//

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <boost/bind.hpp>
#include <thread>
#include <utility>

namespace example {

template <typename T>
class Publisher {
 public:
  Publisher(ros::NodeHandle ros_node, const std::string &topic, const std::size_t history = 1000U) : subscribers_{0U} {
    publisher_ = ros_node.advertise<T>(topic, history, boost::bind(&Publisher::onSubscribe, this, _1),
                                       boost::bind(&Publisher::onDisconnect, this, _1));
  }

  void Publish(const T &message) { publisher_.publish(message); }

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
  std::size_t subscribers_;
  ros::Publisher publisher_;
};

struct ProgramArguments {
  int argc;
  char **argv;
  void Store(const int _argc, char **const _argv) {
    argc = _argc;
    argv = _argv;
  }
} program_arguments;

class Node {
 public:
  Node(const std::string &name, const std::size_t frequency = 1U)
      : ros_node_{nullptr}, publisher_{nullptr}, frequency_{frequency} {
    ros::init(program_arguments.argc, program_arguments.argv, "talker_publisher");
  }

  ~Node() { ros::shutdown(); }

  void Init() {
    ros_node_.reset(new ros::NodeHandle());
    publisher_.reset(new Publisher<std_msgs::String>(*ros_node_, "publish"));
  }

  void Run() {
    ros::Rate loop_rate{frequency_};

    while (ros::ok()) {
      auto message = PrepareMessage();
      publisher_->Publish(message);
      ROS_INFO("%s %s", "Published: ", message.data.c_str());
      ros::spinOnce();
      loop_rate.sleep();
    }
  }

  std_msgs::String PrepareMessage() const {
    std_msgs::String message;
    std::stringstream ss;
    ss << "Test message";
    message.data = ss.str();
    return message;
  }

 private:
  std::unique_ptr<ros::NodeHandle> ros_node_;
  std::unique_ptr<Publisher<std_msgs::String>> publisher_;
  std::size_t frequency_;
};

}  // namespace example

int main(int argc, char **argv) {
  example::program_arguments.Store(argc, argv);
  example::Node node("publisher_node");
  node.Init();
  node.Run();
}