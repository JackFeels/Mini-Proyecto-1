#include "SummaryNode.h"

SummaryNode::SummaryNode(NodeArray* left, NodeArray* right)
    : left(left), right(right),
      total_capacity(left->capacity + right->capacity),
      total_size(left->size + right->size) {}
NodeArray* SummaryNode::getLeft(){
    return this->left;
}

NodeArray* SummaryNode::getRight(){
    return this->right;
}

int SummaryNode::getTotalCapacity(){
    return this->total_capacity;
}

int SummaryNode::getTotalSize(){
    return this->total_size;
}
void SummaryNode::update(){
    total_size = left->size + (right ? right->size : 0);
    total_capacity = left->b + (right ? right->b : 0);
}