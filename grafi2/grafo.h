

#ifndef GRAFI_H_
#define GRAFI_H_
#include "impianto.h"
struct adj_node {
  int node;
  float weight;
  tipo_inf elem;
  struct adj_node* next;
};


typedef adj_node* adj_list;

typedef struct
{adj_list* nodes;
 int dim;
} graph;

graph new_graph(int);
void add_arc(graph&, int, int);
void add_edge(graph&, int, int);

int get_dim(graph);
adj_list get_adjlist(graph,int);
int get_adjnode(adj_node*);
float get_adjweight(adj_node*);
adj_list get_nextadj(adj_list);

adj_node new_node(int, tipo_inf);
void stampa(graph*, tipo_inf*);

void operativitaDegrata(graph* , tipo_inf* , int);
#endif /* GRAFI_H_ */
