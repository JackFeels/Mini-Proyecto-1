#include "ListArr.h"

int main(){
    int capacidad; // tamaño arreglo b
    std:: cout << "Ingrese el tamaño del arreglo: ";
    std:: cin >> capacidad;
    ListArr l_a(capacidad);
    l_a.insert_left(1);
    l_a.insert_left(2);
    l_a.insert_left(15);
    l_a.insert_left(13);

    cout << "size: " << l_a.size() << endl;
    l_a.print();

    return 0;
}