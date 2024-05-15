#include <iostream>
using namespace std;

void displayArray(int* arr, int size) {
    cout << "Nilai-nilai array: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int calculateTotal(int* arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += *(arr + i);
    }
    return total;
}

int findMaximum(int* arr, int size) {
    int maximum = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > maximum) {
            maximum = *(arr + i);
        }
    }
    return maximum;
}

int findMinimum(int* arr, int size) {
    int minimum = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) < minimum) {
            minimum = *(arr + i);
        }
    }
    return minimum;
}

void sortArrayAscending(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

void sortArrayDescending(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) < *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    int size;
    cout << "Masukkan ukuran array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Masukkan nilai-nilai array" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element ke-" << i + 1 << ": ";
        cin >> *(arr + i);
    }

    displayArray(arr, size);

    cout << endl;

    int total = calculateTotal(arr, size);
    cout << "Total nilai dalam array: " << total << endl;

    int maximum = findMaximum(arr, size);
    cout << "Nilai maksimum dalam array: " << maximum << endl;

    int minimum = findMinimum(arr, size);
    cout << "Nilai minimum dalam array: " << minimum << endl;

    cout << endl;

    cout << "Array setelah diurutkan (ascending): ";
    sortArrayAscending(arr, size);
    displayArray(arr, size);

    cout << "Array setelah diurutkan (descending): ";
    sortArrayDescending(arr, size);
    displayArray(arr, size);

    delete[] arr;

    return 0;
}