#include <iostream>
#include <stdexcept>
#define  BUF_SIZE 5
#include "array_dinamico.cpp"
#include "array_dinamico.h"

int main()
{
    arrayDinamico a1(6);
    cout<<a1<<endl;

    int n = 3;
    double d[n]={1,1 , 2.2 , 3.3};
    for(int i=0;i<n;i++)
        cout<<d[i]<<endl;

    cout<<"--------------------------\n";
    arrayDinamico a2(d,3);
    cout<<a2<<endl;

    cout<<"--------------------------\n";

    arrayDinamico a3(a2);
    a2[1] = 0.0;
    cout<<a2<<endl;
    cout<<a3<<endl;

    try{
        a2[5] = 10;
    }
    catch(exception& err)
    {
        cout<<"ERRORE CATTURATO\n"<<err.what()<<endl;
    }

    cout<<"Inserisco 6 elementi:..\n";
    for(int i=0;i<6;i++)
    {
        cout<<a2;
        a2.insert(i+0.1);
    }
    cout<<a2;

    cout<<"Elimino 4 elementi:..\n";
    for(int i=0;i<4;i++)
    {
        cout<<a2;
        a2.remove(0);
    }
    cout<<a2;

    return 0;
}
