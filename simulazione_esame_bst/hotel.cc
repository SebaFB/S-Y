#include <iostream>
using namespace std;

#include "hotel.h"


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