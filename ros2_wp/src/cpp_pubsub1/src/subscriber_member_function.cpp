#include <functional>
#include <memory>
#include <thread>
#include <atomic>
#include <mutex>

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minimal_subscriber")
  {
    subscription_ = this->create_subscription<tutorial_interfaces::msg::Num>(
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }

  ~MinimalSubscriber()
  {
    // if (worker_thread.joinable())
    //   worker_thread.join();
  }

private:
  void topic_callback(const tutorial_interfaces::msg::Num & msg)
  {
    RCLCPP_INFO_STREAM(this->get_logger(), "I heard: '" << msg.num << "'");

    // // Stop any running work
    // stop = true;
    // if (worker_thread.joinable())
    //   worker_thread.join();

    // // Reset stop flag and start new thread if needed
    // if (msg.num != 1) {
    //   stop = false;
    //   worker_thread = std::thread(&MinimalSubscriber::do_work, this);
    // }
  }

  // void do_work()
  // {
  //   std::cout<<stop<<std::endl;
  //   if (!stop) {
  //     std::cout << "first" << std::endl;
  //     std::this_thread::sleep_for(4s);
  //   }

  //   std::cout << "Half Done" << std::endl;
  //   std::cout<<stop<<std::endl;
  //   if (!stop) {
  //     std::cout << "second" << std::endl;
  //     std::this_thread::sleep_for(4s);
  //   }
  // }

  rclcpp::Subscription<tutorial_interfaces::msg::Num>::SharedPtr subscription_;
  std::atomic_bool stop;
  std::thread worker_thread;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
