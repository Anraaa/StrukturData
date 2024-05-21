#include <iostream>

using namespace std;

void bubbleSort(int arr[], int a){
    bool swapped;
    for (int i = 0; i < a-1; i++){
        swapped = false;
        for (int j = 0; j < a-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            cout << "Langkah" << i+1 << ", Iterasi ke-" << j+1 << ": ";
            for (int k = 0; k < a; k++){
                cout << arr[k] << " ";
            } cout << endl;
        }
        
        cout << endl;
        if (swapped == false){
            break;
        }
    }
}

int main()
{
    int arr[] = {5, 3, 1, 7, 6, 2, 4, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Array Sebelum Diurutkan: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    bubbleSort(arr, n);

    cout << "Array Setelah Diurutkan: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}