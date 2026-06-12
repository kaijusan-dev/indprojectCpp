#pragma once
#include <string>

class StackException {
    private:
        std::string message;

    public:
        StackException(const std::string& msg) : message(msg) {}

        std::string getMessage() const {
            return message;
        }
};