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

int compare(tipo_inf a,tipo_inf b){
    if(a.valore < b.valore)
        return -1;
    else if((a.valore == b.valore) && (a.seme != b.seme)){
        if(b.seme == 'C')
            return -1;
        if((b.seme == 'Q' && a.seme=='F' )|| (b.seme == 'Q' && a.seme=='P'))
            return -1;
        if(b.seme == 'F' && a.seme == 'P')
            return -1;
    }
    if((a.valore == b.valore)&&(a.seme == b.seme))
        return 0;
    return 1;
}


void copy(tipo_inf& dest, tipo_inf source){
    dest.seme = source.seme;
    dest.valore = source.valore;
}

//void print(tipo_inf inf){}