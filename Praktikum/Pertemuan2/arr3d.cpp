// Array Dimensi 3
#include <iostream>
using namespace std;

void clearScreen(){
    cout << "Klik Enter Untuk Lanjut";
    getchar();
    system("clear");
}

int main() {
    system("clear");
    int i, s;
    char h = 'A';
    char nama [4][5][22] = {
        {"Rifky", "Destian", "Vienie", "Andre", "Mia"},
        {"Della", "Vanya", "Vio", "Indri", "Nilna"},
        {"Hakim", "Bagus", "Firman", "Amin", "Awan"},
        {"Ramdhan", "Gilang", "Lingga", "Rizky", "Kevin"} };

    cout << "Daftar Nama Kelompok: \n";
    for (i = 0; i < 4; i++) {
        cout << "Kelompok " << h++;
        for (s = 0; s < 5; s++) {
            cout << "\n\t" << s + 1 << ". " << nama[i][s];
        }
        cout << "\n";
    }
    cout << endl;
    clearScreen();
}
