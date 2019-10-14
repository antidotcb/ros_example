#include <nodelet/nodelet.h>

namespace example {

class PublisherNodelet : public nodelet::Nodelet {
 public:
  void onInit() override;
};

}