/**
 * @file main.cc
 * @author {Sebastiano Toni} ({349608@studenti.unimore.it})
 * @author {Sebastiano Toni, Matricola: 199678}
 * @version 0.1
 * @date 30-06-PMPMPMPM
 * @copyright Copyright (c) 2025
 */

/*******************************/
/* DEFINIZIONE MODULO "main" */
/*******************************/

#include <iostream>
#include <cstring>

using namespace std; 

#include "liste.h"
#include "compito.h"

int main()
{
    FILE* fp; 
    int nc,i,val,punt;
    int* v1;
    int* v2; 
    char s;
    lista mano1 = NULL;
    lista mano2 = NULL; 

    cout << "Numero di carte per mano (max 12): " << endl; 
    cin >> nc; 
    
    fp = fopen("g1.txt", "r");
    i = 0; 
    while((fscanf(fp,"%d %c",&val,&s)==2) && i < nc){
        pesca(mano1,val,s);
        i++;
    }
    fclose(fp);

    fp = fopen("g2.txt", "r"); 
    i = 0; 
    while((fscanf(fp,"%d %c",&val,&s)==2) && i < nc){
        pesca(mano2,val,s);
        i++; 
    }
    fclose(fp);

    stampa(mano1,mano2); 

    cout << "\n\n";

    v1= tris(mano1);

    cout << "Tris mano 1: " << endl; 
    for(int i=0; i<12; i++){
        cout << v1[i] << " ";
    }

    v2 = tris(mano2);

    cout << "\nTris mano 2: " << endl;
    for(int i=0; i<12; i++){
        cout << v2[i] << " ";
    }

    cout << "\n"; 

    punt = cala(mano1);

    cout << "Punteggio mano 1: " << punt << endl; 

    punt = cala(mano2); 

    cout << "Punteggio mano 2: " << punt;
    return 0; 
}