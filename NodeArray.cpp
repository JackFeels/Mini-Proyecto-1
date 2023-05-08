#include "NodeArray.h"

NodeArray::NodeArray(int capacity, NodeArray *next) {
    this->data = new int [capacity];
    this->size = 0;
    this->next = next;
}