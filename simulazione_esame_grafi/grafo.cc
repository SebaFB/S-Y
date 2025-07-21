/*
 * grafi.cc
 *
 *  Created on: 29 mag 2018
 *      Author: federica
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#include "grafo.h"

graph new_graph(int n){
	graph G;
	G.dim=n;
	G.nodes= new adj_list[n];
	  for (int i=0; i<n; i++) {
	    G.nodes[i] = NULL;  //indicazione di lista vuota
	  }
	  return G;

}
/*
graph new_graph(int n) //da 1 a n nodi con n liste di adiacenza.
{
    graph g;
    g.dim = n;
    g.nodes = new adj_list[g.dim]; //array di liste di adiacenza.
    for(int i = 0; i < n; i++)
    {
        adj_list elemento = new adj_node;//inizializzo lista di adiacenza vuota per ogni nodo
        elemento->node = i+1; //assegno il nodo di riferimento alla lista.
        elemento->next = nullptr;
        elemento->weight = 0;
        g.nodes[i] = elemento; //inserisco le singole liste di adiacenza in un array di liste.
		//cout<< "node: "<< g.nodes[i]->node<<endl;
    }
    return g;
}
*/
/* Funzione che aggiunge l'arco orientato (u,v) alla lista di adiacenza del
 * nodo u (aggiunge in testa alla lista). L'arco ha peso w. */

void add_arc(graph& G, int u, int v, float w) {
  adj_node* t = new adj_node;
  t->node = v-1;
  t->weight = w;
  t->next = G.nodes[u-1];
  G.nodes[u-1] = t;
}

/*
 Funzione che aggiunge l'arco non orientato (u,v) alle liste
 * di adiacenza di u e v. L'arco ha peso w. 
void add_edge(graph& g, int u, int v, float w) {
  add_arc(g,u,v,w);
  add_arc(g,v,u,w);
}
*/
/*
void add_arc(graph& g , int s , int d , float w) //arco orientato s->d con peso w, nella lista di adiacenza di s. //modifica reale perché passo &g, come passare un puntatore.
{
    adj_list l = g.nodes[s-1]; //prendo la lista di riferimento di l;
    while(l->next!=nullptr)
    {
        l = l->next;
    }
    //l->next = nullptr;
    //creo nodo d da inserire in l.
    adj_node* d1 = new adj_node; //bisogna fare così altrimenti le celle di memoria dei campi non sono inizializzate.
    d1->next = nullptr;
    d1->node = d;
	strcpy(d1->spec.descrizione, g.nodes[d-1]->spec.descrizione);
	d1->spec.tipo = 'P';
    d1->weight = w;
    l->next = d1;
}
*/
int get_dim(graph g){
	return g.dim;
}

adj_list get_adjlist(graph g,int u){
	return g.nodes[u-1];
}

int get_adjnode(adj_node* l){
	return (l->node+1);
}

adj_list get_nextadj(adj_list l){
	return l->next;
}

float get_adjweight(adj_node* l){
	return (l->weight);
}

adj_node* trova_utente(graph g, char* nome, char tipo)
{
	tipo_inf a;
	a.tipo = tipo;
	strcpy(a.descrizione,nome);
	for(int i = 0; i < g.dim; i++)
	{
		/*
		cout<<"SONO A: "<<i<<endl;
		cout<<g.nodes[i]->spec.descrizione << " e " << a.descrizione<<endl;
		cout<<g.nodes[i]->spec.tipo << " e " << a.tipo <<endl;
		*/
		if(compare(g.nodes[i]->spec,a) == 0)
		{
			return g.nodes[i];
		}
	}
	cout<< "NON TROVATO"<<endl;
	return NULL;
}

void stampa_grafo(graph g)
{
	for(int i = 0; i < g.dim; i++)
	{
		if(g.nodes[i]->spec.tipo == 'U') //stampo per ogni utente:
		{
			//scorro tutta la lista:
			cout<< "PER L'UTENTE: "<< g.nodes[i]->spec.descrizione << endl;
			adj_list l = g.nodes[i]->next;
			while(l != NULL)
			{
				cout<< "PRODOTTO: "<< l->spec.descrizione << "VALUT: "<< l->weight <<endl;
				l = l->next;
			}
		}
	}
}

