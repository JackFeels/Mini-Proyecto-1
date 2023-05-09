#include "ListArray.h"

int main(){
    int capacidad; // tamaño arreglo b
    std:: cout << "Ingrese el tamaño del arreglo: ";
    std:: cin >> capacidad;
    ListArray l_a(capacidad);
    l_a.insert_right(5);
    l_a.insert_right(7);
    l_a.insert_right(1);
    l_a.insert_right(0);
    l_a.insert_right(-8);
    l_a.insert_right(0);
    l_a.insert_right(10);
    l_a.insert_right(7);
    l_a.insert_right(-1);
    l_a.insert_right(3);
    l_a.insert_right(0);
    l_a.insert_right(0);
    l_a.insert_right(78);
    l_a.insert_right(40);
    l_a.insert_right(6);
    l_a.insert_right(77);
    l_a.insert_right(13);
    l_a.insert_right(0);
    l_a.insert_right(0);
    l_a.insert_right(0);
    l_a.insert_right(71);
    l_a.insert_right(80);
    l_a.insert_right(65);
    l_a.insert_right(96);
    l_a.insert_right(0);
    l_a.insert_right(0);
    l_a.insert_right(71);
    l_a.insert_right(80);
    l_a.insert_right(65);
    l_a.insert_right(96);
    l_a.insert_right(0);
    l_a.insert_right(0);
    l_a.insert_right(71);
    l_a.insert_right(80);

    //cout << "size: " << l_a.size() << endl;
    l_a.print();
    vector <NodeResumen*> resumenNodes = l_a.createNodeR(l_a.head);
    for (int i = 0; i < resumenNodes.size(); i++) {
    if (0 < resumenNodes.size()) {
        cout << resumenNodes[i]->name << endl;
        }
    }
   // NodeResumen* raiz = l_a.crearArbol(resumenNodes, resumenNodes.begin(), resumenNodes.end() );
    //cout << l_a.totalNodes() <<endl;
    return 0;
    
}