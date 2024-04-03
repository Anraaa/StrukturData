#include <iostream>
using namespace std;

enum KategoriProduk {Elektronik, Pakaian, Makanan, Perabotan, Mainan};

struct Barang {
    string nama_barang;
    string kode_barang;
    string jenis_barang;
    KategoriProduk kategori;
    float harga_barang;
};

void inputDataBarang(Barang &barang){
    cout << "Masukkan Nama Barang: ";
    getline(cin, barang.nama_barang);

    cout << "Masukkan Kode Barang: ";
    cin >> barang.kode_barang;

    cin.ignore();
    cout << "Masukkan Jenis Barang: ";
    getline(cin, barang.jenis_barang);

    cout << "Pilih Kategori Produk (0: Elektronik, 1: Pakaian, 2: Makanan, 3: Perabotan, 4: Mainan): ";
    int pilihan;
    cin >> pilihan;
    barang.kategori = static_cast<KategoriProduk>(pilihan);

    cout << "Masukkan Harga Barang: ";
    cin >> barang.harga_barang;

    cin.ignore();
}

void tampilkanDataBarang(const Barang &barang){
    string kategoriProduk[] = {"ELEKTRONIK", "PAKAIAN", "MAKANAN", "PERABOTAN", "MAINAN"};

    cout << "Nama Barang: " << barang.nama_barang << endl;
    cout << "Kode Barang: " << barang.kode_barang << endl;
    cout << "Jenis Barang: " << barang.jenis_barang << endl;
    cout << "Kategori Produk: " << kategoriProduk[barang.kategori] << endl;
    cout << "Harga Barang: " << barang.harga_barang << endl;
}

int main(){
    char lanjutInput;
    int counter = 1;
    do{
        cout << "\e[1;1H\e[2J";
        Barang barang;
        cout << "========== Mengisi Data Barang ke-" << counter << " ==========" << endl;
        inputDataBarang(barang);

        cout << "========== Data Barang Yang Sudah Diisi ==========" << endl;
        tampilkanDataBarang(barang);

        cout << "Apakah Anda ingin memasukkan data untuk barang lain? (y/n): ";
        cin >> lanjutInput;

        cin.ignore();
        counter++;
    } while (lanjutInput == 'y' || lanjutInput == 'Y');

    cout << "Program selesai. Terima kasih!" << endl;

    return 0;
}