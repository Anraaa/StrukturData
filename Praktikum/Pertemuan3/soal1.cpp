#include <iostream>
#include <string>
using namespace std;

struct Buku {
    string judul;
    string pengarang;
    int tahun;
};

int main(){
    Buku buku1;
    Buku buku2;

    cout << "================================" << endl;
    buku1.judul = "Bima Sang Anak Pengembala";
    buku1.pengarang = "Bima";
    buku1.tahun = 2024;

    cout << "Judul Buku: " << buku1.judul << endl;
    cout << "Pengarang : " << buku1.pengarang << endl;
    cout << "Tahun Terbit : " << buku1.tahun << endl;

    cout << "================================" << endl;
    buku2.judul = "Petualangan Jares Mencari Naga Hitam";
    buku2.pengarang = "Jares";
    buku2.tahun = 2025;

    cout << "Judul Buku : " << buku2.judul << endl;
    cout << "Pengarang : " << buku2.pengarang << endl;
    cout << "Tahun Terbit : " << buku2.tahun << endl;

    return 0;
}