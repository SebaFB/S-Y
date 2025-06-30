#include <iostream>
#include <cstring>

using namespace std ;

#include "stringa.h"

/**
 * @author {Sebastiano Toni, Matricola: 199678}
 * 
 */

/*******************************/
/* DEFINIZIONE MODULO "tipo" */
/*******************************/

int compare(tipo_inf s1,tipo_inf s2){
	return strcmp(s1,s2);
}

void copy(tipo_inf& dest, tipo_inf source){
	dest=new char[strlen(source)];
	strcpy(dest,source);
}

void print(tipo_inf inf){
  cout<<inf;
}
