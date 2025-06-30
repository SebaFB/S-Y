#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("prova.txt");
    if (!file) {
        cerr << "Errore apertura file in lettura." << endl;
        return 1;
    }

    string riga;
    int numero = 1;
    while (getline(file, riga)) {
        cout << "Riga " << numero << ": " << riga << endl;
        numero++;
    }

    file.close();
    return 0;
}
