#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Membuat struct untuk barang 
struct Barang {
    string nama;
    int jumlah;
    double harga;
};

// Membuat vector untuk menyimpan stock barang 
vector<Barang> stock;

// Fungsi untuk menambah stock barang
void tambahBarang(string nama, int jumlah, double harga) {
    Barang barangBaru;
    barangBaru.nama = nama;
    barangBaru.jumlah = jumlah;
    barangBaru.harga = harga;
    stock.push_back(barangBaru);
}

// Fungsi untuk mencetak barang yang tersedia
void cetakBarang() {
    cout << left << setw(20) << "Nama Barang" << setw(10) << "Jumlah" << setw(10) << "Harga" << endl;
    for (const auto &barang : stock) {
        cout << left << setw(20) << barang.nama << setw(10) << barang.jumlah << setw(10) << barang.harga << endl;
    }
}

// Fungsi untuk mengupdate jumlah barang
void updateJumlahBarang(string nama, int jumlahBaru) {
    for (auto &barang : stock) {
        if (barang.nama == nama) {
            barang.jumlah = jumlahBaru;
            cout << "Jumlah barang " << nama << " telah diupdate.\n";
            return;
        }
    }
    cout << "Notifikasi: Barang dengan nama " << nama << " tidak tersedia di database.\n";
}

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

int main() {
    int pilihan;
    string nama;
    int jumlah;
    double harga;

    do {
        clearScreen();
        cout << "Menu:\n";
        cout << "1. Input barang\n";
        cout << "2. Cetak stok\n";
        cout << "3. Update jumlah barang\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                clearScreen();
                cout << "Masukkan nama barang: ";
                getline(cin, nama);
                cout << "Masukkan jumlah barang: ";
                cin >> jumlah;
                cout << "Masukkan harga per barang: ";
                cin >> harga;
                cin.ignore();
                tambahBarang(nama, jumlah, harga);
                clearScreen();
                break;
            case 2:
                clearScreen();
                cetakBarang();
                cout << "\nPress enter to continue... ";
                getchar();
                break;
            case 3:
                clearScreen();
                cout << "Masukkan nama barang yang ingin diupdate: ";
                getline(cin, nama);
                cout << "Masukkan jumlah barang baru: ";
                cin >> jumlah;
                cin.ignore();
                updateJumlahBarang(nama, jumlah);
                clearScreen();
                break;
            case 4:
                clearScreen();
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 4);

    return 0;
}