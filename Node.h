#pragma once

class Node {
    public:
        char data;
        int position;
        Node* next;

        Node(char data, int position);
};