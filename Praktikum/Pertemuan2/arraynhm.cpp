#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    string Nama [5] = {"marseks", "virseks", "jarseks", "bimseks", "balseks"};

    system ("clear");
    cout << "============================" << endl;
    cout << "Array dengan tipe data berbeda : " << endl;

    cout << "Menampilkan tipe data int" << endl;
    cout << "Elemen-elemen array: ";
    for (int i = 0; i < 5;i++){
        cout << numbers[i] << ", ";
    }
    cout << endl;

    cout <<"=============================" << endl;
    cout <<"Menampilkan tipe data string" << endl;
    cout <<"Elemen-elemen array: ";
    for (int i = 0; i < 5; i++){
        cout << Nama[i] << ", ";
    }
    cout << endl;

    return 0;
}