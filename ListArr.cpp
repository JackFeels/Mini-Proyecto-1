#include "ListArr.h"

ListArr::ListArr(int capacity)
{
    head = new NodeArray(capacity);
    head->size = 0;
    head->capacity = capacity;
    head->next = nullptr;
}
/*ListArr::~ListArr()
{
    NodeArray *nodo_actual = head;
    while (nodo_actual != nullptr)
    {
        NodeArray *next_node = nodo_actual->next;
        delete nodo_actual;
        nodo_actual = next_node;
    }
}
*/
int ListArr::size()
{
    int total_size = 0;
    NodeArray *nodo_actual = head;
    while (nodo_actual != nullptr)
    {
        total_size += nodo_actual->size;
        nodo_actual = nodo_actual->next;
    }
    return total_size;
}
void ListArr::insert_left(int v)
{
    if (head->size == head->capacity)
    {
        NodeArray *new_node = new NodeArray(head->capacity);
        new_node->size = 0;
        new_node->next = head;
        head = new_node;
    }
    for (int i = head->size; i > 0; i--)
    {
        head->data[i] = head->data[i - 1];
    }
    head->data[0] = v;
    head->size++;
}
void ListArr::print()
{
    NodeArray *current_node = head;
    while (current_node != nullptr)
    {
        for (int i = 0; i < current_node->size; i++)
        {
            std::cout << current_node->data[i] << " ";
        }
        current_node = current_node->next;
    }
    std::cout << std::endl;
}
