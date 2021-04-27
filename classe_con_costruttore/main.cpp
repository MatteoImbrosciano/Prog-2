#include <iostream>

using namespace std;

class A
{
    int secondo;
    int const terzo = 10; // o lo inizializzo cosi o deve creare il costruttore per forza

    public:
        int primo;
        void printAll() const
        {
            cout<<"Dati membro:\n";
            cout<<"primo:\t"<<primo<<endl;
            cout<<"secondo: "<<secondo<<endl;
            cout<<"terzo:\t"<<terzo<<endl;
            cout<<endl;
        }
        A(){}
        A(int,int);
        A(int,int,int);

        void setDataMember(int,int);
};

void A::setDataMember(int attr,int val)
{
    switch(attr)
    {
        case 1:
            primo = val; break;
        case 2:
            secondo = val; break;
        /*
        case 3:
            terzo = val; break;// non puo essere eseguita perche "terzo" e' costante
        */
    }
}

A::A(int x,int y):primo(x),secondo(x+y),terzo(x+y+1){}

A::A(int x,int y,int z):primo(x),secondo(y),terzo(z){}

int main()
{
    A a;

    //PROVIAMO A MODIFICARE I VALORI
    // MA POSSO MODIFICARE ISTANTANEAMENTE SOLO I DATI PUBBLICI
    a.primo = 100;
    a.printAll();

    a.setDataMember(2,20);
    a.printAll();
    cout<<"--------------------------------------\n";

    A b{10,5};
    b.printAll();
    cout<<"--------------------------------------\n";

    // A c(); ERRORE!!

    // se esiste un costruttore prova a fare matching
    // altrimenti tenta di fare la unif. initializzation
    A c{101,102,103};
    c.printAll();

    cout<<"--------------------------------------\n";
    A a2{1,2,3};
    a.printAll();

    // PUNTATORE
    cout<<"PUNTATORE\n";
    A* ptA = &a2;
    ptA->printAll();
    // RIFERIMENTO
    cout<<"RIFERIMENTO\n";
    A& rA = a2;
    rA.setDataMember(1,100);
    rA.printAll();

    const A& cRofA = a2;
//    cRofA.setDataMember(1,0); ERRORE!
    cRofA.printAll();

    cout<<"\n--------------------------------------\n";
    // ALLOCAZIONE
    A* ptrA = new A(10,20,30);
    ptrA->printAll();
    delete ptrA;

    cout<<endl<<endl;

    A arrA[2];
    for(int i=0; i<2; i++)
    {
        cout<<"arrA["<<i<<"]:  ";
        arrA[i].printAll();
        cout<<endl;
    }

    // array con costruttore specifico per ciascun elemento

    A arrA_2[2] = { A(3,3,3) , A(9,9) };
    for(int i=0; i<2; i++)
    {
        cout<<"arrA_2["<<i<<"]:  ";
        arrA_2[i].printAll();
        cout<<endl;
    }
    cout<<"\n--------------------------------------\n";
    // ALLOCAZIONE DINAMICA

    A* arrA_3 = new A[2]; // costr. di default
    arrA_3[0].printAll();
    delete[] arrA_3 ;
    cout<<"\n--------------------------------------\n";

    A* arrA_4 = new A[2]{A(2,2,2), A(10,10)};
    (arrA_4+1)->printAll(); // artmetica dei puntatori
    delete[] arrA_4;

    return 0;
}
