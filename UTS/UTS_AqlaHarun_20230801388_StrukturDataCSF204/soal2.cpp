#include <iostream>
#include <string>
#include <map>

using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

string formatPrice(double price) {
    string reversedResult = "";
    string priceStr = to_string((int)price);
    int counter = 0;

    for (int i = priceStr.length() - 1; i >= 0; i--) {
        counter++;
        reversedResult += priceStr[i];
        if (counter % 3 == 0 && i != 0) {
            reversedResult += '.';
        }
    }

    string result(reversedResult.rbegin(), reversedResult.rend());
    return result;
}

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

void displayProducts(Product products[], int n, map<string, double> prices) {
    cout << "Products:\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << products[i].name << " (indeks ke-" << i << "), Harga: Rp. " << formatPrice(prices[products[i].name]) << endl;
    }
}

int main() {
    Product products[] = {{"Processor"}, {"RAM"}, {"SSD"}, {"VGA"}, {"Monitor"}};
    map<string, double> prices = {{"Processor", 800000}, {"RAM", 650000}, {"SSD", 400000}, {"VGA", 3500000}, {"Monitor", 1250000}};
    int n = sizeof(products) / sizeof(products[0]);

    int choice;
    do {
        clearScreen();
        cout << "\nMenu:\n";
        cout << "1. Display Products (Unsorted)\n";
        cout << "2. Display Products (Sorted) & Searching Product\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();
                clearScreen();
                displayProducts(products, n, prices); // display unsorted products

                cout << endl << "Press any key to continue...";
                getchar();
                break;

            case 2:
                clearScreen();
                bubbleSort(products, n); // sort products
                displayProducts(products, n, prices); // display sorted products

                cout << endl;
                {
                string target;
                cout << "Enter product name: ";
                cin.ignore();
                getline(cin, target);
                int index = binarySearch(products, 0, n - 1, target);
                if (index != -1) {
                    cout << "'" << target << "' found at index " << index << endl;
                } else {
                    cout << "'" << target << "' not found" << endl;
                }
                }

                cout << endl << "Press any key to continue...";
                getchar();
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