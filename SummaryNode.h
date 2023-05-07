#include <iostream>
#include "Structs.h"

class SummaryNode{
private:
    NodeArray* left;
    NodeArray* right;
    int total_capacity;
    int total_size;
public:
    SummaryNode(NodeArray *left, NodeArray *right);
    NodeArray *getLeft();
    NodeArray *getRight();
    int getTotalCapacity();
    int getTotalSize();
    void update();
};