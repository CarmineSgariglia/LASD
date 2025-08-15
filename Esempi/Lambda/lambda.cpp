/*
Per passare una lambda function con una capture list non vuota in un parametro
di tipo puntatore a funzione accorre usare std::function nella dichiarazione
della funzione chiamante
*/

#include <iostream>
#include <functional> // include la libreria necessaria per std::function
using namespace std;

void amplifica(double *v, std::function<double(double)> func){
    for(int i = 0; i < 4; i++)
        v[i] = func(v[i]);
}

int main(){
    double myMeasures[]{12.3, 24.2, 4.5, 2.3};
    int amplFactor{7};

    amplifica(myMeasures, [&amplFactor](double x)->double{return amplFactor*x;});
    for(int i = 0; i < 4; i++) cout << myMeasures[i] << ',';
    cout << endl;
}