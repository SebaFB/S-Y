#include <iostream>
using namespace std;

#include "compito.h"
#include <string.h>
//che legge il contenuto del file nodi.txt, genera un vettore dinamico contenente la descrizione dei nodi e restitutisce il vettore e la dimensione

tipo_inf* creaNodi(int& n)
{
    FILE* file = fopen("nodi.txt", "r");
    if (fscanf(file, "%d", &n) != 1) {
        cerr << "Errore nella lettura del numero nodi.\n";
        fclose(file);
        return nullptr;
    }
    cout<<n<<endl;
    tipo_inf* array = new tipo_inf[n];
    while (fgetc(file) != '\n' && !feof(file));
    for(int i = 0; i < n; i++)
    {
        char nome[20];
        char tipo; 
        fgets(nome, sizeof(nome), file);
        nome[strcspn(nome, "\n")] = '\0';
        if (fscanf(file, "%c", &tipo) != 1) {
            cerr << "Errore nella lettura del TIPO .\n";
            fclose(file);
            return nullptr;
        }
        while (fgetc(file) != '\n' && !feof(file)); 
        nome[strcspn(nome, " ")] = '\0'; //tolgo spazio che viene letto da fgets e inserito.
        nome[strcspn(nome, "\n")] = '\0'; //tolgo il new line che viene letto da fgets e inserito.
        strcpy(array[i].descrizione,nome);
        array[i].tipo = tipo;
        cout<<array[i].descrizione << " " << array[i].tipo <<endl;
    }
    return array;
}