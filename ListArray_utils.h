#pragma once
#include "ListArray.h"
#include "SummaryNode.h"
#include <vector>
using namespace std;

// Función auxiliar para construir el árbol de forma recursiva
SummaryNode* buildTree(ListArray *a, vector<NodeArray*>& nodeArrays, int start, int end);

// Función principal para crear el árbol de SummaryNodes
SummaryNode* createSummaryNodeTree(ListArray *a);
vector<NodeArray*> node_arrays_to_vector(ListArray *list_array);