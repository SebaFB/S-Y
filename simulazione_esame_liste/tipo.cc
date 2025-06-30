/**
 * @file tipo.cc
 * @author Youssef Chiesi
 * @brief Implementazione funzioni compare, copy e print riferite a tipo_inf.
 * @version 0.1
 * @date 2025-06-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include "tipo.h"
using namespace std;


/**
 * @brief ritorna -1 se il valore della prima è minore della seconda o se il seme della prima è inferiore alla seconda.
 * 
 * @param a tipo_inf (carta)
 * @param b tipo_inf (carta)
 * @return int -1 se a minore di b, 1 altrimenti.
 */
int compare(tipo_inf a,tipo_inf b)
{
    if(a.valore < b.valore)
    {
        return -1;
    }
    else if((a.valore == b.valore) && (a.seme != b.seme)) //ordine: C >Q >F> P.
    {
        if(b.seme == 'C')
        {
            return -1;
        }
        if((b.seme == 'Q' && a.seme=='F' )|| (b.seme == 'Q' && a.seme=='P'))
        {
            return -1;
        }
        if(b.seme == 'F' && a.seme == 'P')
        {
            return -1;
        }
    }
    if((a.valore == b.valore)&&(a.seme == b.seme))
    {
        return 0;
    }
    return 1;
}
/**
 * @brief funzione che copia i valori della seconda carta nella prima.
 * 
 * @param a tipo_inf dove vengono copiati i valori, passato per riferimento.
 * @param b tipo_inf da cui vengono copiati i valori.
 */
void copy(tipo_inf& a, tipo_inf b)
{
    a.seme = b.seme;
    a.valore = b.valore;
}

/**
 * @brief print dei due campi della struct tipo_inf
 * 
 * @param a struct di cui si vogliono conoscere i valori.
 */
void print(tipo_inf a)
{
    cout<<"Il valore della carta: "<< a.valore <<" e il seme: "<< a.seme <<endl;
}
