#include "NodeArray.h"

NodeArray::NodeArray(int capacity, NodeArray *next = nullptr)
{
    this->capacity = capacity;
    this->data = new int[capacity];
    this->next = next;
}

NodeArray::~NodeArray() {
    delete[] data;
}

int NodeArray::getCapacity(){
    return this->capacity;
}
int NodeArray::getSize(){
    return this->size;
}

int NodeArray::getData(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Índice fuera de rango.");
    }
    return data[index];
}

bool NodeArray::insert(int index, int value) {
    if (size == this->capacity) {
        return false; // No hay espacio para insertar un nuevo elemento.
    }

    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }

    data[index] = value;
    size++;

    return true;
}