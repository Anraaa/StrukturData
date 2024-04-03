#include <iostream>
using namespace std;

void clearScreen(){
    cout << "Klik Enter Untuk Lanjut";
    getchar();
    system("clear");
}

int main() {
    char nama[4][5][22][23] = {
        {{"Rifky", "Destian", "Vienie", "Andre", "Mia"},
         {"Della", "Vanya", "Vio", "Indri", "Nilna"},
         {"Hakim", "Bagus", "Firman", "Amin", "Awan"},
         {"Ramdhan", "Gilang", "Lingga", "Rizky", "Kevin"}},

        {{"Nama1", "Nama2", "Nama3", "Nama4", "Nama5"},
         {"Nama6", "Nama7", "Nama8", "Nama9", "Nama10"},
         {"Nama11", "Nama12", "Nama13", "Nama14", "Nama15"},
         {"Nama16", "Nama17", "Nama18", "Nama19", "Nama20"}},
    };

    int i, s;
    char h = 'A';

    cout << "Daftar Nama Kelompok: \n";
    for (int kelompok = 0; kelompok < 4; kelompok++) {
        cout << "Kelompok " << h++;

        for (int nama_ke = 0; nama_ke < 5; nama_ke++) {
            cout << "\n";
            for (int indeks_karakter = 0; nama[kelompok][nama_ke][indeks_karakter][0] != '\0'; indeks_karakter++) {
                cout << nama[kelompok][nama_ke][indeks_karakter];
            }
        }
        cout << "\n";
    }

    clearScreen();
}
