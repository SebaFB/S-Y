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