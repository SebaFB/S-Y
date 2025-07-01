#include <iostream>
using namespace std;

#include "bst.h"

int main()
{
    tipo_inf hotel;
    char nome[6] = "Pablo";
    char luogo[9] = "Fontana";
    hotel = new_hotel(nome, luogo, 5);

    FILE* file = fopen("hotel.txt", "r");
    
    int n_hotel = 0;
    if (fscanf(file, "%d", &n_hotel) != 1) {
        cerr << "Errore nella lettura del numero hotel.\n";
        fclose(file);
        return 1;
    }
    bst albero = NULL;
    for(int i = 0; i < n_hotel; i++)
    {
        int stelle;
        char nome[20];
        char luogo[20]; 
        if(fscanf(file, "%d", &stelle) != 1) {
            cerr << "Errore nella lettura delle stelle.\n";
            fclose(file);
            return 1;
        }
        while (fgetc(file) != '\n' && !feof(file)); // Scarta fino a newline
        fgets(nome, sizeof(nome), file);
        nome[strcspn(nome, "\n")] = '\0';
        fgets(luogo, sizeof(luogo), file);
        luogo[strcspn(luogo, "\n")] = '\0'; //tolgo il new line che viene letto da fgets e inserito.
        cout<<nome << " " << luogo << " " << stelle<<endl;

        //inserimento nel bst:
        tipo_inf hotel = new_hotel(nome, luogo, stelle);
        bnode* nodo = bst_newNode(stelle, hotel);
        bst_insert(albero, nodo);
    }
    stampa_bst(albero);
    return 0;
}