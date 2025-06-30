#include <iostream>

using namespace std;

#include "albero.h"
#include "stringa.h"
//#define DEBUG

void serialize(tree t){
	cout << "("; 
	print(get_info(t)); 
	tree t1 = get_FirstChild(t); 
	while(t1!=nullptr){
		serialize(t1); 
		t1 = get_NextSibling(t1);
	}
	cout << ")"; 
}

int main()
{
	tree t=NULL;
	char b[5] = "Luca" ;
	t=new_node(b);
	char a [6] = "Paolo";
	node* n=new_node(a);
	insert_child(t,n);

#ifdef DEBUG
	cout<<"Root:"<<get_info(t)<<endl;
	cout<<"Root->first child: "<<get_info(get_FirstChild(t))<<endl;
#endif

	char c[6] = "Marco";
	n=new_node(c);
	insert_sibling(t->first_child,n);

#ifdef DEBUG
	cout<<"Root->second child: "<<get_info(get_NextSibling(get_FirstChild(t)))<<endl;
	cout<<"Marco and Paolo's parent:"<<get_info(get_parent(get_FirstChild(t)))<<" "<<get_info(get_parent(get_NextSibling(get_FirstChild(t))))<<endl;
#endif

	char d[6] = "Lucia";
	n=new_node(d);
	insert_child(t->first_child->next_sibling,n);
	char e[5] = "Anna";
	node* m=new_node(e);
	insert_sibling(n->parent,m);

#ifdef DEBUG
	cout<<"Lucia's parent: "<<get_info(get_parent(n))<<endl;
	cout<<"Root->third child: "<<get_info(get_NextSibling(get_NextSibling(get_FirstChild(t))))<<endl;
#endif

	dfs_albero(t);

	cout << "\nSerialize:" << endl; 

	serialize(t); 

	//int h = altezza(t, 0,0);
	//cout<<"ALTEZZA ALBERO: "<< h <<endl;
}