#include <iostream>
#include <string>
using namespace std;

int binarySearch(string* arr[], int left, int right, string target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (*arr[mid] == target)
            return mid;

        if (*arr[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

void bubbleSort(string* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*arr[j] > *arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void displayProducts(string* products[], int n) {
    cout << "Products:\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << *products[i] << " (indeks ke-" << i << ")" << endl;
    }
}

int main() {
    int n = 5;
    string* products[n];
    products[0] = new string("Processor");
    products[1] = new string("RAM");
    products[2] = new string("SSD");
    products[3] = new string("VGA");
    products[4] = new string("Monitor");

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display Products (Unsorted)\n";
        cout << "2. Display Products (Sorted) & Searching Product\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayProducts(products, n); // display unsorted products
                break;

            case 2:
                bubbleSort(products, n); // sort products
                displayProducts(products, n); // display sorted products

                cout << endl;
                {
                string target;
                cout << "Enter product name: ";
                cin >> target;
                int index = binarySearch(products, 0, n - 1, target);
                if (index != -1) {
                    cout << "'" << target << "' found at index " << index << endl;
                } else {
                    cout << "'" << target << "' not found" << endl;
                }
                }
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
                break;
        }
    } while (choice != 3);

    // Don't forget to delete allocated memory
    for (int i = 0; i < n; i++) {
        delete products[i];
    }

    return 0;
}