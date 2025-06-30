#include <iostream>
#include <cstring>

using namespace std;

//#include "liste_tipo_header.h"
#include "fun_liste.h"

char* head(lista l)
{
    return l->inf;
}

elem* new_elem(char* c)
{
    elem* e = new elem;
    strcpy(e->inf,c);
    e->pun = nullptr;
    e->prev = nullptr;
    return e;
}


elem* search(lista l, char* c)
{
    stampa_lista(l);
    cout<<endl<<endl<<"--------------------"<<endl;
    elem* tmp = l;
    while(tmp!=nullptr)
    {
        if(strcmp(tmp->inf,c) == true)
        {
            return tmp;
        }
        tmp = tmp->pun;
    }

    return nullptr;
}