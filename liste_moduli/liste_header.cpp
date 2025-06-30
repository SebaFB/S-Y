#include <iostream>
#include <cstring>
using namespace std;

#include "liste_header.h"

lista tail(lista l)
{
    if(l->pun == nullptr) //la lista ha un solo elemento
    {
        return nullptr;
    }
    return l->pun;
}

lista insert_elem(lista l, elem* e) //inserimento in testa.
{
    if(l == nullptr) //lista vuota
    {
        e->prev = nullptr;
        e->pun = nullptr;
        return e;
    }

    l->prev = e;
    e->pun = l;
    e->prev = nullptr;
    return e;
}

lista delete_elem(lista l, elem* e)
{
    cout<<endl<<"SONO DENTRO A DELETE ELEM"<<endl;
    if(strcmp(l->inf,e->inf)==true) //è il primo elemento.
    {
        cout<<endl<<"ERA IL PRIMO ELEMENTO"<<endl;
        l = e->pun;
        l->prev = nullptr;
        delete(e);
        return l;
    }
    elem* tmp = l;
    while(tmp != nullptr && strcmp(tmp->inf,e->inf)!=true)
    {
        cout<<"sto facendo dei giri credo"<<endl;
        tmp = tmp->pun;
    }

    if(tmp == nullptr)
    {
        //cout<<"l'elemento non era presente";
        return l;
    }
    //altrimenti tmp == e:
    elem* prec = tmp->prev;
    elem* pross = tmp->pun;
    prec->pun = pross;
    pross->prev = prec;
    cout<<endl<<"ho fatto qualcosa in delete elem"<<endl;
    delete(e);
    return l;
}

