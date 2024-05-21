#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
};

int binarySearch(Product arr[], int left, int right, string target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].name == target)
            return mid;

        if (arr[mid].name < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

void bubbleSort(Product arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].name > arr[j + 1].name) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void displayProducts(Product products[], int n) {
    cout << "Products:\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << products[i].name << " (indeks ke-" << i << ")" << endl;
    }
}

int main() {
    Product products[] = {{"Processor"}, {"RAM"}, {"SSD"}, {"VGA"}, {"Monitor"}};
    int n = sizeof(products) / sizeof(products[0]);

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

    return 0;
}