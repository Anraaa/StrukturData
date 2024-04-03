// Array Dimensi 2
#include <iostream>
#include <cstdlib>
using namespace std;

void clearScreen(){
    cout << "Klik Enter Untuk Lanjut";
    getchar();
}

int main (){
    int arr[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    system ("clear");
    cout << "Contoh Array Dimensi 2 (dua):" << endl;
    for (int i = 0; i < 4; i++) { // looping untuk baris
        for (int j = 0; j < 3; j++) { // looping untuk kolom
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    clearScreen();

    return 0;
}