#pragma once
#include <iostream>

class NodeArray {
    public:
        int size;
        int capacity;
        int *data;
        NodeArray *next;

        NodeArray (int capacity, NodeArray *next);
};