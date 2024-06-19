#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Pasien {
    string nama;
    int NomorAntrian;
};

int main(){
    queue<Pasien> antrian;
    int nomorAntrianTerakhir = 0;

    while (true){
        cout << "Menu:\n";
        cout << "1. Tambah Pasien\n";
        cout << "2. Panggil Pasien\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";

        int pilihan;
        cin >> pilihan;

        if (pilihan == 1){
            Pasien pasienBaru;
            cout << "Nama: ";
            cin >>pasienBaru.nama;
            nomorAntrianTerakhir++;
            pasienBaru.NomorAntrian = nomorAntrianTerakhir;
            antrian.push(pasienBaru);
            cout << "Pasien berhasil ditambahkan.\n";
        } else if (pilihan == 2){
            if (!antrian.empty()){
                Pasien pasienDipanggil = antrian.front();
                antrian.pop();
                cout << "Pasien dipanggil: " << pasienDipanggil.nama << " (Nomor " << pasienDipanggil.NomorAntrian << ")\n";
            } else {
                cout << "Antrian kosong.\n";
            }
        } else if (pilihan == 3){
            if (antrian.empty()){
                cout << "Antrian kosong.\n";
            } else {
                cout << "Daftar Antrian:\n";
                queue<Pasien> temp = antrian;
                while (!temp.empty()){
                    Pasien pasien = temp.front();
                    temp.pop();
                    cout << "- " << pasien.nama << " (Nomor " << pasien.NomorAntrian << ")\n";
                }
            }
        } else if (pilihan == 4){
            cout << "Keluar dari aplikasi.\n";
            break;
        } else {
            cout << "Pilihan tidak valid.\n";
        }
        
    }

    return 0;
}
