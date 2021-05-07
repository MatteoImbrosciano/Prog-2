#include <iostream>
#include "classe.h"
#include "classe.cpp"
#include "lista.h"
using namespace std;

int main()
{
    Nodo<int> n1(10);
    Nodo<int> n2(10); // &n1);
    Nodo<int> n3;// se metto le '()' mi dara' errore nella riga 21

    cout<<" &n1:\t"<<&n1<<endl;
    cout<<" &n2:\t"<<&n2<<endl;
    cout<<" &n3:\t"<<&n3<<endl;
    cout<<" n1.value():\t"<<n1.getValue()<<endl;
    cout<<" n1.next():\t"<<n1.getNext()<<endl;

 //   n2.setValue(100);
 //   n3.setNext(&n1);

    cout<<"\nn2.toString():\t"<<n2.toString()<<endl;

    cout<<"----------------------------------------------\n";

    Lista<int> lista;

    lista.insert(&n1);
    lista.insert(&n2);
    lista.insert(&n3);

    lista.insert(14);

    cout<<lista<<endl;
    return 0;
}
