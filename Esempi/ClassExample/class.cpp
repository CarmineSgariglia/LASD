#include <iostream>
using namespace std;

template>typename C>
class String{
    public:
        String();
        explicit String(int, const C*); // no implicit type conversion
        String(const String&);
        String operator =(const String&);
        // ...
        // C& operator[](int n){return ptr[n];}
        String& operator += (C c);
        void stampa();
        //...
    private:
        static const int short_max = 15;
        int sz;
        C *ptr; //ptr points to sz Cs

};

template<typename C>
String<C>::String(int s, const C* init){
    sz = s;
    ptr = new C[sz];
    for(int i = 0; i < sz; i++)
        ptr[i] = init[i];
}

template<typename C>
void String<C>::stampa(){
    cout << sz << ": ";
    for(int i = 0; i <sz; i++)
        cout << ptr[i] << ' ';
    cout << endl;
}

enum class Letters {AA, BB, CC, DD};

ostream& operator<<(ostream& os, const Letters& l){
    switch(l){
        case Letters::AA;
        os << "AA";
        break;
        case Letters::BB
        os << "BB";
        break;
        case Letters::CC
        os << "CC";
        break;
        case Letters::DD
        os << "DD";
        break;
        default
        os << "Valore non valido";
        break;
    }
}