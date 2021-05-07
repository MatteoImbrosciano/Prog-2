#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "classe.h"

template<class T>
class Lista
{
    Nodo<T> * head;
    int length;
public:

    Lista(Nodo<T> * head) : head(head), length(0){}
    Lista(): Lista(NULL) {}

    void insert(Nodo<T> * n)
    {
        // INIZIALMENTE VOGLIO INSERIRE IN CODA
        if(head == NULL)
        {
            head = n;
            length++; //LA LISTA AVRA' UN NODO IN PIU
            return;
        }
        Nodo<T> * current = head; // USO IL PUNTATORE CURRENT PER SCORRERE LA LISTA

        while( current->getNext() != NULL)
        {
            current = current->getNext();
        }
        // quando finisce il ciclo while sono nell'ultimo nodo
        current->setNext(n);
        length++;
    }

    int getLenght() { return this->length;}
    Nodo<T> * getHead() { return this->head;}
    void setLenght(int length) { this->length = length;}
    void setHead() { this->head = head;}

    friend
    ostream& operator<<(ostream& out, const Lista& l)
    {
        out<<" Lista head =  "<<l.head<<endl<<endl;
        Nodo<T> * current = l.head;

        while(current != NULL)
        {
            out<<"\t"<<current->toString()<<endl;
            current = current->getNext();
        }
        return out;
    }

    void insert(T value)
    {
        Nodo<T> * temp = new Nodo<T>(value);
        this->insert(temp);
    }
};


#endif // LISTA_H_INCLUDED
