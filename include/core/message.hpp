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

#ifndef CORE_MESSAGE_HPP
#define CORE_MESSAGE_HPP

#endif // CORE_MESSAGE_HPP
