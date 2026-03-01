#include <iostream>
using namespace std ;

struct Mahasiswa {
    string Nama ; 
    string NIM ;
    float IPK ;
} ;

int main() {
    Mahasiswa mhs [5] ;

    for (int i = 0 ; i < 5 ; i++) {

        cout << "Mahasiswa ke- " << i+1 << endl ;
        cout << "Nama : " << endl ;
        cin >> mhs[i].Nama ;
        cout << "Nim : " << endl;
        cin >> mhs[i].NIM ;
        cout << "IPK : " << endl ;
        cin >> mhs[i].IPK ;
        cout << endl ;
    }

    int index_Max = 0 ;

    for (int i = 1 ; i < 5 ; i++) {
        if (mhs[i].IPK > mhs[index_Max].IPK) {
            index_Max = i ;
        }
    }

    cout << "Mahasiswa dengan IPK tertinggi : " ;
    cout << "Nama : " << mhs[index_Max].Nama << endl ;
    cout << "NIM : " << mhs[index_Max].NIM << endl ;
    cout << "IPK : " << mhs[index_Max].IPK << endl ;

    return 0 ;

}