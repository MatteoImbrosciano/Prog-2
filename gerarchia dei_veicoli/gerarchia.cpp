#include "gerarchia.h"

void gara::bubblesort()
{
    for(int i=0;i<numeroIscritti;i++)
    {
        for(int j=i+1;j<numeroIscritti;j++)
        {
            if(*veicoli[i] < *veicoli[j])
            {
                veicolo *tmp = veicoli[j];
                veicoli[i] = veicoli[j];
                veicoli[j] = tmp;
            }
        }
    }
}

void gara::aggiungiPartecipante( veicolo& v)
{
    // mi serve sapere il numero dei partecipanti
    // A. aggiungo un parametro a questo metodo
    // B. utilizzo una costanteù
    // C. aggiungo un attributoalla classe


    veicoli[numeroIscritti++] = &v;
}

void gara::controlla(int t)
{
    int massimo_temporaneo = veicoli[0]->getVelocitaInstantanea();
    //int massimo_temporaneo = -1;
    int indice_max = 0; // del veicolo piu veloce

    // devo scorrere l'array
    for(int i=1/*perche' l'elemento in pos 0 e' stato valutat0*/ ;i < numeroIscritti; i++)
    {
        // estrarre la velocità di ogni veicolo
        // e verificare chie e' piu avanti
        // RICERCA se vogliamo trovare solo il massimo
        // ORDINAMENTO se vogliamo la classifica completa

        if(veicoli[i]->getVelocitaInstantanea() > massimo_temporaneo)
        {
            massimo_temporaneo = veicoli[i]->getVelocitaInstantanea();
            indice_max = i;
        }
    }
    cout<<"Il veicolo piu' veloce e' "<<*veicoli[indice_max]<<"  ha velocita':   "
        <<massimo_temporaneo<<endl;

}
void gara::partenza()
{
    srand(42);
    for(int i=0;i<durata;i++)
    {
        for(int j=0; j<numeroIscritti;j++)
        {
            int scelta = rand()%2 ;
            if(scelta == 1)
                veicoli[j]->accellera();
            else
                veicoli[j]->decellera();

        }
        this->controlla(i);
    }
    this->printClassifica();
}

void gara::printClassifica()
{
    cout<<"\nCLASSIFICA:\n"<<endl;
 /*   for(int i=0;i<numeroIscritti;i++)
    {
        cout<<"#"<<i<<"  "<<*veicoli[i]->bubblesort()<<endl;
    }
 */
}

