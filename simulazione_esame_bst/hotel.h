/**HEADER FILE HOTEL:
 * @file hotel.h
 * @author Youssef Chiesi (you@domain.com)
 * @author {Youssef Chiesi, Matricola}
 * @version 0.1
 * @date 2025-07-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
/**
 * STRUTTURA HOTEL.
 */
#include <string.h>
typedef struct 
{
    char nome[20];
    char luogo[20];
    int stelle;
}tipo_inf;

tipo_inf new_hotel(char*, char*, int);

void copy(tipo_inf&, tipo_inf);
