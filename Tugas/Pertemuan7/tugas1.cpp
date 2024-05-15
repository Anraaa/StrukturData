#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    while (true) {
        int n;
        cout << "Masukkan Panjang Array : ";
        cin >> n;

        if (n == 0) {
            break;
        }

        int arr[n];
        cout << "Masukkan elemen-elemen array" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Element ke-" << i + 1 << ": ";
            cin >> arr[i];
        }

        bubbleSort(arr, n);

        cout << "Array Setelah Diurutkan: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    return 0;
}