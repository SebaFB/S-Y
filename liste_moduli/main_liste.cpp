#include <iostream>
#include <cstring>
using namespace std;


#include "fun_liste.h"

int main()
{
    
    /*cout<< "Inserire scelta: "<<endl;
    cin>>scelta;*/
    /*switch(scelta)
    {
        case 0 :
            lista l1 = nullptr;
            l1 = crea_lista(6);
            stampa_lista(l1);
            break;
        case 1 :
            elem* e;
            cout<<"Inserire valore da eliminare:"<<endl;
            cin>>e->inf;

    }*/
    lista l1 = nullptr;
    l1 = crea_lista(6);
    elem* e1 = new elem;
    e1->pun = nullptr;
    e1->prev =nullptr;
    strcpy(e1->inf, "a");
    l1 = cancella(l1,e1->inf);
    cout<<endl<<"ULTIMA:"<<endl;
    stampa_lista(l1);
    /*while(continua == true)
    {
        
        /*int n = 0;
        cout<<endl<<"Inserire lunghezza lista:"<<endl;
        cin>>n;
        lista l = nullptr;
        l = crea_lista(n);
        stampa_lista(l);
        switch(scelta)
        {
            case 0:
                int n = 0;
                cout<<endl<<"Inserire lunghezza lista:"<<endl;
                cin>>n;
                lista l1 = nullptr;
                l1 = crea_lista(n);
                break;
            /*case 2:
                char c; 
                cout<<"Inserire valore da cancellare: "<<endl;
                cin>> c;
                l = cancella(l,&c);
                break;
                
            default:
                cout<< "Inserire valore valido"<<endl;
                break;

        }
        //continua = false;
   // }*/
    
    return 0;
}

