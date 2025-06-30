#include <iostream>

using namespace std;

#include "albero.h"

/**
 * @author {Sebastiano Toni, Matricola: 199678}
 * @brief Modulo per la gestione di alberi generici.
 */

tree root = nullptr;

node* new_node(tipo_inf i){
    node* n = new node;
    n->first_child = nullptr;
    n->next_sibling = nullptr;
    n->parent =nullptr;
    copy(n->inf,i);
    return n;
}


void insert_child(tree p, tree c) //inserisco c come figlio di p.
{
    c->next_sibling=p->first_child;
	c->parent=p;
	p->first_child=c;
}

void insert_sibling(node* n, tree t) //aggiorno n inserendo t come suo fratello (t albero)
{
    t->next_sibling = n->next_sibling;
    t->parent = n->parent; 
    n->next_sibling = t; 
}

tipo_inf get_info(node* n)
{
    if(n!=nullptr)
        return n->inf;
    else
        return nullptr;
}

node* get_parent(node* n)
{
    if(n->parent !=nullptr)
        return n->parent;
    else
        return nullptr;
}

node* get_FirstChild(node* n)
{
    if(n->first_child!=nullptr)
    {
        //cout<<"inserito figlio correttamente"<<endl;
        return n->first_child;
    }
    return nullptr;
}

node* get_NextSibling(node* n)
{
    if(n->next_sibling!=nullptr)
        return n->next_sibling;
    return nullptr;
}

void dfs_albero(tree t) //in preorder (nodo,figli):
{
    cout << t->inf << endl; 
    if(t->first_child != nullptr)
        dfs_albero(t->first_child); 
    node* frat = t;
    if(frat->next_sibling != nullptr)
        dfs_albero(frat->next_sibling); 
}
