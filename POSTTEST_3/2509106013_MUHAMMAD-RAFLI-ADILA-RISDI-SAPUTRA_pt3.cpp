# include <iostream>
using namespace std ;

struct Data_Hewan {
    int ID_Hewan ;
    string Jenis_Hewan ;
    string Ras_Hewan ;
    char Jenis_Kelamin_Hewan ;
    int Harga_Hewan ;
};

# define MAX_Hewan 15 
int Panjang_Data = 0 ;
Data_Hewan DH [MAX_Hewan] ;

int Pilihan_Menu_Utama ;
bool Program_Jalan = true ;
bool ID_Sama = false ;

// ----------------------------------------
// Antri periksa
# define MAX_Antri 15
int Antri[MAX_Antri] ;

int front = -1, rear = -1; 

bool Antri_Full() {
    return rear == MAX_Antri - 1 ;
}

bool Antri_Kosong() {
    return front == -1 || front > rear ;
}

// Nambah antrian ke belakang antrian (enqueue)
void Nambah_Antri(int Value) {
    system("cls") ; 

    if (Antri_Full()) {
        cout << "Antrian Penuh" << endl ;
        system("pause") ;
        return ;
    }

    if (front == -1) {
        front = 0 ;
    }

    rear++ ; 
    *(Antri + rear) = Value  ;
    cout << Value << " Berhasil menambahkan pasien ke antrian" << endl ;

}

// Riwayat tindakan (Stack) (push)
# define MAX_Riwayat 15
int Stack[MAX_Riwayat] ;
int Top = -1 ;

void Push(int Value) {
    system("cls") ; 

    if (Top >= MAX_Antri - 1) {
        cout << "Antrian penuh !" << endl ;
        system("pause") ;
    }
    else {
        Top++ ;
        Stack[Top] = Value ;

        cout << Value << " Berhasil menambahkan ke antrian ! " << endl ;
    }
}

// Panggil pasien (dequeue)
int Panggil_Pasien() {
    system("cls") ; 

    if (Antri_Kosong()) {
        cout << "Antrian kosong" << endl ;
        system("pause") ;
        return -1 ;
    }

    int Value = *(Antri + front) ;
    front++ ;

    Push(Value) ;
    
    if (Antri_Kosong()) {
        front = rear = -1 ;
    }
    return Value ;
    system("pause") ;
}


// Pop riwayat batal ataau hapus tindakan terakhir
int Pop() {
    system("cls") ; 

    if (Top < 0) {
        cout << "Riwayat kosong" << endl ;
        system("pause") ;
        return -1 ;
    }
    else {
        int Value = Stack[Top] ;
        Top-- ;
        return Value ;
    }
    system("pause") ;
}

// Tampilkan pasien terdepan dan antiran dan tindakan terakhir
void Peek() {
    system("cls") ; 

    if (Antri_Kosong()) {
        cout << "Antrian kosong" << endl ;
        system("pause") ;
    } 
    else {
        cout << "Pasien Terdepan : " << *(Antri + front) << endl ;
    }

    if (Top != -1) {
        cout << "Tindakan Terakhir : " << *(Stack + Top) << endl ;
    } 
    else {
        cout << "Belum ada riwayat ! " << endl ;
    }
    
    system("pause") ;      
    }

// Tampilkan semua antrian 
void Tampil_Antrian() {
    system("cls") ; 

    if (Antri_Kosong()) {
        cout << "Antrian kosong" << endl ;
        system("pause") ;
        return ;
    }

    cout << "Daftar antrian : " ;
    
    for (int i = front; i <= rear; i++) {
        cout << *(Antri + i) << " ";
    }

    cout << endl ;

    system("pause") ;
}

// Tampil semua riwayat  
void Tampil_Riwayat() {
    system("cls") ; 

    if (Top == -1) {
        cout << "Riwayat kosong" << endl ;
        system("pause") ;
        return ;
    }

    cout << "Riwayat Tindakan : " << endl ;
    
    for (int i = Top ; i >= 0 ; i--) {
        cout << "| ID : "<< *(Stack + i) << " |" << endl;
    }

    cout << endl ;
    system("pause") ;
}


void Menu_Tampilkan_Klinik () {

    int Pilihan_Tampil ;
    bool Menu_Tampilkan_Klinik = true ;

    while (Menu_Tampilkan_Klinik) {
        system("cls") ;

        cout << "=================================== " << endl ;
        cout << "        DATA KLINIK PAWLUXE " << endl ;
        cout << "===================================  " << endl ;
        cout << " 1. Lihat Antrian Saat Ini " << endl ;
        cout << " 2. Lihat Riwayat Selesai  " << endl ;
        cout << " 3. Lihat Pasien Terdepan & Terbelakang  " << endl ;
        cout << " 4. Kembali ke Menu Klinik " << endl ;
        cout << "-----------------------------------" << endl ; 
        cout << "Pilih (1-4) : " << endl ;
        cin >> Pilihan_Tampil ;

        switch (Pilihan_Tampil) {
            case 1 :        // Queue
                Tampil_Antrian() ;
                break ;

            case 2 :       // Stack
                Tampil_Riwayat() ;
                break ;

            case 3 :      // Peek     
                Peek() ;
                break ;

            case 4 :     // KEMBALI KE MENU UTAMA
                Menu_Tampilkan_Klinik = false ;
                break ;
            
            default : 
                system("cls") ; 
                cout << "Pilihan Salah !" << endl ; 
                system("pause") ;
                break ; 
        } 
    }
}

void Klinik_Pawluxe () {

    int Pilihan_Menu_Klinik ;
    bool Menu_Klinik = true ;
    int ID_Input ; 

    while (Menu_Klinik) {
        system("cls") ;

        cout << "=================================== " << endl ;
        cout << "          KLINIK PAWLUXE " << endl ;
        cout << "===================================  " << endl ;
        cout << " 1. Tambah Antrian  " << endl ;
        cout << " 2. Panggil Pasien untuk di periksa  " << endl ;
        cout << " 3. Batal / Hapus riwayat terakhir  " << endl ;
        cout << " 4. Tampil Antrian & Riwayat  " << endl ;
        cout << " 5. Kembali ke menu utama " << endl ;
        cout << "-----------------------------------" << endl ; 
        cout << "Pilih (1-5) : " << endl ;
        cin >> Pilihan_Menu_Klinik ;

        switch (Pilihan_Menu_Klinik) {
            case 1 :        
                system("cls") ;
                cout << "Masukan ID Hewan untuk Antri : " ; cin >> ID_Input ;
                Nambah_Antri(ID_Input) ;
                system("pause") ;
                break ;

            case 2 :            
                Panggil_Pasien() ;
                system("pause") ;
                break ;

            case 3 :           
                Pop() ;
                system("pause") ;
                break ;

            case 4 :          
                Menu_Tampilkan_Klinik() ;
                break ;

            case 5 :           // KEMBALI KE MENU UTAMA
                Menu_Klinik = false ;
                break ;
            
            default : 
                system("cls") ; 
                cout << "Pilihan Salah !" << endl ; 
                system("pause") ;
                break ; 
        } 

    }
}

void Tampil_Data (Data_Hewan DH[], int Panjang_Data) { // C

    ID_Sama = false ;

    system("cls") ; 
    if (Panjang_Data == 0) {
        cout << "Belum ada Data Hewan " << endl ;
    } else {
        cout << "=================================== " << endl ;
        cout << "       Daftar Data Hewan " << endl ;
        cout << "=================================== " << endl ;

        for (int i = 0 ; i < Panjang_Data ; i++) {
            cout << "No. : " << i + 1 << endl ;
            cout << "ID : " << (DH + i)->ID_Hewan << endl ;
            cout << "Jenis : " << (DH + i)->Jenis_Hewan << endl ;
            cout << "Ras : " << (DH + i)->Ras_Hewan << endl ;
            cout << "Jenis Kelamin : " << (DH + i)->Jenis_Kelamin_Hewan << endl ;
            cout << "Harga : " << (DH + i)->Harga_Hewan << endl ;

            cout << "=================================== " << endl ;
        } 
    }

    system("pause") ;
}

void Tambah_Data (Data_Hewan DH[], int &Panjang_Data) { // R

    ID_Sama = false ;
    system("cls") ; 
    
    if (Panjang_Data < MAX_Hewan) {
        cout << "Masukan ID hewan baru : " ;
        cin >> DH[Panjang_Data].ID_Hewan ;

        for (int i = 0 ; i < Panjang_Data ; i++) {
            if (DH[i].ID_Hewan == DH[Panjang_Data].ID_Hewan ) {
                ID_Sama = true ;
                break ;
            }
        }

        if (ID_Sama) {
            cout << "ID Sudah ada ! " << endl  ;
            system("pause") ;
        } else {

            cout << "Masukan Jenis hewan baru : " ;
            cin >> DH[Panjang_Data].Jenis_Hewan ;
            
            cout << "Masukan Ras hewan baru : " ;
            cin.ignore() ;
            getline(cin, DH[Panjang_Data].Ras_Hewan) ;

            cout << "Masukan Jenis Kelamin Hewan baru (L/P): " ;
            cin >> DH[Panjang_Data].Jenis_Kelamin_Hewan ;

            cout << "Masukan Harga hewan baru (Masukan hanya angka tanpa koma atau titik !) : " ;
            cin >> DH[Panjang_Data].Harga_Hewan ;

            Panjang_Data++ ;

            cout << "Hewan berhasil di tambahkan ke data !" << endl ;
            system("pause") ;

        }

    } else {
        cout << "Data hewan sudah penuh !" << endl ;
        system("pause") ;
    }
}

void Swap (Data_Hewan *a, Data_Hewan *b) {
    Data_Hewan Temp = *a ;
    *a = *b ;
    *b = Temp ;
}

void Linear_Search (Data_Hewan DH[], int n) {
    system("cls") ;
    string Target ;

    cout << "Masukkan Nama Jenis hewan yang dicari (Contoh : Kucing, Anjing, dll) : " << endl ;
    cin.ignore() ;
    getline(cin, Target) ;

    bool Ketemu_Linear = false ;

    for (int i = 0 ; i < n ; i++) {
        if ((DH + i)->Jenis_Hewan == Target) {

            cout << "Data Ditemukan !" << endl ;
            cout << "=================================== " << endl ;
            cout << "No. : " << i + 1 << endl ;
            cout << "ID : " << (DH + i)->ID_Hewan << endl ;
            cout << "Jenis : " << (DH + i)->Jenis_Hewan << endl ;
            cout << "Ras : " << (DH + i)->Ras_Hewan << endl ;
            cout << "Jenis Kelamin : " << (DH + i)->Jenis_Kelamin_Hewan << endl ;
            cout << "Harga : " << (DH + i)->Harga_Hewan << endl ;

            cout << "=================================== " << endl ;

            Ketemu_Linear = true ;
            

        }
    }

    if (!Ketemu_Linear) {
        cout << "Data tidak ditemukan !" << endl ;
    }

    system("pause") ;
}

int Fibonacci_Search (Data_Hewan DH[], int n, int Target) {
    // Variabel
    int Fib_2 = 0 ; 
    int Fib_1 = 1 ; 
    int Fib = Fib_1 + Fib_2 ;

    
    while (Fib < n) {
        Fib_2 = Fib_1 ;
        Fib_1 = Fib ;
        Fib = Fib_1 + Fib_2 ;
        
    }

    int Offset = -1 ; // BATAS KIRI

    while (Fib > 1) {

        int i ;
        if (Offset + Fib_2 < n - 1)
            i = Offset + Fib_2 ;

        else
            i = n - 1 ;

        cout << "Cek Index ke- : " << i <<  endl ;

        if ((DH + i)->ID_Hewan == Target) 
            return i ;

        else if ((DH + i)->ID_Hewan < Target) {
            // KE KANAN
            Fib = Fib_1 ;
            Fib_1 = Fib_2 ;
            Fib_2 = Fib - Fib_1 ;
            Offset = i ;

        } else {
            // KE KIRI
            Fib = Fib_2 ;
            Fib_1 = Fib_1 - Fib_2 ;
            Fib_2 = Fib - Fib_1 ;
        }
    
    }


    if (Fib_1 && (DH + Offset + 1)->ID_Hewan  == Target)
        return Offset + 1 ;

return -1 ; 
}

void Cari_ID (Data_Hewan DH[], int n) {
    system("cls") ;
    int Target ;

    cout << "Masukan ID yang dicari : " ;
    cin >> Target ;

    int Hasil = Fibonacci_Search(DH, n, Target) ;

    if (Hasil != -1) { 
        cout << "Data ditemukan !" << endl ;
        cout << "=================================== " << endl ;

        cout << "ID : " << (DH + Hasil)->ID_Hewan << endl ;
        cout << "Jenis : " << (DH + Hasil)->Jenis_Hewan << endl ;
        cout << "Ras : " << (DH + Hasil)->Ras_Hewan << endl ;
        cout << "Jenis Kelamin : " << (DH + Hasil)->Jenis_Kelamin_Hewan << endl ;
        cout << "Harga : " << (DH + Hasil)->Harga_Hewan << endl ;

        cout << "=================================== " << endl ;
        system("pause") ; 
        
    } else {
        cout << "Data tidak ditemukan !" << endl ;
        system("pause") ; 
    }
}

void Bubble_Sort (Data_Hewan DH[], int n) {
    system("cls") ;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n - i - 1 ; j++) {
            if ((DH + j)->Jenis_Hewan > (DH + j + 1)->Jenis_Hewan) {
                Swap(DH + j, DH + j + 1) ;
            }
        }
    }

    cout << "Data berhasil di urutkan ! " << endl ;
    system("pause") ; 
}

void Selection_Sort (Data_Hewan DH[], int n) {
    system("cls") ;

    for (int i = 0 ; i < n ; i++) {
        int Min = i ;
        for (int j = i + 1 ; j < n ; j++) {
            if ((DH + j)->Harga_Hewan < (DH + Min)->Harga_Hewan) {
                Min = j ;
            }
        }
        Swap(DH + i, DH + Min) ;
    }

    cout << "Data Berhasil diurutkan ! " << endl ;
    system("pause") ; 
}

void Cari () {
    int Pilihan_Menu_Cari ;
    bool Menu_Cari = true ;

    while (Menu_Cari) {
        system("cls") ;

        cout << "=================================== " << endl ;
        cout << "            SEARCH " << endl ;
        cout << "===================================  " << endl ;
        cout << " 1. Cari dengan Nama  " << endl ;
        cout << " 2. Cari dengan ID " << endl ;
        cout << " 3. Kembali ke menu utama " << endl ;
        cout << "-----------------------------------" << endl ; 
        cout << "Pilih (1-3) : " << endl ;
        cin >> Pilihan_Menu_Cari ;

        switch (Pilihan_Menu_Cari) {
            case 1 :        // LINEAR SEARCH
                Linear_Search (DH, Panjang_Data) ;
                break ;

            case 2 :          // FIBONACCI SEARCH   
                Cari_ID (DH, Panjang_Data) ;
                break ;

            case 3 :           // KEMBALI KE MENU UTAMA
                Menu_Cari = false ;
                break ;
            
            default : 
                system("cls") ; 
                cout << "Pilihan Salah !" << endl ; 
                system("pause") ;
                break ; 
        } 

    }
}

void Urut () {
    int Pilihan_Menu_Urut ;
    bool Menu_Urut =  true ; 

    while (Menu_Urut) {
        system("cls") ;

        cout << "=================================== " << endl ;
        cout << "             SORT " << endl ;
        cout << "===================================  " << endl ;
        cout << " 1. Urut berdasarkan Nama dari (A-Z) " << endl ;
        cout << " 2. Urut berdasarkan Harga dari (Murah ke Mahal) " << endl ;
        cout << " 3. Kembali ke menu utama " << endl ;
        cout << "-----------------------------------" << endl ; 
        cout << "Pilih (1-3) : " << endl ;
        cin >> Pilihan_Menu_Urut ;

        switch (Pilihan_Menu_Urut) {
            case 1 :        // BUBBLE SORT
                Bubble_Sort (DH, Panjang_Data) ;
                break ;

            case 2 :          // SELECTION SORT  
                Selection_Sort (DH, Panjang_Data) ;
                break ;

            case 3 :           // KEMBALI KE MENU UTAMA
                Menu_Urut = false ;
                break ;
            
            default : 
                system("cls") ; 
                cout << "Pilihan Salah !" << endl ; 
                system("pause") ;
                break ; 
        } 

    }
}

int main () {

    // Data Hewan
    DH [0] = {101, "Kucing", "Persia", 'P', 2500000} ;
    DH [1] = {102, "Kucing", "British ShortHair", 'L', 9500000} ;
    DH [2] = {103, "Anjing", "Siberian Husky", 'L', 10999000} ;
    DH [3] = {104, "Kucing", "Anggora", 'P', 3500000} ;
    DH [4] = {105, "Anjing", "Golden Retriever", 'P', 5300000} ;
    DH [5] = {106, "Kucing", "Persia", 'L', 2700000} ;
    DH [6] = {107, "Kucing", "Ragdoll", 'L', 9000000} ;
    DH [7] = {108, "Kucing", "Sphynx", 'P', 15000000} ;
    DH [8] = {109, "Anjing", "Siberian Husky", 'P', 15000000} ;
    DH [9] = {110, "Anjing", "Pomeranian", 'P', 7500000} ;
    DH [10] = {111, "Anjing", "Beagle", 'L', 8500000} ;
    DH [11] = {112, "Anjing", "Chihuahua", 'P', 3500000} ;
    DH [12] = {113, "Kucing", "Bengal", 'L', 25500000} ;

    Panjang_Data = 13 ;

    // Data Antrian
    Nambah_Antri(102) ;
    Nambah_Antri(103) ;
    Nambah_Antri(106) ;
    Nambah_Antri(101) ;
    Nambah_Antri(113) ;
    Nambah_Antri(112) ;
    Nambah_Antri(111) ;

    // Data Riwayat Tindakan
    Push(109) ;

while (Program_Jalan) {
    system("cls") ;

    cout << "=================================== " << endl ;
    cout << "    SELAMAT DATANG DI PAWLUXE ! " << endl ;
    cout << "===================================  " << endl ;
    cout << " 1. Tampilkan Seluruh Data Hewan " << endl ;
    cout << " 2. Tambah Data Hewan " << endl ;
    cout << " 3. Search " << endl ;
    cout << " 4. Sort " << endl ;
    cout << " 5. Layanan Klinik " << endl ;
    cout << " 6. EXIT " << endl ;
    cout << "-----------------------------------" << endl ; 
    cout << "Pilih (1-6) : " << endl ;
    cin >> Pilihan_Menu_Utama ;

    switch (Pilihan_Menu_Utama) {
        case 1 :        // TAMPILKAN DATA
            Tampil_Data (DH, Panjang_Data) ;
            break ;

        case 2 :          // TAMBAH DATA   
            Tambah_Data (DH, Panjang_Data) ;
            break ;

        case 3 :          // SEARCH
            Cari();
            break ; 

        case 4 :            // SORT
            Urut();
            break ; 
        
        case 5 :            // Klinik
            Klinik_Pawluxe();
            break ; 

        case 6 :           // EXIT
            system("cls") ;
            Program_Jalan = false ;
            break ;
        
        default : 
            system("cls") ; 
            cout << "Pilihan Salah !" << endl ; 
            system("pause") ;
            break ; 
    } 

    
}

if (!Program_Jalan) {
    cout << "Terima kasih sudah menggunakan program !" ;
}
    return 0 ;
}

