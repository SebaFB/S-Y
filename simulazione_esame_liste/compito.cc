#include <iostream>
using namespace std;


#include "compito.h"
/**
 * @brief aggiunge alla lista in mano al giocatore una carta
 * 
 * @param l lista "Mano" del giocatore
 * @param v valore carta
 * @param s seme carta
 */
void pesca(lista& l, int v, char s)
{
    //creo la carta:
    tipo_inf carta;
    carta.seme = s;
    carta.valore = v;
    //creo il nodo:
    elem* node = new elem;
    node = new_elem(carta);
    //inserimento in testa:
    l = insert_elem(l, node);
    //print_mano(l);
}
/*
void print_mano(lista l)
{
    elem* tmp = l;
    cout<<"-----------"<<endl;
    while(tmp!=NULL)
    {
        cout<<"valore: "<<tmp->inf.valore<< " seme: "<<tmp->inf.seme<<endl;
        tmp = tmp->pun;
    }
}
*/
/**
 * @author {Youssef Chiesi, Matricola}
 * 
 * @param mano1 è la mano del giocatore 1
 * @param mano2 è la mano del giocatore 2
 * stampa le due liste di carte a coppie nella stessa posizione e, per ogni coppia se la carta è minore, maggiore o uguale
 */
void stampa(lista mano1, lista mano2)
{
    elem* tmp1 = mano1;
    elem* tmp2 = mano2;
    int a;
    while(tmp1!=NULL && tmp2!=NULL)
    {
        a = compare(tmp1->inf,tmp2->inf);
        if(a < 0)
        {
            cout<<"valore: "<<tmp1->inf.valore<< " seme: "<<tmp1->inf.seme<< " MINORE di " <<"valore: "<<tmp2->inf.valore<< " seme: "<<tmp2->inf.seme<<endl;
        }
        else if(a == 0)
        {
            cout<<"valore: "<<tmp1->inf.valore<< " seme: "<<tmp1->inf.seme<< " UGUALE di " <<"valore: "<<tmp2->inf.valore<< " seme: "<<tmp2->inf.seme<<endl;
        }
        else //a == 1   
        {
            cout<<"valore: "<<tmp1->inf.valore<< " seme: "<<tmp1->inf.seme<< " MAGGIORE di " <<"valore: "<<tmp2->inf.valore<< " seme: "<<tmp2->inf.seme<<endl;
        }
        tmp1 = tmp1->pun;
        tmp2 = tmp2->pun;
    }
}