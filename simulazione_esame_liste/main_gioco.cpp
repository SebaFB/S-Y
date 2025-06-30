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
    lista mano1;
    while ((fscanf(file1, "%d %c", &val, &seme) == 2) && i < n_carte)
    {
        pesca(mano1,val,seme);
    }
    fclose(file1);
    i = 0;
    FILE* file2 = fopen("g2.txt", "r");
    lista mano2;
    while ((fscanf(file1, "%d %c", &val, &seme) == 2) && i < n_carte)
    {
        pesca(mano2,val,seme);
    }
    fclose(file2);
    stampa(mano1,mano2);
    return 0;
}