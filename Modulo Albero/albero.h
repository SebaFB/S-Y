/* PRIMITIVE ALBERO E STRUTTURA: */

#include "stringa.h"

struct node
{
    tipo_inf inf;
    node* first_child;
    node* next_sibling;
    node* parent;
};
typedef node* tree; //punterà alla radice dell'albero (simile l liste.)

extern tree root; //variabile di tipo tree.

node* new_node(tipo_inf);

void insert_child(tree, tree); //inserisco c come figlio di p.

void insert_sibling(node*, tree);

tipo_inf get_info(node*); //restituisce il campo info del nodo

node* get_parent(node*); //restituisce il parent

node* get_FirstChild(node*); //restituisce il firstchild

node* get_NextSibling(node*); //restituisce il nextsibling

void dfs_albero(tree);

int altezza(tree, int, int);