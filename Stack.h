#pragma once
#include "Node.h"

class Stack {
    private:
        Node* top;

    public:
        Stack();

        bool isEmpty();

        void push(char value, int pos);

        void pop();

        char peek();

        int topPosition();

        ~Stack();
};