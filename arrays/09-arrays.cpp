#include <iostream>
using namespace std;

int main(){
    char pippo[13] = "pippo";
    for(int i =0; pippo[i]!=0; i++)
        cout << i << ") " << pippo[i] << endl;
    
    for(char* ptr = pippo; *ptr != 0; ++ptr)
        cout << ptr << " " << *ptr << endl;

        double pluto[5];

        for(int i = 0; i<5; i++)
            pluto[i] = i + 1;
        pluto[5] = 0; // out of boundary!

        for(double * ptr=pluto; *ptr != 0; ++ptr)
            cout << *ptr << endl;
}