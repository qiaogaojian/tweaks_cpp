#include "core/message.hpp"
#include <iostream>

namespace core {
Message::Message(const std::string& msg) : message_(msg) {}

void Message::print() const {
    std::cout << message_ << std::endl;
}
}  // namespace core
