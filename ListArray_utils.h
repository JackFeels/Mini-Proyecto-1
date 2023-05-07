#include <vector>
#include "ListArray.h"
#include "SummaryNode.h"

int getElementAtIndex(SummaryNode* summary_root, int index);

SummaryNode* buildSummary(vector<NodeArray*>& nodes, int start, int end);
bool insertElementAtIndex(SummaryNode* summary_root, int index, int value);


