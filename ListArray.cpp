#include "ListArray.h"

ListArray::ListArray(int capacity)
{
    head = new NodeArray(capacity, nullptr);
    head->size = 0;
    head->capacity = capacity;
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
        NodeArray *new_node = new NodeArray(head->capacity, head);
        new_node->size = 0;
        //new_node->next = head;
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
        nodo_actual->next = new NodeArray(head->capacity, nullptr);
        nodo_actual = nodo_actual->next;
        nodo_actual->size = 0;
        //nodo_actual->next = nullptr;
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
/*
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
*/
/*
void ListArray::createNodeR(){
    NodeArray *actual_node = this->head;
    for (int i = 1; i <= this->totalNodes()/2; i++)
    {   
        while (actual_node != nullptr && actual_node->next != nullptr)
    {
        //for (int i = 1; i <= this->totalNodes()/2; i++){
            NodeResumen* NR_i = new NodeResumen (*actual_node, *actual_node->next);
            cout << "Nodo Resumen " << i << ". Size: " << NR_i->size << ". Capacity: " << NR_i->capacity << endl; 
            cout << i << "." << NR_i->name << endl;
        //}  
        i++;
        
        actual_node = actual_node->next->next;
        }
    }
}
*/

vector<NodeResumen *> ListArray::createNodeR(NodeArray *head)
{
    std::vector<NodeResumen *> resumen_nodes;
    NodeArray *actual_node = head;

    for (int i = 1; i <= totalNodes(head) / 2; i++)
    {
        while (actual_node != nullptr && actual_node->next != nullptr)
        {
            NodeResumen *NR_i = new NodeResumen(*actual_node, *actual_node->next);
            resumen_nodes.push_back(NR_i);
            actual_node = actual_node->next->next;
            cout << i << "." << NR_i->name << endl;
            i++;
        }
    }

    return resumen_nodes;
}

int ListArray::totalNodes(NodeArray *head)
{
    int count = 0;
    NodeArray *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

void ListArray::crearArbol(ListArray la)
{

 NodeArray* actual = head;
    la.clear();
    while (actual != nullptr)
    {
        NodeResumen* ref = new NodeResumen(actual,actual->size(),actual->totalSize());
        arbol.push_back(ref);
        actual = actual->getNext();
    }
    if(head->getNext() == nullptr) arbol.push_back(nullptr);
    while(arbol.size()>1)
    {
        if(arbol.size()%2 != 0)
        {
            arbol.push_back(nullptr);
        }
        int maxNodosPerLevel = arbol.size()/2;
        for(int i=0; i<maxNodosPerLevel; i++)
        {
            NodoResumen* left = arbol.front();
            arbol.pop_front();
            NodoResumen* right = arbol.front();
            arbol.pop_front();
            if(right == nullptr)
            {
                NodoResumen* padre = new NodoResumen(left, right, left->getCapacity(), left->getMaxCapacity()*2);
                arbol.push_back(padre);
                continue;
            }
            NodoResumen* padre =new NodoResumen(left, right, left->getCapacity()+right->getCapacity(), left->getMaxCapacity()*2);
            arbol.push_back(padre);
        }
    }
    root = arbol.front();
    actualSize = arbol.front()->getCapacity();
    maxSize = arbol.front()->getMaxCapacity();

}
/*
NodeResumen *create_tree_recursive(const std::vector<NodeResumen *> &nodes, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    if (start == end)
    {
        return nodes[start];
    }

    int mid = start + (end - start) / 2;
    NodeResumen *left = create_tree_recursive(nodes, start, mid);
    NodeResumen *right = create_tree_recursive(nodes, mid + 1, end);

    return new NodeResumen(*static_cast<NodeArray *>(left->left), *static_cast<NodeArray *>(right->left));
}
*/