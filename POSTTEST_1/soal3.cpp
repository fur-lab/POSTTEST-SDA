#include <iostream>
using namespace std ;

void Reverse_Array (int* arr, int n) {

    int* Awal =  arr ;
    int* Akhir = arr + n - 1 ;

    while (Awal < Akhir) {
        int Sementara = *Awal ;
        *Awal = *Akhir ;
        *Akhir = Sementara ;

        Awal++ ;
        Akhir-- ;
    }
} 

int main() {
    int arr [7] = {2, 3, 5, 7, 11, 13, 17} ;

    cout << "Sebelum dibalik : \n" ;

    for (int i = 0 ; i < 7 ; i++) {
        cout << arr[i] << " " ;
        
    }

    Reverse_Array (arr, 7) ;

    cout << "\n \nSesudah dibalik : \n" ;

    for (int i = 0 ; i < 7 ; i++) {
        cout << arr[i] << " " ;
    }

    cout << "\n \nAlamat memori setiap elemen : \n" ;

    for (int i = 0 ; i < 7 ; i++) {
        cout << &arr[i] << endl ;
    }
    
    return 0 ;
}