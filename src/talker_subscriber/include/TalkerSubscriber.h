#pragma once

#include <Node.h>
#include <std_msgs/String.h>

namespace example {
namespace subscriber {

class TalkerSubscriber : public Node {
 public:
  TalkerSubscriber();

  void Init() override;
  void Cycle() override;

 protected:
 public:
  void Run(double frequency) override;
 protected:
  void Stop() override;

 private:
  void OnMessage(const std_msgs::String::ConstPtr& message);

 private:
  std::unique_ptr<Subscriber> publish_subscriber_;
};

}  // namespace subscriber
}  // namespace example
