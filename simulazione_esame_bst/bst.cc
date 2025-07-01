#include <iostream>
using namespace std;

#include <cstring>

#include "bst.h"
static tipo_key copy_key(tipo_key& s,tipo_key s1){
	s=s1;
	return s;
}

static tipo_key compare_key(tipo_key s,tipo_key s1){
		return s1-s;
}

void print_key(tipo_key k){
	cout<<k;
}
tipo_key get_key(bnode* n){
	return (n->key);
}

tipo_inf get_value(bnode* n){
	return (n->inf);
}

bst get_left(bst t){
	return (t->left);
}

bst get_right(bst t){
	return (t->right);
}

bnode* get_parent(bnode* n){
	return (n->parent);
}



bnode* bst_newNode(tipo_key k, tipo_inf i){
	bnode* n=new bnode;
	copy(n->inf,i);
	copy_key(n->key,k);
	n->right=n->left=n->parent=NULL;
	return n;
}

void bst_insert(bst& b, bnode* n){
	bnode* x;
	bnode* y=NULL;
	if(b==NULL){
		    	b=n;
		    }
	else{
	    x=b;
	    while (x != NULL) {
	      y=x;
	      if (compare_key(get_key(n),get_key(x))<0) {
		      x = get_left(x);
	      } else {
		      x = get_right(x);
	      }
	    }
	    n->parent = y;
	    if (compare_key(get_key(n), get_key(y))<0) {
	      y->left = n;
	    } else {
	      y->right = n;
	    }
}}

bnode* bst_search(bst b,tipo_key k){ //bst al contrario : a sx i maggiori a dx i minori

	    while (b != NULL) {
	      if (compare_key(k,get_key(b))==0) {//(s,s1) -> return s1-s
			  //cout<< endl<< "sono uguali: trovato"<< k << get_key(b)<< " "<<b->inf.nome<< endl;
	    	  return b; 
		  }
	      if (compare_key(k,get_key(b))<0) {  //chiave albero < chiave da trovare
			  //cout<<"vado a sx, b_key < key: "<<get_key(b)<<endl;
		      b = get_left(b);
	      } else { //chiave albero > chiave da trovare
			  //cout<<"vado a dx, b_key > key: "<<get_key(b)<<endl;
		      b = get_right(b);
	      }
	    }
	    return NULL;
}

// Aggiorna il puntatore al figlio (sinistro o destro) del padre di p  al nuovo elemento q
void update_father(bnode* p, bnode* q)
{
	if (p == get_left(get_parent(p)))
				(p->parent)->left = q;
		else
				(p->parent)->right = q;
}


void bst_delete(bst& b, bnode* n){
	bnode* new_child; // variabile d'appoggio che individua il nodo da sostuire a n come figlio
	   if (get_left(n) == NULL) {
	                if (get_right(n) == NULL) //Nodo foglia
	                		new_child=NULL;
	                else {
	                       cout << "Nodo con solo figlio destro\n";//Solo figlio destro
	                       new_child=get_right(n);
	                }
	    }
	    else if (get_right(n) == NULL) { //Solo figlio sinistro
	            cout << "Nodo con solo figlio sinistro\n";
	            new_child=get_left(n);

			 }
			 else { //Entrambi i figli: cerco l'elemento più grande nel sottoalbero di sx
	            cout << "Nodo con entrambi i figli\n";
	            bnode* app = get_left(n);
	            while (get_right(app) != NULL) //cerco l'elemento più a destra nel sottoalbero di sx
	           		        	app = get_right(app);
	            if(get_left(app)==NULL){ //app è una foglia
					update_father(app, NULL);
		        } else {  //app ha il figlio sinistro
					(app->parent)->right = get_left(app);
					(app->left)->parent = get_parent(app);
		        }
			    // sostituisco app a n
			    app->left = get_left(n);
			    app->right = get_right(n);
			    if(get_left(app)!=NULL)
			    	(app->right)->parent = app;
			    if(get_left(app)!=NULL)
			    	(app->left)->parent = app;
			    new_child=app;

	        }
	   if(new_child!=NULL)
		   new_child->parent = get_parent(n);
	    if(n==b) // n è la radice
	    	b=new_child;
	    else
	    	update_father(n, new_child);
	  delete n;

}
/**
 * @author {Youssef Chiesi, Matricola}
 * @brief stampa in ordine decrescente i nodi nell'albero.
 * @param albero 
 */
void stampa_bst(bst albero)
{	
	cout<<endl;
	if(albero->left != NULL)
	{
		stampa_bst(albero->left); //sx i maggiori
	}
	cout<<albero->inf.nome << " " << albero->inf.luogo << " " << albero->key; //valore mediano
	if(albero->parent!=NULL)
	{
		cout<< " FIGLIO DI: "<< albero->parent->inf.nome <<endl;
	}
	cout<<endl;
	if(albero->right != NULL)
	{
		stampa_bst(albero->right); //dx i minori/uguali
	}
}


/**
 * @author {Youssef Chiesi, Matricola}
 * @brief stampa gli hotel > o <= al numero di stelle inserito in base al parametro cerca.
 * @param albero 
 * @param stelle identificativo stelle per stampare.
 * @param cerca se true stampa hotel con "stelle" > a quelle in input, se false il contrario.
 */
void ricerca(bst albero, int stelle, bool cerca) //a sx valori > a destra valori <
{
	bnode* nodo = bst_search(albero , stelle); //uso questo come albero di partenza.
	bnode* padre = nodo->parent;
	if(cerca == true) //stampo i maggiori.
	{
		if(nodo->left!=NULL)
		{
			stampa_bst(nodo->left); // maggiori diretti del nodo.
		}
		if(padre != NULL && (padre->right->key == nodo->key)) //sono a dx (minore del padre e della roba alla sua sx) //CASO RICORSIVO
		{
			while(padre!=NULL && (padre->right->key == nodo->key)){
				cout<<padre->inf.nome << " " << padre->inf.luogo << " " << padre->key;
				if(padre->left!=NULL)
				{
					stampa_bst(padre->left);
				}
				nodo = padre;
				padre = padre->parent;
			}
		}
		//sono a sinistra caso base: non faccio nulla perché non c'è uguale.
	}
	else //<=
	{
		if(padre!=NULL && padre->left->key == nodo->key)
		{
			while(padre!=NULL && padre->left->key == nodo->key) //caso ricorsivo : sono a sx.
			{
				//stampo le cose a dx:
				cout<<padre->inf.nome << " " << padre->inf.luogo << " " << padre->key; 
				if(padre->right!=NULL)
				{
					stampa_bst(padre->right);
				}
				nodo = padre;
				padre = padre->parent;
			}
			//sono a dx caso particolare:
			while(padre!=NULL && padre->key == stelle) //caso = del <=
			{
				cout<<padre->inf.nome << " " << padre->inf.luogo << " " << padre->key;
				padre = padre->parent; 
			}
		}
		//caso base a dx: non faccio niente.
	}
}