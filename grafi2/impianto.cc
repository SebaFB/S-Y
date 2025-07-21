#include <iostream>
using namespace std;

#include "impianto.h"

int compare(tipo_inf a,tipo_inf b)
{
    if(a.tipo == b.tipo)
    {
        if(a.stato == b.stato)
        {
            return 0;
        }
    }
    return 1;
}
void print(tipo_inf a)
{
    cout<< a.id << " " << a.tipo << " "<< a.stato <<endl;
}

void copy(tipo_inf* a, tipo_inf b)
{
    a->id = b.id;
    a->stato = b.stato;
    a->tipo = b.tipo;
    //cout<<"Copia effettuata: "<< a->id << " "<< a->tipo << " "<< a->stato<<endl;
    cout<<"Copia effettuata: ";
    print(*a);
}

/**
 * @author {Youssef Chiesi, Matricola}
 * 
 * @param a tipo inf
 * @return 0 se è presente/funzionamento regolare, 1 altrimenti.
 */
int sanity_check(tipo_inf a)
{
    if(a.stato == 'P' || a.stato == 'R')
    {
        return 0;
    }
    return 1;
}