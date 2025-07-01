#include <iostream>
using namespace std;


#include "compito.h"
/**
 * @brief aggiunge alla lista in mano al giocatore una carta
 * 
 * @param l lista "Mano" del giocatore
 * @param v valore carta
 * @param s seme carta
 */
void pesca(lista& l, int v, char s)
{
    if (v < 1 || v > 12) {
        cerr << "[ERRORE] Valore non valido per una carta: " << v << endl;
        return;
    }   
    tipo_inf carta;
    carta.seme = s;
    carta.valore = v;

    // Rimuovi allocazione ridondante:
    elem* node = new_elem(carta);
    l = insert_elem(l, node);
}


void print_mano(lista l)
{
    elem* tmp = l;
    cout<<"-----------"<<endl;
    while(tmp!=NULL)
    {
        cout<<"valore: "<<tmp->inf.valore<< " seme: "<<tmp->inf.seme<<endl;
        tmp = tmp->pun;
    }
}

/**
 * @author {Youssef Chiesi, Matricola}
 * 
 * @param mano1 è la mano del giocatore 1
 * @param mano2 è la mano del giocatore 2
 * stampa le due liste di carte a coppie nella stessa posizione e, per ogni coppia se la carta è minore, maggiore o uguale
 */
void stampa(lista mano1, lista mano2)
{
    elem* tmp1 = mano1;
    elem* tmp2 = mano2;
    int a;
    while(tmp1!=NULL && tmp2!=NULL)
    {
        a = compare(tmp1->inf,tmp2->inf);
        if(a < 0)
        {
            cout<<"valore: "<<tmp1->inf.valore<< " seme: "<<tmp1->inf.seme<< " MINORE di " <<"valore: "<<tmp2->inf.valore<< " seme: "<<tmp2->inf.seme<<endl;
        }
        else if(a == 0)
        {
            cout<<"valore: "<<tmp1->inf.valore<< " seme: "<<tmp1->inf.seme<< " UGUALE di " <<"valore: "<<tmp2->inf.valore<< " seme: "<<tmp2->inf.seme<<endl;
        }
        else //a == 1   
        {
            cout<<"valore: "<<tmp1->inf.valore<< " seme: "<<tmp1->inf.seme<< " MAGGIORE di " <<"valore: "<<tmp2->inf.valore<< " seme: "<<tmp2->inf.seme<<endl;
        }
        tmp1 = tmp1->pun;
        tmp2 = tmp2->pun;
    }
}
/**
 * @author {Youssef Chiesi, Matricola}
 * @brief conta nella lista carte il numero di tris distinti per valore. 
 * @brief tris: tre carte con lo stesso valore (indipendentemente dal seme).
 * @param carte 
 * @return int* un vettore dinamico di dimensione 13
 */

int* tris(lista carte)
{
    int* array = new int[12]; ;
    elem* scorri = carte;
    for(int j = 0; j < 12; j++)
    {
        array[j] = 0;
    }
    int k = 0;
    while(scorri!=NULL && k < 12)
    {
        //cout<<"dove sono: "<<scorri->inf.valore - 1<<endl;
        if((scorri->inf.valore-1)>= 0 && (scorri->inf.valore-1)<12) //aggiungo una ricorrenza
        {
            array[scorri->inf.valore - 1] = array[scorri->inf.valore - 1] +1;
        }
        else
        {
            cout<< "sono uscito dai bordi"<<endl;
        }
        scorri = scorri->pun;
        k = k+1;
    }
    for(int i = 0; i < 12; i++)
    {
        array[i] = array[i]/3; //numero tris.
    }
    return array;
}



/**
 * @author {Youssef Chiesi, Matricola}
 * @brief funzione che cerca un tris da calare sul tavolo, stampa il tris trovato e aggiorna la lista delle carte del giocatore eliminandolo
 * @param carte lista doppia che contiene le carte del giocatore
 * @return int che rappresenta il punteggio del tris appena eliminato.
 */
int cala(lista& carte)
{
    int* terz = tris(carte);
    bool esiste = false; // esiste un tris;
    int a = -1;
    while( a < 12 && esiste == false)
    {
        a++;
        if(terz[a]>0)
        {
            esiste = true;
        }
    }
    if(esiste == false)
    {
        return 0;
    }
    else
    {
       cout<<"tris di "<< a+1<<endl;
       elem* tmp = carte;
       int contatore = 0;
       elem* pross = NULL;
       while(tmp!=NULL && contatore < 3)
       {
            cout<< "sono a "<<tmp->inf.valore <<" con seme: " << tmp->inf.seme<<endl;
            if(tmp->inf.valore == (a+1))
            {
                cout<<"rimuovo la seguente carta: "<<tmp->inf.valore<< " seme: "<<tmp->inf.seme<<endl;
                pross = tmp->pun;
                carte = delete_elem(carte, tmp);
                contatore = contatore+1;
                tmp = pross;
            }
            else
            {
                tmp = tmp->pun;
            }
       }
       //calcolo punteggio:
       int punteggio = (a+1)*3; //a+1 valore
       delete(terz);
       return punteggio;
    }
}