#pragma once
#include "ListArr.h"
#include "Structs.h"
#include <vector>

class ListArray : public ListArr{

public:
NodeArray* head;
ListArray(int capacity);
~ListArray();
 int size(); //Retorna la cantidad de elementos almacenados en el ListArr
 void insert_left(int v); //Inserta un nuevo valor v a la izquierda del ListArr. Equivalentemente, inserta el valor v en el índice 0
 void insert_right(int v); //Inserta un nuevo valor v a la derecha del ListArr. Equivalentemente, inserta el valor v en el índice size()-1
 void insert(int v, int i); //Inserta un nuevo valor v en el índice i del ListArr.
 void print(); //Imprime por pantalla todos los valores almacenados en el ListArr.
 bool find(int v); //Busca en el ListArr si el valor v se encuentra almacenado.
 vector<NodeResumen *> createNodeR(NodeArray *head);
 int totalNodes(NodeArray *head);
 NodeResumen* crearArbol(vector <NodeResumen*> n, vector <NodeResumen*>::iterator inicio, vector <NodeResumen*>::iterator final);
};