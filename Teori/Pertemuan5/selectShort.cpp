#include <iostream>

using namespace std;

void selectionSort(int arr[], int a){
    for (int i = 0; i < a-1; i++){
        int min = i;
        for (int j = i+1; j < a; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[min], arr[i]);
        cout << "Langkah " << i+1 << ": ";
        for (int k = 0; k < a; k++){
            cout << arr[k] << " ";
        } cout << endl;
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

    selectionSort(arr, n);

    cout << "Array Setelah Diurutkan: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}