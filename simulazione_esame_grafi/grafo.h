#include "compito.h"
struct adj_node {
  tipo_inf spec;
  int node;
  float weight; //peso in stelle.
  struct adj_node* next;
};


typedef adj_node* adj_list;

typedef struct
{adj_list* nodes;
 int dim;
} graph;

graph new_graph(int);
void add_arc(graph&, int, int, float);
void add_edge(graph& g, int, int, float);

int get_dim(graph);
adj_list get_adjlist(graph,int);
int get_adjnode(adj_node*);
float get_adjweight(adj_node*);
adj_list get_nextadj(adj_list);

adj_node* trova_utente(graph, char*, char);
adj_node* new_node(tipo_inf);

void stampa_grafo(graph);