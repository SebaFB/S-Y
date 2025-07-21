/**
 * @file compito.cc
 * @author Youssef Chiesi (you@domain.com)
 * @author {Youssef Chiesi, Matricola}
 * @version 0.1
 * @date 2025-07-21
 * @brief AVVIENE LA LETTURA DA FILE E LA GESTIONE DEL MAIN.
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
using namespace std;


#include "grafo.h"

int main()
{

    FILE* file = fopen("impianto.txt", "r");
    int n_nodi = 0;
    int n_archi = 0;
    if (fscanf(file, "%d %d", &n_nodi, &n_archi) != 2) {
        cerr << "Errore nella lettura del numero nodi e archi.\n";
        fclose(file);
        return 1;
    }
    //cout<<" N: "<<n_archi<<" "<<n_nodi<<endl;
    graph g = new_graph(n_nodi);
    
    //creo array dinamico;
    tipo_inf* array = new tipo_inf[n_nodi];

    for(int i = 0; i < n_nodi; i++)
    {
        if(fscanf(file,"%d %c %c", &(array[i].id), &(array[i].tipo), &(array[i].stato))!=3)
        {
            cerr << "Errore nella lettura.\n";
            fclose(file);
            return 1;
        }
        //print(array[i]);
        //li inserisco nel grafo:
        copy(&(g.nodes[i]->elem), array[i]);
    }
    for(int i = 0; i < n_archi; i++)
    {
        int s;
        int d;
        if(fscanf(file,"%d %d", &s, &d)!=2)
        {
            cerr << "Errore nella lettura.\n";
            fclose(file);
            return 1;
        }
        //cout<<endl<< s <<" " << d <<endl;
        add_edge(g,s,d);
    }

    graph* punt = &g;
    //cout<<"ciao"<<endl;
    stampa(punt, array);
    
    return 0;
    
}
