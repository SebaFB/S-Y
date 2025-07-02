/**
 * @file compito.cc
 * @author {Sebastiano Toni} ({349608@studenti.unimore.it})
 * @author {Sebastiano Toni, Matricola: 199678}
 * @version 0.1
 * @date 30-06-PMPMPMPM
 * @copyright Copyright (c) 2025
 */

/*******************************/
/* DEFINIZIONE MODULO "compito" */
/*******************************/

#include <iostream>
#include <cstring>

using namespace std; 

#include "liste.h"

/**
 * @author {Sebastiano Toni, Matricola: 199678}
 * @brief Funzione per aggiungere (far pescare) una carta al giocatore
 * @param l = lista
 * @param v = int
 * @param s = char
 */
void pesca(lista& l, int v, char s){
    elem* e = NULL;
    tipo_inf inf; 
    inf.seme = s;
    inf.valore = v; 
    e = new_elem(inf); 
    l = insert_elem(l,e); 
}

/**
 * @author {Sebastiano Toni, Matricola: 199678}
 * @brief Funzione che confronta le mani dei due giocatori 
 * @param l1 
 * @param l2 
 */
void stampa(lista l1, lista l2){
    int ris; 
    while(l1!=NULL && l2!=NULL){
        ris = compare(l1->inf,l2->inf);
        if(ris<0)
            cout << l1->inf.valore << " " << l1->inf.seme << " minore di " << l2->inf.valore << " " << l2->inf.seme << endl;
        else if(ris>0)
            cout << l1->inf.valore << " " << l1->inf.seme << " maggiore di " << l2->inf.valore << " " << l2->inf.seme << endl;
        else
            cout << l1->inf.valore << " " << l1->inf.seme << " è uguale a " << l2->inf.valore << " " << l2->inf.seme << endl; 
        
        l1 = tail(l1); 
        l2 = tail(l2); 
    }
}

/**
 * @author {Sebastiano Toni, Matricola: 199678}
 * Funzione per trovare i tris nella mano
 * @param mano 
 * @return int* 
 */
int* tris(lista mano){
    int* v = new int[12]; 
    int i; 
    lista l = mano; 
    
    for(i=0; i<12; i++){
        v[i] = 0; 
    }

    while(l!=NULL){
        v[l->inf.valore - 1] = v[l->inf.valore - 1] + 1;
        l = tail(l); 
    }

    for(i=0; i<12; i++){
        v[i] = v[i] / 3;
    }

    return v;
}

/**
 * @author {Sebastiano Toni, Matricola: 199678}
 * @brief Funzione per calcolare il punteggio di ogni mano, in base a quanti tris si hanno
 * @param carte 
 * @return int 
 */
int cala(lista& carte)
{
    int* terz = tris(carte);
    bool esiste = false; // esiste un tris;
    int a = -1;
    while( a < 12 && esiste == false)
    {
        a++;
        if(terz[a]>0)
        {
            esiste = true;
        }
    }
    if(esiste == false)
    {
        return 0;
    }
    else
    {
       elem* tmp = carte;
       int contatore = 0;
       elem* pross = NULL;
       while(tmp!=NULL && contatore < 3)
       {
            if(tmp->inf.valore == (a+1))
            {
                cout <<tmp->inf.valore<< " "<<tmp->inf.seme << " ";
                pross = tmp->pun;
                carte = delete_elem(carte, tmp);
                contatore = contatore+1;
                tmp = pross;
            }
            else
            {
                tmp = tmp->pun;
            }
       }
       int punteggio = (a+1)*3; //a+1 valore
       delete(terz);
       return punteggio;
    }
}

/**
 * @author {Sebastiano Toni, Matricola: 199678}
 * Funzione per pescare le carte in modo ordinato
 * @param l 
 * @param v 
 * @param s 
 */
void ord_pesca(lista l, int v, int s){
    elem* e = NULL;
    tipo_inf inf; 
    inf.seme = s;
    inf.valore = v; 
    e = new_elem(inf);

    while(l!=NULL){
        if(l->pun == NULL){
            l->pun = e; 
            e->prev = l; 
        }
    }
}