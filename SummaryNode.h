#pragma once 
#include "NodeArray.h"

class SummaryNode {
    public:
        int s_size;
        int s_capacity;
        SummaryNode *left;
        SummaryNode *right;
        NodeArray *a_left;
        NodeArray *a_right;

    SummaryNode (NodeArray *a, NodeArray *b);
    SummaryNode (SummaryNode *a, SummaryNode *b);

};