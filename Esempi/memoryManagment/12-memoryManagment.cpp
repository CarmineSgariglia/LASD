#include <iostream>
using namespace std;

int main(){
    int *p1 = new int{99};
    int *p2 = p1;
    delete p1; // e quindi anche p2!
    p1 = nullptr; // ma dovrei farlo anche con p2!
    char *p3 = new char{'X'} // p3 e p2 puntano alla stessa memoria ma con interpretazioni diverse
    *p2 =123; // questo non va bene
    cout << *p3 << endl; // potrebbe non stamapre 'X'
}