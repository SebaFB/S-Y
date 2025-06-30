#include <iostream>

using namespace std;

#include "fun_liste.h"


void stampa_lista(lista l)
{
    elem* tmp = l;
    while(tmp!=nullptr)
    {
        cout<< "valore: "<< tmp->inf <<endl;
        tmp = tmp->pun;
    }
}

lista crea_lista(int n)
{
    lista l = nullptr;
    while(n > 0)
    {
        elem* e = new elem;
        cout<<endl<<"inserire valore"<<endl;
        cin>> e->inf;
        l = insert_elem(l,e);
        n = n-1;
    }
    return l;
}

lista cancella(lista l, char* c)
{
    elem* e = new elem;
    e = search(l, c);
    /*while(e!=nullptr)
    {
        cout<<"trovato uno"<<endl;
        //"e" ha come char il char che voglio eliminare quindi:
        elem* tmp = e->pun; //inizio a cercare da quello dopo per il prossimo giro
        l = delete_elem(l,e);
        elem* e; //ogni volta in delete elem viene usato delete su e.
        e = search(tmp,c);
    }*/
    elem* tmp = l;
    while(tmp!=nullptr){
        //"e" ha come char il char che voglio eliminare quindi:
        //cout<<"trovato uno"<<endl;
        //elem* tmp = e->pun; //inizio a cercare da quello dopo per il prossimo giro
        l = delete_elem(l,e);
        elem* e; //ogni volta in delete elem viene usato delete su e.
        tmp = tmp->pun;
        e = search(tmp,c);
    }
    return l;
}

