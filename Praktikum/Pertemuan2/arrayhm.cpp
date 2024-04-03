#include <iostream>
#include <cstdlib>
using namespace std;

void clearScreen(){
    cout << "Klik Enter Untuk Lanjut";
    getchar();
}

int main (){
    int arr[5] = {10, 20, 30, 40, 50};

    system ("clear");
    cout << "Contoh Array dengan tipe data yang sama : ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i];
        if (i < 4) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << endl;
    clearScreen();

    return 0;
}