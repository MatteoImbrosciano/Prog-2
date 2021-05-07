#ifndef CLASSE_H_INCLUDED
#define CLASSE_H_INCLUDED

#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

template<class T>
class Nodo
{
    T value;
    Nodo<T> * next;
public:

    Nodo(T _value, Nodo<T> * _next): value(_value),next(_next){}
    Nodo(T _value): Nodo(_value, NULL){}
    Nodo(): Nodo(0,NULL){}

    Nodo<T> * getNext() { return this->next;}
    void setNext(Nodo<T> * next) { this->next = next;}
    T getValue() { return this->value;}
    void setValue(T value) { this->value = value;}

    string toString()
    {
        stringstream stream;
        stream<<"Nodo value =  "<<value<<" ,  next =  "<<next<<endl;
        return stream.str();
    }

};

#endif // CLASSE_H_INCLUDED
