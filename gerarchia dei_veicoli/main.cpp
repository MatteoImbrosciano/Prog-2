#include "gerarchia.cpp"
#include "gerarchia.h"
using namespace std;
// SI SIMULI UNA GARA TRA 10 VEICOLI DI TIPO DIVERSO
// RIPORTANDO SORPASSI E CLASSIFICA FINALE

int main()
{
    double* array;
    double array2[10];

    array = new double[10];

    for(int i=0; i< 10; i++)
    {
        cout<<array[i]<<endl;
    }
    cout<<"-----------------------"<<endl;
    for(int i=0; i< 10; i++)
    {
        cout<<array2[i]<<endl;
    }
    cout<<"-----------------------"<<endl;

    moto m1{125, 10000 ,"Ducati", "1000cc"};
    cout << m1<<endl;

    automobile a1{170 , 60000, "Fiat" , "Diesel" , "1300ml" };
    cout<<a1<<endl;

    cout<<"-----------------------"<<endl;

    gara garaa(10, 10);
    garaa.aggiungiPartecipante(m1);
    garaa.aggiungiPartecipante(a1);

    garaa.partenza();
}
