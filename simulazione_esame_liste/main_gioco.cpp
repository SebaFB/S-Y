#include <iostream>
using namespace std;

#include "compito.h"

int main()
{
    
    int n_carte;
    cout<< "Inserire numero di carte da assegnare ad ogni giocatore: ";
    cin>>n_carte;
    cout<<endl;
    //lettura file:
    int val;
    char seme;
    FILE* file1 = fopen("g1.txt", "r");
    int i = 0;
    lista mano1 = NULL;
    while ((fscanf(file1, "%d %c", &val, &seme) == 2) && i < n_carte)
    {
        pesca(mano1,val,seme);
        i++;
    }
    fclose(file1);
    i = 0;
    FILE* file2 = fopen("g2.txt", "r");
    lista mano2 = NULL;
    while ((fscanf(file2, "%d %c", &val, &seme) == 2) && i < n_carte)
    {
        pesca(mano2,val,seme);
        i++;
    }
    fclose(file2);
    stampa(mano1,mano2);

    //2.b
    pesca(mano1,2,'Q');
    pesca(mano2,7,'C');
    int punteggio1 = 0;
    int punteggio2 = 0;
    
    for(int m = 0; m < 3; m++)
    {
        //cout<<"punteggio parziale 1"<< punteggio1<<endl;
        punteggio1 = punteggio1 + cala(mano1);
    }
    cout<<"PUNTEGGIO1: "<<punteggio1<<endl;
    cout<<"-----------------------------"<<endl<<endl<<endl;
    for(int m = 0; m < 4; m++)
    {
        //cout<<"punteggio parziale 2"<< punteggio2<<endl;
        punteggio2 = punteggio2 + cala(mano2);
        
    }
    cout<<"PUNTEGGIO2: "<<punteggio2<<endl;
    
    return 0;
}