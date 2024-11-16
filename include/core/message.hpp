#pragma once

#include <string>

namespace core {
class Message {
public:
    Message(const std::string& msg);
    void print() const;
private:
    std::string message_;
};
}  // namespace core
