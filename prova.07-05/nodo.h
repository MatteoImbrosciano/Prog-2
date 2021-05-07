#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <iostream>

using namespace std;

class Nodo
{
public:
    int valore;
    Nodo* succ;

};

class ListaSemplice
{
    Nodo* testa;

public:
     ListaSemplice(){testa = nullptr;} // una lista che ha null come testa sara una lista vuota
     ~ListaSemplice();
     Nodo* getTesta() {return this->testa;}

     //inserisci in testa:
     void inserisci(int value); //_in_testa
     void inserisci(Nodo* precedente, Nodo* seguente, int n); // _in_pos
     void inserisci_in_coda(int value);

     Nodo* ricerca(int value);
     void rimuovi(int value);

     friend
     ostream& operator<<(ostream& out, const ListaSemplice& l);

};

#endif // NODO_H_INCLUDED
