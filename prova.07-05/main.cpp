#include <iostream>
#include "nodo.h"
#include "nodo.cpp"
using namespace std;

int main()
{
    ListaSemplice lista;
    lista.inserisci(20); //inserisci in testa
    lista.inserisci(10);
    lista.inserisci(5);

    cout<<lista<<endl;

    Nodo* p;
    int x;
    cout<<"Inserisci un numero da inserire dopo il 10:\t";
    cin>>x;

    p = lista.ricerca(10);

    if( p != nullptr)
        lista.inserisci(p , p->succ , x);
    cout<<lista<<endl;

    cout<<"inserisci tre elementi in coda\n";
    for(int i=0;i<3;i++)
    {
        cin>>x;
        lista.inserisci_in_coda(x);
        cout<<lista;
    }

    cout<<"inserisci un elemento da eliminare\n";
    cin>>x;
    lista.rimuovi(x);
    cout<<lista;


}
