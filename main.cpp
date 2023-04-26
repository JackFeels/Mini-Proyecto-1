#include "ListArray.h"

int main(){
    int capacidad; // tamaño arreglo b
    std:: cout << "Ingrese el tamaño del arreglo: ";
    std:: cin >> capacidad;
    ListArray l_a(capacidad);
    l_a.insert_left(1);
    l_a.insert_left(2);
    l_a.insert_left(15);
    l_a.insert_left(13);
    l_a.insert_left(69);
    l_a.insert_left(11);
    l_a.insert_left(13);
    l_a.insert_right(8);
    l_a.insert_right(444);
    l_a.find(15);
    l_a.find(100);

    cout << "size: " << l_a.size() << endl;
    l_a.print();

    return 0;
}