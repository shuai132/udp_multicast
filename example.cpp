#include "udp_multicast.hpp"
#include <cstdio>

int main() {
  using namespace udp_multicast;
  std::thread([]{
    asio::io_context context;
    udp_multicast::receiver receiver(context, [](const std::string& name, const std::string& message) {
      printf("found: %s: %s\n",  name.c_str(), message.c_str());
    });
    context.run();
  }).detach();
  std::thread([]{
    asio::io_context context;
    udp_multicast::sender sender(context, "example", "hello world");
    context.run();
  }).join();
}
