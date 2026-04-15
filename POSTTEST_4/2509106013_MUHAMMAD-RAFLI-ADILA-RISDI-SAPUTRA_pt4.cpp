# include <iostream>
using namespace std ;

struct Node {
    int ID_Hewan ;
    string Jenis_Hewan ;
    string Ras_Hewan ;
    char Jenis_Kelamin_Hewan ;
    int Harga_Hewan ;
    Node* next ;
};

// Untuk database utama
Node* Head_Data = NULL ;

// Untuk Queue (Antrian)
Node* Front = NULL ;
Node* Rear = NULL ;

// Untuk stack (riwayat)
Node* Top = NULL ;

int Pilihan_Menu_Utama ;
bool Program_Jalan = true ;
bool ID_Sama = false ;

// Insert Last, karena saya menggunakan fibonacci search yang membutuhkan data yang sudah terurut
void Tambah_Data_Ke_Database (int ID, string Jenis, string Ras, char Gender, int Harga) {
    Node* Baru = new Node ;
    Baru->ID_Hewan = ID ;
    Baru->Jenis_Hewan = Jenis ;
    Baru->Ras_Hewan = Ras ;
    Baru->Jenis_Kelamin_Hewan = Gender ;
    Baru->Harga_Hewan = Harga ;
    Baru->next = NULL ;

    if (Head_Data == NULL) {
        Head_Data = Baru ;
    } else {
        Node* Temp = Head_Data ;

        while (Temp->next != NULL) {
            Temp = Temp->next ;
        }

        Temp->next = Baru ;
    }

}

// ----------------------------------------
// Antri periksa
bool Antri_Kosong() {
    return Front == NULL ;
}

// Nambah antrian ke belakang antrian (enqueue)
void Nambah_Antri(int Value) {
    system("cls") ; 

    Node* Baru = new Node ;
    Baru->ID_Hewan = Value ;
    Baru->next = NULL ;

    if (Antri_Kosong()) {
        Front = Baru ;
        Rear = Baru ;
    } else {
        Rear->next = Baru ;
        Rear = Baru ;
    }

    cout << Value << " Berhasil menambahkan pasien ke antrian" << endl ;
    system("cls") ;
}

// Riwayat tindakan (Stack) (push)
void Push(int Value) {
    system("cls") ; 

    Node* Baru = new Node ;
    Baru->ID_Hewan = Value ;

    Baru->next = Top ;
    Top = Baru ;

    cout << Value << " Berhasil menambahkan ke antrian ! " << endl ;
    system("cls") ;
}

// Panggil pasien (Dequeue)
int Panggil_Pasien() {
    system("cls") ; 

    if (Antri_Kosong()) {
        cout << "Antrian kosong" << endl ;
        system("pause") ;
        return -1 ;
    }

    Node* Temp = Front ;
    int Value = Temp->ID_Hewan ;
    Front = Front->next ;

    if (Antri_Kosong()) {
        Rear = NULL ;
    }

    delete Temp ;
    Push(Value) ;
    cout << "Pasien ID : " << Value << " dipanggil periksa." << endl ;

    system("pause") ;
    return Value ;
}

// Pop riwayat batal ataau hapus tindakan terakhir
int Pop() {
    system("cls") ; 

    if (Top == NULL ) {
        cout << "Riwayat kosong" << endl ;
        system("pause") ;
        return -1 ;
    }

    Node* Temp = Top ;
    int Value = Temp->ID_Hewan ;
    Top = Top->next ;
    delete Temp ;

    cout << "Berhasil menghapus ID " << Value << " dari riwayat. " << endl ;
    system("pause") ;
    return Value ;
}

// Tampilkan pasien terdepan dan antiran dan tindakan terakhir
void Peek() {
    system("cls") ; 

    if (Antri_Kosong()) {
        cout << "Antrian kosong" << endl ;
        system("pause") ;
    } 
    else {
        cout << "Pasien Terdepan : " <<     Front->ID_Hewan << endl ;
    }

    if (Top == NULL) {
        cout << "Belum ada riwayat ! " << endl ;
    } 
    else {
        cout << "Tindakan Terakhir : " << Top->ID_Hewan << endl ;
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

    Node* Temp = Front ;
    cout << "Daftar antrian : " ;
    
    while (Temp != NULL) {
        cout << Temp->ID_Hewan << " -> " ;
        Temp = Temp->next ;
    }

    cout << "NULL " << endl ;
    system("pause") ;
}

// Tampil semua riwayat  
void Tampil_Riwayat() {
    system("cls") ; 

    if (Top == NULL) {
        cout << "Riwayat kosong" << endl ;
        system("pause") ;
        return ;
    }

    Node* Temp = Top ;
    cout << "Riwayat Tindakan : " << endl ;
    
    while (Temp != NULL) {
        cout << "| ID : " << Temp->ID_Hewan << " | " << endl ;
        Temp = Temp->next ;
    }
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

void Tampil_Data (Node* Head_Data) { // C
    system("cls") ; 

    if (Head_Data == NULL) {
        cout << "Belum ada Data Hewan " << endl ;
    } else {
        Node* Temp = Head_Data ;
        int i = 1 ;
        
        while (Temp != NULL) {
            cout << "=================================== " << endl ;
            cout << "       Daftar Data Hewan " << endl ;
            cout << "=================================== " << endl ;
            cout << "No. : " << i++ << endl ;
            cout << "ID : " << Temp->ID_Hewan << endl ;
            cout << "Jenis : " << Temp->Jenis_Hewan << endl ;
            cout << "Ras : " << Temp->Ras_Hewan << endl ;
            cout << "Jenis Kelamin : " << Temp->Jenis_Kelamin_Hewan << endl ;
            cout << "Harga : " << Temp->Harga_Hewan << endl ;
            cout << "=================================== " << endl ;

            Temp = Temp->next ;
        }
        
    }

    system("pause") ;
}

void Tambah_Data () { // R

    int ID_Baru  ;
    string Jenis_Baru ;
    string Ras_Baru ;
    char Gender_Baru ;
    int Harga_Baru ;

    system("cls") ; 
    
    cout << "Masukan ID hewan baru : " ; cin >> ID_Baru ;

    Node* Temp = Head_Data ;
    while (Temp != NULL ) {
        if (Temp->ID_Hewan == ID_Baru) {
            cout << "ID Sudah ada ! " << endl  ;
            return ;
        }

        Temp = Temp->next ;
    }

    cout << "Masukan Jenis hewan baru : " ; cin >> Jenis_Baru ;
    cout << "Masukan Ras hewan baru : " ; cin.ignore() ; getline(cin, Ras_Baru) ; Ras_Baru ;
    cout << "Masukan Jenis Kelamin Hewan baru (L/P): " ; cin >> Gender_Baru ;
    cout << "Masukan Harga hewan baru (Masukan hanya angka tanpa koma atau titik !) : " ;  cin >> Harga_Baru ;

    Tambah_Data_Ke_Database(ID_Baru, Jenis_Baru, Ras_Baru, Gender_Baru, Harga_Baru) ;

    cout << "Hewan berhasil di tambahkan ke data !" << endl ;
    system("pause") ;
}

void Swap (Node* a, Node* b) {
    int Temp_ID = a->ID_Hewan ;
    string Temp_Jenis = a->Jenis_Hewan ;
    string Temp_Ras = a->Ras_Hewan ;
    char Temp_Gender = a->Jenis_Kelamin_Hewan ;
    int Temp_Harga = a->Harga_Hewan ;

    a->ID_Hewan = b->ID_Hewan ;
    a->Jenis_Hewan = b->Jenis_Hewan ;
    a->Ras_Hewan = b->Ras_Hewan ;
    a->Jenis_Kelamin_Hewan = b->Jenis_Kelamin_Hewan ;
    a->Harga_Hewan = b->Harga_Hewan ;

    b->ID_Hewan = Temp_ID ;
    b->Jenis_Hewan = Temp_Jenis ;
    b->Ras_Hewan = Temp_Ras ;
    b->Jenis_Kelamin_Hewan = Temp_Gender ;
    b->Harga_Hewan = Temp_Harga ;
}

void Linear_Search () {
    system("cls") ;
    string Target ;

    cout << "Masukkan Nama Jenis hewan yang dicari (Contoh : Kucing, Anjing, dll) : " << endl ; cin.ignore() ; getline(cin, Target) ;

    Node* Temp = Head_Data ;
    bool Ketemu_Linear = false ;
    int i = 1 ;

    while (Temp != NULL ) {
        if (Temp->Jenis_Hewan == Target) {
            
            cout << "Data Ditemukan !" << endl ;
            cout << "=================================== " << endl ;
            cout << "Index ke -" << i++  << " Ditemukan !" << endl ; 
            cout << "ID : " << Temp->ID_Hewan << endl ;
            cout << "Jenis : " << Temp->Jenis_Hewan << endl ;
            cout << "Ras : " << Temp->Ras_Hewan << endl ;
            cout << "Jenis Kelamin : " << Temp->Jenis_Kelamin_Hewan << endl ;
            cout << "Harga : " << Temp->Harga_Hewan << endl ;

            cout << "=================================== " << endl ;

            Ketemu_Linear = true ;
        }
        Temp = Temp->next ;
    }

    if (!Ketemu_Linear) {
        cout << "Data tidak ditemukan !" << endl ;
    }

    system("pause") ;
}

int Fibonacci_Search (int Target) {
    int n = 0 ;
    Node* Temp_Hitung = Head_Data ;
    while (Temp_Hitung != NULL) {
        n++ ;
        Temp_Hitung = Temp_Hitung->next ;
    }

    if (n == 0) return -1 ;

    Node** Temp_Array = new Node*[n] ;
    Node* Temp_Isi = Head_Data ;

    for (int j = 0 ; j < n ; j++) {
        Temp_Array[j] = Temp_Isi ;
        Temp_Isi = Temp_Isi->next ;
    }
// Logika fibbonaci
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
    int Iterasi = 1 ;

    while (Fib > 1) {

        int i = min(Offset + Fib_2, n - 1) ;

        cout <<"Iterasi ke- " << Iterasi++ << " | Indeks ke- : " << i << endl ; 


        if (Temp_Array[i]->ID_Hewan  == Target) {
            cout << " ID ditemukan pada index ke - " << i << endl ;
            delete[] Temp_Array ;
            return i ;
        }
        else if (Temp_Array[i]->ID_Hewan < Target) {
            Fib = Fib_1 ;
            Fib_1 = Fib_2 ; 
            Fib_2 = Fib - Fib_1 ;
            Offset = i ;
        }
        else {
            Fib = Fib_2 ;
            Fib_1 = Fib_1- Fib_2 ; 
            Fib_2 = Fib - Fib_1 ;
        }
    }
    
    if (Fib_1 && Temp_Array[Offset + 1]->ID_Hewan  == Target) {
        delete[] Temp_Array ;
        return Offset + 1 ;     
    }

    delete[] Temp_Array ;
    return -1 ; 
}

void Cari_ID () {
    system("cls") ;
    int Target ;

    cout << "Masukan ID yang dicari : " ; cin >> Target ;

    int Hasil_Indeks = Fibonacci_Search(Target) ;

    if (Hasil_Indeks != -1) {
        Node* Temp = Head_Data ;

        for (int i = 0 ; i < Hasil_Indeks ; i++) {
            Temp = Temp->next ;
        }

        cout << "Data ditemukan !" << endl ;
        cout << "=================================== " << endl ;

        cout << "ID : " << Temp->ID_Hewan << endl ;
        cout << "Jenis : " << Temp->Jenis_Hewan << endl ;
        cout << "Ras : " << Temp->Ras_Hewan << endl ;
        cout << "Jenis Kelamin : " << Temp->Jenis_Kelamin_Hewan << endl ;
        cout << "Harga : " << Temp->Harga_Hewan << endl ;

        cout << "=================================== " << endl ;

    } else {
        cout << "Data tidak ditemukan ! " << endl ;
    }

    system("pause") ;
}

void Bubble_Sort () {
    bool Swapped = true ;
    Node* ptr1 ;
    Node* lptr = NULL ;

    system("cls") ;
    
    if (Head_Data == NULL) return ;

    while (Swapped) {
    Swapped = false ;
    ptr1 = Head_Data ;

    while (ptr1->next != lptr) {
        if (ptr1->Jenis_Hewan > ptr1->next->Jenis_Hewan) {
            Swap (ptr1, ptr1->next) ;
            Swapped = true ;
            }

        ptr1 = ptr1->next ;
        }

        lptr = ptr1 ;
    }
    

    cout << "Data berhasil di urutkan ! " << endl ;
    system("pause") ; 
}

void Selection_Sort () {

    if (Head_Data == NULL) return ;

    system("cls") ;
    Node* i = Head_Data ;

    while (i != NULL) {
        Node* Min_Node = i ;
        Node* j = i->next ;
        
        while (j != NULL) {
            if(j->Harga_Hewan < Min_Node->Harga_Hewan) {
                Min_Node = j ;
            }
            j = j->next ;
        }

        if (Min_Node != i) {
            Swap(i, Min_Node) ;
        }

        i = i->next ;
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
                Linear_Search () ;
                break ;

            case 2 :          // FIBONACCI SEARCH   
                Cari_ID () ;
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
                Bubble_Sort () ;
                break ;

            case 2 :          // SELECTION SORT  
                Selection_Sort () ;
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
    Tambah_Data_Ke_Database (101, "Kucing", "Persia", 'P', 2500000) ;
    Tambah_Data_Ke_Database (102, "Kucing", "British ShortHair", 'L', 9500000) ;
    Tambah_Data_Ke_Database (103, "Anjing", "Siberian Husky", 'L', 10999000) ;
    Tambah_Data_Ke_Database (104, "Kucing", "Anggora", 'P', 3500000) ;
    Tambah_Data_Ke_Database (105, "Anjing", "Golden Retriever", 'P', 5300000) ;
    Tambah_Data_Ke_Database (106, "Kucing", "Persia", 'L', 27000000) ;
    Tambah_Data_Ke_Database (107, "Kucing", "Ragdoll", 'L', 9000000) ;
    Tambah_Data_Ke_Database (108, "Kucing", "Sphynx", 'P', 15000000) ;
    Tambah_Data_Ke_Database (109, "Anjing", "Siberian Husky", 'P', 15000000) ;
    Tambah_Data_Ke_Database (110, "Anjing", "Pomeranian", 'P', 7500000) ;
    Tambah_Data_Ke_Database (111, "Anjing", "Beagle", 'L', 8500000) ;
    Tambah_Data_Ke_Database (112, "Anjing", "Chihuahua", 'P', 3500000) ;
    Tambah_Data_Ke_Database (113, "Kucing", "Bengal", 'L', 25500000) ;

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

    Node*head=nullptr;

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
            Tampil_Data (Head_Data) ;
            break ;

        case 2 :          // TAMBAH DATA   
            Tambah_Data () ;
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

