#include <iostream>
using namespace std ;

// pseudocodenya belum 

int Cari_Min(int A[], int n, int &index_Min) {
    int min = A[0] ;
    index_Min = 0 ;

    for (int i = 1 ; i < n ; i++) {
        if (A[i] < min) {
            min = A[i] ; 
            index_Min = i;
        }
    }
    return min ;
}

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21} ;
    int index_Min ;

    int Minimum = Cari_Min(A, 9, index_Min) ;

    cout << "Nilai Minimum : " << Minimum << endl ;
    cout << "Index Minimum : " << index_Min << endl ;

    return 0 ;

}

/*

=====================================================
|                 Pseudocode + Cost                 |
=====================================================
| No.|  Pseudocode              | Cost | Tmin | Tmax |
-----------------------------------------------------
| 1. | min =A[0]               | 1    | 1    | 1    |
| 2. | index_Min = 0           | 1    | 1    | 1    |
| 3. | loop (i = 1 to n-1)     | 1    | n-1  | n-1  |
| 4. | if A[i] < min           | 1    | n-1  | n-1  |
| 5. | min = A[i]              | 1    | 0    | n-1  |
| 6. | index_Min = i           | 1    | 0    |n-1   |
| 7. | return min              | 1    | 1    | 1    |
=====================================================

Analisis :
` Best Case (Tmin)  : Terjadi ketika elemen pertama adalah nilai minimum, yaitu pada kondisi "if A[i] < min" selalu False dan nilai min tidak pernah berubah. Kompleksitasnya adalah O(n).
` Worst Case (Tmax) : Terjadi ketika elemen baru selalu lebih kecil dari nilai min namun program tetap berjalan hingga akhir dan  pada kondisi "if A[i] < min" selalu TRUE. Kompleksitasnya adalah 0(n).

Kesimpulannya : Kompleksitas waktu linear terhadap jumlah elemen array. Karena pada Best case maupun Worst case, program berjalan hingga akhir.


*/