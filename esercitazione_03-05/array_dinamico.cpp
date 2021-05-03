#ifndef ARRAY_DINAMICO_CPP_INCLUDED
#define ARRAY_DINAMICO_CPP_INCLUDED

class arrayDinamico
{
private:
    double *ptr;
    int size; // num elementi attualmente presenti
    int maxSize; // dim fisica >= size

public:
    arrayDinamico(){}
    explicit arrayDinamico(int n = 8 );
    arrayDinamico(const arrayDinamico &a );
    arrayDinamico(const double a[], int n );

    ~arrayDinamico();

    int getSize() const {return size;}
    int getMaxSize() const {return maxSize;}

    void insert(double elem);
    void remove(int idx); // elimina ptr[idx]

    // uno per leggere
    double operator[](int idx) const; // a[i] solo lettura
    // uno per scrivere
    double & operator[](int idx); // a[i] = x

    friend
    std::ostream& operator<<(std::ostream& out, const arrayDinamico &a);


};

#endif // ARRAY_DINAMICO_CPP_INCLUDED
