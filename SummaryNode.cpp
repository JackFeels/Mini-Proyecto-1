#include "SummaryNode.h"

SummaryNode::SummaryNode(NodeArray *a, NodeArray *b)
{
    this->a_left = a;
    this->a_right = b;
    this->s_size = a->size + b->size;
    this->s_capacity = a->capacity + b->capacity;
}

SummaryNode::SummaryNode(SummaryNode *a, SummaryNode *b)
{
    this->left = a;
    this->right = b;
    this->s_size = a->s_size + b->s_size;
    this->s_capacity = a->s_capacity + b->s_capacity;
}