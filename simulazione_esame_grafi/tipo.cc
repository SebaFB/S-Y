#include <iostream>

using namespace std;

#include "tipo.h"
#include <string.h>

int compare(tipo_inf a,tipo_inf b)
{

    if(a.tipo==b.tipo)
    {
        if(strcmp(a.descrizione , b.descrizione)==0)
        {
            return 0;
        }
    }
    return 1;
}
void copy(tipo_inf& a,tipo_inf b)
{
    a.tipo = b.tipo;
    strcpy(a.descrizione,b.descrizione);
    cout<<a.descrizione <<"  "<< a.tipo<<endl;
}

void print(tipo_inf a)
{
    cout<<"Tipo: "<< a.tipo << " Descr: "<< a.descrizione<<endl;
}
