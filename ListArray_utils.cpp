#include "ListArray_utils.h"

SummaryNode* buildSummary(vector<NodeArray*>& nodes, int start, int end) {
    if (end - start == 1) {
        return new SummaryNode(nodes[start], nodes[end]);
    } else if (end - start > 1) {
        int mid = start + (end - start) / 2;
        auto left_child = buildSummary(nodes, start, mid);
        auto right_child = buildSummary(nodes, mid + 1, end);
        return new SummaryNode(left_child->getLeft() ? left_child->getLeft() : left_child->getRight(),
                               right_child->getLeft() ? right_child->getLeft() : right_child->getRight());
    } else if (end == start) {
        return new SummaryNode(nodes[start], nullptr);
    }
    return nullptr;
}
/*
bool insertElementAtIndex(SummaryNode* summary_root, int index, int value) {
    if (index > summary_root->getTotalSize()) {
        return false; // Índice fuera de rango.
    }

    SummaryNode* current = summary_root;
    while (current->getLeft() != nullptr && current->getRight() != nullptr) {
        current->update();
        if (current->getLeft()->size > index) {
            current = new SummaryNode(current->getLeft()->getLeft(), current->getLeft()->getRight());
        } else {
            index -= current->getLeft()->size;
            current = new SummaryNode(current->getRight()->getLeft(), current->getRight()->getRight());
        }
    }

    bool success = current->getLeft()->insert(index, value);
    if (success) {
        // Actualizar el tamaño total en todos los nodos resumen que abarcan el nodo donde se insertó el elemento.
        current = summary_root;
        while (current != nullptr) {
            current->update();
            if (current->getLeft()->size > index) {
                current = current->getLeft()->getLeft() ? new SummaryNode(current->getLeft()->getLeft(), current->getLeft()->getRight()) : nullptr;
            } else {
                index -= current->getLeft()->size;
                current = current->getRight()->getLeft() ? new SummaryNode(current->getRight()->getLeft(), current->getRight()->getRight()) : nullptr;
            }
        }
    }

    return success;
}
*/