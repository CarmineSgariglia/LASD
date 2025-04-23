#include <iostream>
using namespace std;

void error(string s) {cout << s << "Dentro la funzione  error()\n";}

int main (){
    void (*puntAFunzione)(string)

    // I seguenti due assegnamenti sono del tutto equivalenti
    puntAFunzione  = &error;
    puntAFunzione = error;

    puntAFunzione("Chiamo error() senza *\n");
    (*puntAFunzione)("Chiamo error() con *\n")
}