#pragma once

#include <ros/ros.h>

#include <memory>
#include <string>

#include "ProgramArguments.h"
#include "Publisher.h"
#include "Subscriber.h"

namespace example {

class Node {
 public:
  explicit Node(const std::string& name);

  ~Node();

  virtual void Init();

  virtual void Run(double frequency);

  virtual void Cycle() = 0;

 protected:
  virtual void Stop();

  template <class M, class T>
  using Callback = void (T::*)(M);

  template <class M, class T>
  std::unique_ptr<Subscriber> Subscribe(const std::string& topic, const uint32_t queue_size, Callback<M, T> fp,
                                        T* obj) {
    std::unique_ptr<Subscriber> result{new Subscriber{handle_->subscribe(topic, queue_size, fp, obj)}};
    return std::move(result);
  }

  template <typename T>
  std::unique_ptr<Publisher<T>> CreatePublisher(const std::string& topic) {
    ros::NodeHandle& handle = *handle_;
    std::unique_ptr<Publisher<T>> result{new Publisher<T>(handle, topic)};
    return std::move(result);
  }

 private:
  std::unique_ptr<ros::NodeHandle> handle_;
};

}  // namespace example
