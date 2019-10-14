#include <pluginlib/class_list_macros.h>
#include <ros/node_handle.h>

#include "nodelet.h"

namespace example {

void PublisherNodelet::onInit() {
  NODELET_INFO("Initializing nodelet...");
  ros::NodeHandle& node_handle = this->getNodeHandle();
  (void)node_handle;
}

}  // namespace example

PLUGINLIB_EXPORT_CLASS(example::PublisherNodelet, nodelet::Nodelet)
