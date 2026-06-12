#pragma once
#include <string>

class InputException {
    private:
        std::string message;

    public:
        InputException(const std::string& msg) : message(msg) {}

        std::string getMessage() const {
            return message;
        }
};