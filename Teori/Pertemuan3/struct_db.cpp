#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float ipk;
};

int main(){
    Mahasiswa mhs1;
    Mahasiswa mhs2;

    cout << "\e[1;1H\e[2J";
    cout << "============================="<< endl;
    mhs1.nim = "20230801151";
    mhs1.nama = "hanz";
    mhs1.ipk = 3.75;

    cout << "NIM: " << mhs1.nim << endl;
    cout << "Nama: " << mhs1.nama << endl;
    cout << "IPK: " << mhs1.ipk << endl;

    cout << "============================="<< endl;
    mhs2.nim = "20230801151";
    mhs2.nama = "hanz2";
    mhs2.ipk = 3.85;

    cout << "NIM: " << mhs2.nim << endl;
    cout << "Nama: " << mhs2.nama << endl;
    cout << "IPK: " << mhs2.ipk << endl;

    return 0;
}