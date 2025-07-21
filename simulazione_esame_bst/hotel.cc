#include <iostream>
using namespace std;
/**
 * @file hotel.cc
 * @author Youssef Chiesi (you@domain.com)
 * @author {Youssef Chiesi, Matricola}
 * @version 0.1
 * @date 2025-07-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "hotel.h"
/**
 * @author {Youssef Chiesi, Matricola}
 * 
 * @param nome 
 * @param luogo 
 * @param stelle 
 * @return tipo_inf 
 */

tipo_inf new_hotel(char* nome, char* luogo, int stelle)
{
    tipo_inf hotel;
    strcpy(hotel.nome , nome);
    strcpy(hotel.luogo , luogo);
    hotel.stelle = stelle;
    return hotel;
}

void copy(tipo_inf& a, tipo_inf b)
{
    strcpy(a.luogo,b.luogo);
    strcpy(a.nome,b.nome);
    a.stelle = b.stelle;
}

