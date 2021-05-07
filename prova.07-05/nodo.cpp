#include "nodo.h"

ListaSemplice::~ListaSemplice()
{
    Nodo* iter = this->testa;

    while(iter != nullptr)
    {
        Nodo* temp = iter->succ;
        delete iter; // stiamo eliminando un oggetto puntato da iter
        iter = temp;
    }
}

ostream& operator<<(ostream& out, const ListaSemplice& l)
{
    Nodo* iter = l.testa; // nodo di appoggio per iterare
    out<<" iter->value  \n";
    while(iter != nullptr)
    {
        out<<"  "<<iter->valore<<" --> ";
        iter = iter->succ;
    }
    out<<" NULL"<<endl;

    return out;
}
void ListaSemplice::inserisci(int value) //_in_testa
{
    Nodo* nuovo = new Nodo;
    nuovo->valore = value;
    nuovo->succ = this->testa; // conterra l'indirizzo della testa
    this->testa = nuovo; //aggiorno la testa

}

void ListaSemplice::inserisci(Nodo* precedente, Nodo* seguente, int value) // _in_pos
{
    Nodo* nuovo =new Nodo;

    nuovo->valore = value;
    nuovo->succ = seguente;
    precedente->succ = nuovo;
}
void ListaSemplice::inserisci_in_coda(int value)
{
    Nodo* nuovo = new Nodo;
    Nodo* iter = this->testa;

    nuovo->valore = value;

    if(this->testa == nullptr)
    {
        nuovo->succ = nullptr;
        this->testa = nuovo;
    }
    else
    {
        while(iter->succ != nullptr)
        {
            iter= iter->succ;
        }
        iter->succ = nuovo;
        nuovo->succ = nullptr;
    }
}
Nodo* ListaSemplice::ricerca(int value)
{
    Nodo* p;
    for(p = this->testa; p != nullptr ; p = p->succ)
    {
        if(p->valore == value)
            return p;
    }

    return nullptr; // se arriviamo qui p stava puntando a NULL
}

void ListaSemplice::rimuovi(int value)
{
    Nodo* prec;
    Nodo* current;

    if(this->testa == nullptr)
        cout<<" Lista vuota...\n";
    else if(this->testa->valore == value)
        {
            prec = this->testa;
            this->testa = this->testa->succ;
            delete prec;
    }
    else
    {
        prec = this->testa;
        current = this->testa->succ;
        while((current != nullptr) && (current->valore != value))
        {
            // spostiamo i puntatori in avanti
            prec = prec->succ;
            current = current->succ;
        }
        if(current != nullptr)
        {
            prec->succ = current->succ;
            delete current;
        }
        else
        {
            cout<<" elemento non presente nella lista\n";
        }
    }


}
