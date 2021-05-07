#ifndef GERARCHIA_H_INCLUDED
#define GERARCHIA_H_INCLUDED
#include <iostream>
#include <string.h>
#include <sstream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
class veicolo
{
protected:

    int numRuote, velocitaMax;
    string marca, tipoCarburante, motorizzazione;
    double prezzo;
    int velocitaInstantanea;
public:
    veicolo(){}
    veicolo(int _numRuote, int _velocitaMax,int _velocitaInstantanea, double _prezzo, string _marca, string _tipoCarburante, string _motorizzazione)
    {
        this->velocitaInstantanea = 0;
        this->numRuote = _numRuote;
        this->marca = _marca;
        this->velocitaMax = _velocitaMax;
        this->tipoCarburante = _tipoCarburante;
        this->motorizzazione = _motorizzazione;
        this->prezzo = _prezzo;
    }
    double getPrezzo() const {return prezzo;}
    void setPrezzo(double _prezzo){prezzo = _prezzo;}

    int getNumRuote() const {return prezzo;}
    void setNumRuote(int _numRuote){numRuote = _numRuote;}

    int getVelocitaInstantanea() const {return velocitaInstantanea;}

    int getVelocitaMax() const {return prezzo;}
    void setVelocitaMax(int _velocitaMax){velocitaMax = _velocitaMax;}

    string getMarca() const {return marca;}
    void setMarca(string _marca){marca = _marca;}

    string getTipoCarburante() const {return tipoCarburante;}
    void setTipoCarburante(string _tipoCarburante){tipoCarburante = _tipoCarburante;}

    string getMotorizzazione() const {return motorizzazione;}
    void setPrezzo(string _motorizzazione){motorizzazione = _motorizzazione;}


    void accellera()
    {
        if(velocitaInstantanea < velocitaMax)
            velocitaInstantanea++;
    }
    void decellera()
    {
        if(velocitaInstantanea > 0)
            velocitaInstantanea--;
    }
    virtual string toString() const = 0;

    friend ostream& operator<<(ostream& out,const veicolo& v)
    {
        out << v.toString();
        return out;
    }

    // l'operatore = non ha bisogno di friend
     void operator=(const veicolo& v)
     {
         this->numRuote = v.numRuote;
         this->velocitaMax = v.velocitaMax;
         this->velocitaInstantanea = v.velocitaInstantanea;
         this->marca = v.marca;
         this->prezzo = v.prezzo;
         this->motorizzazione = v.motorizzazione;
         this->tipoCarburante = v.tipoCarburante;
     }

     bool operator<(const veicolo& v)
     {
         this->velocitaInstantanea < v.velocitaInstantanea;
     }
     bool operator==(const veicolo& v)
     {
         this->velocitaInstantanea == v.velocitaInstantanea;
     }
     bool operator>(const veicolo& v)
     {
         this->velocitaInstantanea > v.velocitaInstantanea;
     }

     void sorpassa()  {}

};
class moto : public veicolo
{

public:
    moto(){}
    moto(int _velocitaMax, double _prezzo ,string _marca, string _motorizzazione):
        veicolo(2,_velocitaMax,0,_prezzo, _marca,"Benzina",_motorizzazione){}

    std::string toString() const
    {
        stringstream stream;
        stream <<"Sono una moto di marca "<<marca<<" ,  "<<motorizzazione
               <<" , "<<tipoCarburante<<"  La mia velocita e' di  "<<velocitaInstantanea<<" km/h"<<endl;
        return stream.str();
    }
    friend ostream& operator<<(ostream& out,const moto& m)
    {
        out << m.toString();
        return out;
    }
};
class automobile : public veicolo
{
public:

    automobile(){}
    automobile(int _velocitaMax , double _prezzo ,string _marca,string _tipoCarburante, string _motorizzazione):
        veicolo(4,_velocitaMax, 0 ,_prezzo, _marca,_tipoCarburante,_motorizzazione){}

    string toString() const
    {
        stringstream stream;
        stream <<"Sono una automobile di marca "<<marca<<" ,  "<<motorizzazione
               <<" , "<<tipoCarburante<<"  La mia velocita e' di  "<<velocitaInstantanea<<" km/h"<<endl;
        return stream.str();
    }
};

class gara
{
    int durata, numPartecipanti;
    int numeroIscritti; // variabile di istanza
    void controlla(int t);
    veicolo ** veicoli;

public:

    gara(){}
    gara(int _durata, int _numPartecipanti) : durata(_durata),numPartecipanti(_numPartecipanti)
    {
        veicoli = new veicolo*[numPartecipanti];
        numeroIscritti = 0;
    }
    ~gara()
    {
        delete [] veicoli;
    }
    void partenza();
    void printClassifica();
    void aggiungiPartecipante(veicolo& v); //posso modificare il veicolo
    void bubblesort();
};


#endif // GERARCHIA_H_INCLUDED
