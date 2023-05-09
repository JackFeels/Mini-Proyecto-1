#include <iostream>
#include <string>

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
    string name;

    NodeResumen(NodeArray a, NodeArray b){
        this->capacity = a.capacity + b.capacity;
        this->size = a.size + b.size;
        this->left = &a;
        this->right = &b;
        this->name = "Nodo Resumen " + to_string(size) + "||" + to_string(capacity);
    };
    
    NodeResumen(NodeResumen *a, NodeResumen *b){
        this->capacity = a->capacity + b->capacity;
        this->size = a->size + b->size;
        this->left = &a;
        this->right = &b;   
    };




};

/*
NodoResumen::NodoResumen(NodoResumen* left, NodoResumen* right,int capacity, int maxCapacity)
{
    this->son = nullptr;
    this->left = left;
    this->right = right;
    this->capacity = capacity;
    this->maxCapacity = maxCapacity;
}

NodoResumen::NodoResumen(int capacity, int maxCapacity)
{
    this->son = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->capacity = capacity;
    this->maxCapacity = maxCapacity;
}

NodoResumen::NodoResumen(Nodo *son, int capacity, int maxCapacity)
{
    this->son = son;
    this->left = nullptr;
    this->right = nullptr;
    this->capacity = capacity;
    this->maxCapacity = maxCapacity;
}

NodoResumen::NodoResumen(NodoResumen* left, NodoResumen* right)
{
    this->son = nullptr;
    this->left = left;
    this->right = right;
    this->capacity = 0;
    this->maxCapacity = 0;

}

END!!!!!

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