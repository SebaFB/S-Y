#include <iostream>
using namespace std;


#include "grafo.h"
#include <string.h>
int main()
{
    tipo_inf* array;
    int n;
    array = creaNodi(n);
    //cout<<"Dimensione: "<<n<<endl;
    graph g = new_graph(n);
    //adj_node nodi = new adj_node[n];
    FILE* file_val = fopen("valutazioni.txt", "r");

    
    for(int j = 0; j < n ; j++)
    {
        g.nodes[j]->spec.tipo = array[j].tipo;
        strcpy(g.nodes[j]->spec.descrizione, array[j].descrizione);
        cout<< ": " << g.nodes[j]->spec.descrizione <<endl;
    }
    
    //adj_node* user = NULL;
    
    fclose(file_val);
    cout<<"--------------------"<<endl;
    //stampa_grafo(g);
    return 0;
}