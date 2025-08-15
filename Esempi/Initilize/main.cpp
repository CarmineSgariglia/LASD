#include <iostream>
#include <complex>
#include <vector>
using namespace std;

int main(){
    double d1 =2.3;
    double d2 {2.3};

    complex<double> z1 = 1;
    complex<double> z2 {d1, d2};
    complex<double> z3 = {1, 2};   // = opzionale

    vector<int> v1 {1,2,3,4,5,6};

    cout << "d1 e' " << d1 << '\n';
    cout << "d2 e' " << d2 << '\n';
    cout << "z1 e' " << z1 << '\n';
    cout << "z2 e' " << z2 << '\n';
    cout << "z3 e' " << z3 << '\n';
    for(int i = 0; i < 6; i++)
        cout << "v1[ " << i << "] e' " << v1[i] << '\n';
}