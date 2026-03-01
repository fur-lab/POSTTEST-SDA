#include <iostream>
using namespace std ;

void Tukar (int* a, int* b) {
    int Sementara = *a ;
    *a = *b ;
    *b = Sementara ;
}

int main() {
    int x, y;

    cout <<"Masukan nilai x : ";
    cin >> x ;
    cout <<"Masukan nilai y : ";
    cin >> y ;

    cout << "\nSebelum ditukar : \n" ;
    cout << "x : " << x << endl ;
    cout << "y : " << y << endl ;

    Tukar(&x, &y) ;

    cout << "\nSesudah ditukar : \n" ;
    cout << "x : " << x << endl ;
    cout << "y : " << y << endl ;

    return 0 ;
}