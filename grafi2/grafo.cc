/*
 * grafi.cc
 *
 *  Created on: 29 mag 2018
 *
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

#include "grafo.h"
adj_node* new_node(int n)
{
	adj_node* nuovo = new adj_node;
	nuovo->node = n;
	nuovo->next = NULL;
	return nuovo;
}
graph new_graph(int n){
	graph G;
	G.dim=n;
	G.nodes= new adj_list[n];
	  for (int i=0; i<n; i++) {
		adj_node* e = new_node(i+1);
		G.nodes[i] = e;
		//cout<<"NODO: "<<G.nodes[i]->node<<endl;
	  }
	  return G;

}
/*
	graph G;
	G.dim=n;
	G.nodes= new adj_list[n];
	for (int i=0; i<n; i++) {
	    if(G.nodes[i]!=NULL)
		{
			
			G.nodes[i]->node = i+1;
			G.nodes[i]->next = NULL;
			
			//G.nodes[i]->elem.id = i+1;
			//cout<<"nodo: "<< G.nodes[i]->node<< " "<< i <<endl;
			cout<< i <<endl;
		}
		else
		{
			cout<< "sorpresa: "<<i <<endl;
		}
	}
	  cout<<"oooo"<<endl;
	  return G;

}
*/
/* Funzione che aggiunge l'arco orientato (u,v) alla lista di adiacenza del
 * nodo u (aggiunge in testa alla lista).*/
/**
 * @brief aggiunge i nodi con anche le informazioni di tipo_inf copiate al loro interno.
 */
void add_arc(graph& G, int u, int v) { 

  adj_node* t = new_node(v);
  //cerco tipo_inf di v.
  for(int i = 0; i < G.dim; i++)
  {
	adj_list l = G.nodes[i];
	while(l->next!=NULL)
	{
		l = l->next;
	}
	if(l->node == v) //ho trovato il suo posto originale in G.nodes e ne copio le info di tipo_inf
	{
		copy(&(t->elem),l->elem);
		i = G.dim + 1;
	}
  }
  t->node = v-1;
  //t->weight = w;
  t->next = G.nodes[u-1];
  G.nodes[u-1] = t;
}


/* Funzione che aggiunge l'arco non orientato (u,v) alle liste
 * di adiacenza di u e v.*/
void add_edge(graph& g, int u, int v) {
  add_arc(g,u,v);
  add_arc(g,v,u);
  //cout<<"aggiunto arco tra "<< u << " "<< v <<endl;
}


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
/**
 * @author {Youssef Chiesi, Matricola}
 * 
 * @param g grafo
 * @param array contiene le informazioni tipo_inf
 */
void stampa(graph* g, tipo_inf* array)
{
	for (int i = 0; i < g->dim; i++)
	{
		tipo_inf a = array[i];
		//print(a);
		if(a.tipo == 'D' && a.stato == 'G')
		{
			//devo scorrere la adj_list del nodo fino a quando non trovo il nodo da cui dipende.
			adj_list l = g->nodes[i];
			cout<<"NODO NUMERO "<< a.id <<endl;
			while(l!=NULL && l->elem.tipo != 'O') //ultimo elemento è corrisp di a.id
			{
				//cout<<" " << l->elem.id << " " << l->elem.tipo << " ";
				l = l->next;
			}
			if(l!=NULL)
			{
				//cout<<l->elem.id<<" : "<< l->elem.stato<< endl;
				if(l->elem.stato == 'P') //operatore presente
				{
					cout<< "Macchinario "<< a.id<< " richiede manutenzione da operatore "<< l->elem.id <<endl;
				}
				else
				{
					cout<< "WARNING: Macchinario "<< a.id<< " richiede manutenzione ma non ha operatori!"<<endl;
				}
			}
			else
			{
				cout<< "NON HA TROVATO OPERATORE"<<endl;
			}
		}
	}
}


void operativitaDegrata(graph* g , tipo_inf* array, int m)
{
	//Cerco m in G.nodes
	adj_list l = g->nodes[m-1]; //è 0 based mentre gli indici sono 1 based.
	cout<<"MACCHINARI INFLUENZATI: "<<endl;
	while(l->next!=NULL)
	{
		if(l->elem.tipo == 'D') //tutti i macchinari in g.nodes[m-1].
		{
			print(l->elem);
		}
		l = l->next;
	}
}