#include <iostream>
using namespace std;

int main(){
    double d = -3.4;
    int i = 7;

    d = d + i;
    i = d + i;

    cout << "d e' " << d << "; i e' " << i << endl;
    cout << "i+d da' " << i+d << "; d+i " << d+i << endl;

    bool flag = true, go = false;
    cout << "flag is " << flag << "while go is " << go << endl;

    int ottale = 023;
    int esadec = 0x3f;
    cout << "ottale " << ottale << "; esadecimale " << esadec << endl;
}