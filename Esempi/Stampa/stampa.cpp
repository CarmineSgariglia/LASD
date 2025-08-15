#include <iostream>
#include <vector>
using namespace std;

struct Studente {
    string nome;
    string corsoDiLaurea;
    int matricola;
};

vector<Studente> corsoSL {
    {"Russo Elisabetta", "N97", 452},
    {"Capasso Mario", "N97", 442},
    {"Assante Lucia", "N97", 439},
    {"Parcelli Ciro", "N97", 440},
    {"Livorno Anita", "N97", 451}
};

void stampaStudente(const Studente& a) {
    cout << a.nome << "\t" << a.corsoDiLaurea << '/' << a.matricola;
}

void stampaMatricola(const Studente& a) {
    cout << a.corsoDiLaurea << '/' << a.matricola << "\t" << a.nome;
}

using PRINTF = void(const Studente&);
void stampaVettore(vector<Studente>& v, PRINTF stampa) {
    for (auto& x : v) {
        stampa(x);
        cout << endl;
    }
}

int main() {
    stampaVettore(corsoSL, stampaStudente);
    string cornicetta(70, '*');
    cout << cornicetta << endl;
    stampaVettore(corsoSL, stampaMatricola);
}
