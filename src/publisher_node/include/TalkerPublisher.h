#pragma once

#include <Node.h>
#include <std_msgs/String.h>

namespace example {
namespace publisher {

class PublisherNode : public Node {
 public:
  PublisherNode();

  void Init() override;

 protected:
  void Stop() override;

 private:
  std_msgs::String PrepareMessage() const;

  void Cycle() override;

 private:
  std::unique_ptr<Publisher<std_msgs::String>> publisher_;
};

}  // namespace publisher
}  // namespace example
