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
#include "tipo.h"
#include "compito.h"

extern "C" char* lettura(FILE* fp){
    fp = fopen("g1.txt", "r"); 

    long n;
    n = ftell(fp);

    char s[n]; 

    fgets(s,n,fp);
    
    fclose(fp);
    if(fp==EOF)
        exit(1);
    
    return s; 
}

int main()
{

}