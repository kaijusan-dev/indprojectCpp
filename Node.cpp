#include "Node.h"

Node::Node(char data, int position) {
    this->data = data;
    this->position = position;
    next = nullptr;
}