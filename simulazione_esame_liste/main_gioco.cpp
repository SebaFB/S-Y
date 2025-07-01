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

    //punto 2.a:
    int* array1 = NULL;
    
    array1 = tris(mano1);
    
    for(int j = 0; j < 12; j++)
    {
        cout<<array1[j]<<endl;
    }
    
    delete[] array1; //per oggetti multipli, altrimenti : int* p = new int; delete p; ma per oggetti singoli
    /*print_mano(mano1);
    
    print_mano(mano2);*/
    cout<<"--------------------------------------"<<endl;
    int* array2 = NULL;
    array2 = tris(mano2);
    
    
    for(int f = 0; f < 12; f++)
    {
        cout<<array2[f]<<endl;
    }

    delete[] array2;
    cout<<"--------------------------------------"<<endl;
    return 0;
}