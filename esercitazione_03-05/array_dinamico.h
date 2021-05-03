#include "array_dinamico.cpp"
using namespace std;

arrayDinamico::arrayDinamico(int n)
{
    if(n <= 0)
    {
        cout<<"ERRORE: size deve essere maggiore di '"<<endl;
        exit(1);
    }
    maxSize = n + BUF_SIZE;
    size = n;

    ptr = new double[maxSize];
    for(int i=0;i<n;i++)
    {
        ptr[i] = 0.0;
    }
}
 arrayDinamico::arrayDinamico(const arrayDinamico &a)
{
    maxSize = a.maxSize;
    size = a.size;
    ptr = new double[maxSize];
    for(int i=0;i<maxSize;i++)
        ptr[i] = a.ptr[i];
}
 arrayDinamico::arrayDinamico(const double a[], int n)
{
    maxSize = n + maxSize;
    size = n;
    ptr = new double[maxSize];
    for(int i=0;i<n;i++)
        ptr[i] = a[i];
}
arrayDinamico::~arrayDinamico()
{
    delete [] ptr;
}

void arrayDinamico::insert(double elem)
{
    /*
    [ 3 2 23 11 55 - - - - - ]
      0 1 2  3  4
     size = 5  maxSize = 10
    */
    if(size == maxSize)
    {
        // vediamo se dobbiamo o no aumentare lo spazio
        cout<< endl<<"Estendo l'array...\n";
        maxSize += BUF_SIZE + 1;

        double *tmp = new double[maxSize]; // ottengo l'array aumentato

        for(int i=0;i<size;i++)
            tmp[i] = ptr[i];

        double *toDelete = ptr;
        ptr = tmp; // conterra' l'indirizzo del nuovo array

        delete [] toDelete; // sto liberando l'area di memoria puntata da questo puntatore (contiene l'area puntata da ptr)

    }
    //inserimento
    ptr[size] = elem;
    size += 1;
}

void arrayDinamico::remove(int idx)
{
    if(idx >= size || idx < 0)
    {
        cout<<"Indice errato!!!"<<endl;
        exit(-1);
    }
    // sovrascrivo l'elemento di indice idx con quelli successivi
    for(int i= idx; i<size-1; i++)
        ptr[i] = ptr[i+1];

    ptr[size] = 0.0;
    size -= 1;
/*
    [ 2 . 3 , 44 , 2 , 4 , - - - - -]
    [ 2 , 3 , 2 , 4 , - - - - - ]
    [ 2 , - - - - -  - - - -}
*/
    // SE SPRECO SPAZIO RIDUCO L'ARRAY
    if(size <= maxSize - 2* BUF_SIZE)
    {

        cout<<"\nSE SPRECO SPAZIO RIDUCO L'ARRAY\n";
        maxSize -= BUF_SIZE;

        double *tmp = new double[size];
        for(int i=0;i<size;i++)
            tmp[i] = ptr[i];

        double *toDelete = ptr;
        ptr = tmp;
        delete [] toDelete;
        cout<<"Nuova dimensione dello array...\n";
    }
}
double arrayDinamico::operator[](int idx) const
{
    // exception <- logic_error <- out_of_range

    if(idx <0 || idx >= size)
    {
        throw out_of_range("ArrayDinamico::operator[]");
        // throw -10;
        //cout<<"INDICE ERRATO!\n";
    }
    return ptr[idx];
}
double & arrayDinamico::operator[](int idx)
{
    if(idx <0 || idx >= size)
    {
        throw out_of_range("ArrayDinamico::operator[]");
        // throw -10;
        //cout<<"INDICE ERRATO!\n";
    }
    return ptr[idx];
}

ostream& operator<<(ostream& out,const arrayDinamico& a)
{
    // VOGLIO STAMPARE OGNI VOLTA [ 3 , 3 , 2 , 33 , - - - - -]
    out<<"[";
    for(int i=0;i < a.maxSize;i++)
    {
        if(i < a.size)
            out<< a.ptr[i]<<"  ";
        else
            out<< " - ";
    }
    out<<"]";
    return out;
}
