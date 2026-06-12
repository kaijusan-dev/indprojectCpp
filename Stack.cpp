#include "Stack.h"
#include "StackException.h"

Stack::Stack() {
    top = nullptr;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::push(char value, int pos) {
    Node* n = new Node(value, pos);
    n->next = top;
    top = n;
}

void Stack::pop() {
    if (isEmpty()) throw StackException("Попытка pop() из пустого стека");

    Node* tmp = top;
    top = top->next;
    delete tmp;
}

char Stack::peek() {
    if (isEmpty()) throw StackException("Попытка peek() из пустого стека");

    return top->data;
}

int Stack::topPosition() {
    if (isEmpty()) throw StackException("Стек пуст");

    return top->position;
}

Stack::~Stack() {
    while (!isEmpty()) pop();
}