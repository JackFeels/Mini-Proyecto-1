#include "ListArray_utils.h"

vector<NodeArray*> node_arrays_to_vector(ListArray &list_array) {
    
    vector<NodeArray*> node_array_vector;
    NodeArray *current_node = list_array.head;
    
     while (current_node != nullptr) {
        node_array_vector.push_back(current_node);
        current_node = current_node->next;
    }

    return node_array_vector;
};
// Función auxiliar para construir el árbol de forma recursiva
SummaryNode* buildTree(ListArray &a, vector<NodeArray*>& nodeArrays, int start, int end) {
    

    //int start = 0;
    //int end = nodeArrays.size();

    if (start == end) {
        return new SummaryNode(nodeArrays[start], nodeArrays[start + 1]);
    }
   
    int mid = (start + end) / 2;
   
    SummaryNode* left = buildTree(a, nodeArrays, start, mid);
    SummaryNode* right = buildTree(a, nodeArrays, mid + 1, end);
   
    return new SummaryNode(left, right);
}

// Función principal para crear el árbol de SummaryNodes
SummaryNode* createSummaryNodeTree(ListArray &a) {
    
    vector <NodeArray*> nodeArrays = node_arrays_to_vector(a);

    if (nodeArrays.size() < 2) {
        return nullptr;
    }
   
    return buildTree(a, nodeArrays, 0, nodeArrays.size() - 2);
};