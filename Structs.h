#include <iostream>

using namespace std;

/// @brief Nodo que contiene Array
struct NodeArray
{
    int *data; // b = 6 por ahora
    NodeArray *next;
    int capacity; // maximo
    int size;     // tamaño actual
    NodeArray(int capacity, NodeArray *next = nullptr)
    {
        this->capacity = capacity;
        this->data = new int[capacity];
        this->next = next;
    };
};

struct NodeResumen{
    int capacity; // capacidad de ambos Nodos Array
    int size; // suma de la cantidad de elementos de ambos Nodos Array
    void* left;
    void* right;

    NodeResumen(NodeArray a, NodeArray b){
        this->capacity = a.capacity + b.capacity;
        this->size = a.size + b.size;
        this->left = &a;
        this->right = &b;

    };
    NodeResumen(NodeResumen a, NodeResumen b){
        this->capacity = a.capacity + b.capacity;
        this->size = a.size + b.size;
        this->left = &a;
        this->right = &b;

    };
};

/*

struct NodeResumen1{
    int capacity; // capacidad de ambos Nodos Array
    int size; // suma de la cantidad de elementos de ambos Nodos Array
    void* left;
    void* right;

    NodeResumen1(NodeResumen a, NodeResumen b){
        this->capacity = a.capacity + b.capacity;
        this->size = a.size + b.size;
        this->left = &a;
        this->right = &b;

    };
};
*/