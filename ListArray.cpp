#include "ListArray.h"

ListArray::ListArray(int capacity)
{
    head = new NodeArray(capacity);
    head->size = 0;
    head->capacity = capacity;
    head->next = nullptr;
}
ListArray::~ListArray()
{
    NodeArray *nodo_actual = head;
    while (nodo_actual != nullptr)
    {
        NodeArray *next_node = nodo_actual->next;
        delete nodo_actual;
        nodo_actual = next_node;
    }
}
int ListArray::size()
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
void ListArray::insert_left(int v)
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
void ListArray::print()
{
    NodeArray *nodo_actual = head;
    while (nodo_actual != nullptr)
    {
        for (int i = 0; i < nodo_actual->size; i++)
        {
            std::cout << nodo_actual->data[i] << " ";
        }
        nodo_actual = nodo_actual->next;
    }
    std::cout << std::endl;
}
void ListArray::insert_right(int v) {
    NodeArray*  nodo_actual= head;
    while (nodo_actual->next != nullptr) {
        nodo_actual = nodo_actual->next;
    }
    if (nodo_actual->size == nodo_actual->capacity) {
        nodo_actual->next = new NodeArray(head->capacity);
        nodo_actual = nodo_actual->next;
        nodo_actual->size = 0;
        nodo_actual->next = nullptr;
    }
    nodo_actual->data[nodo_actual->size] = v;
    nodo_actual->size++;
}
void ListArray::insert(int v, int i)
{
    // Si la lista está vacía o i == size(), insertar al final
    if (head == nullptr || i == size())
    {
        insert_right(v);
    }
}
bool ListArray::find(int v)
{
    NodeArray *nodo_actual = head;
    while (nodo_actual != nullptr)
    {
        for (int i = 0; i < nodo_actual->size; i++)
        {
            if (nodo_actual->data[i] == v)
            {   
                cout << "El elemento " << v << " se encuentra en el ListArr" << endl;
                return true;
            }
        }
        nodo_actual = nodo_actual->next;
    }
    cout << "El elemento " << v << " NO se encuentra en el ListArr" << endl;
    return false;
}
int ListArray::totalNodes(){
    NodeArray *actual_node = this->head;
    int totalNodes = 0;
    while (actual_node!= nullptr)
    {
        totalNodes = totalNodes + 1;
        actual_node = actual_node->next;
    }
    return totalNodes;
}

void ListArray::createNodeR(){
    NodeArray *actual_node = this->head;
    for (int i = 1; i <= this->totalNodes()/2; i++)
    {   
        while (actual_node != nullptr && actual_node->next != nullptr)
    {
        //for (int i = 1; i <= this->totalNodes()/2; i++){
            NodeResumen NR_i (*actual_node, *actual_node->next);
            cout << "Nodo Resumen" << i << " size: " << NR_i.size << endl;
        //}   
        i++;
        actual_node = actual_node->next->next;
        }
    }
}
