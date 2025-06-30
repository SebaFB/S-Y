/**
 * @file tipo.cc
 * @author {Sebastiano Toni} ({349608@studenti.unimore.it})
 * @author {Sebastiano Toni, Matricola: 199678}
 * @version 0.1
 * @date 30-06-PMPMPMPM
 * @copyright Copyright (c) 2025
 */

/*******************************/
/* DEFINIZIONE MODULO "tipo" */
/*******************************/

#include <iostream>
#include <cstring>

using namespace std; 

#include "tipo.h"

int compare(tipo_inf s1, tipo_inf s2){//c q f p
    if(s1.valore > s2.valore)
        return -1; 
    if(s1.valore == s2.valore)
        return 0;
    if(s1.valore == s2.valore && s1.seme != s2.seme){
        if(s1.sema == 'C' && s2.seme == 'Q')
            return -1; 
        else if(s1.seme == 'Q' && s2.seme == 'F')
            return -1; 
        else if(s1.seme == 'F' && s2.seme == 'P')
            return -1; 
        else if(s1.seme == 'C' && s2.seme == 'F')
            return -1; 
        else if(s1.seme == 'C' && s2.seme == 'P')
            return -1; 
        else if(s1.seme == 'Q' && s2.seme == 'P')
            return -1;
        else
            return 1;
    }
}

void copy(tipo_inf& dest, tipo_inf source){
    dest = malloc(sizeof(source)); 
    strcpy(dest,source);
}

void print(tipo_inf inf){
    cout << inf; 
}