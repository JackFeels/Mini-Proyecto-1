#include <iostream>
using namespace std;

class NodeArray{
private:

public:
    int *data;
    NodeArray *next;
    int capacity;
    int size;
    NodeArray(int capacity, NodeArray *next = nullptr);
    ~NodeArray();
    bool insert(int index, int value);
    int getSize();
    int getData(int index);
    int getCapacity();

};