/**
 * @file liste.h
 * @author {Sebastiano Toni} ({349608@studenti.unimore.it})
 * @author {Sebastiano Toni, Matricola: 199678}
 * @version 0.1
 * @date 30-06-PMPMPMPM
 * @copyright Copyright (c) 2025
 */

/*******************************/
/* HEADER MODULO "liste" */
/*******************************/
#include "tipo.h"

struct elem{
       tipo_inf inf;
       elem* pun ;
       elem* prev;
} ;

typedef elem* lista ;
	
lista tail(lista);
lista prev(lista);
lista insert_elem(lista, elem*);
lista delete_elem(lista, elem*);

tipo_inf head(lista);
elem* new_elem(tipo_inf);
elem* search(lista, tipo_inf);
