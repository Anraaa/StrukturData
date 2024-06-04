#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* frontList = nullptr;
Node* middleList = nullptr;
Node* backList = nullptr;

void insertFront(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = frontList;
    frontList = node;
}

void insertMiddle(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = middleList;
    middleList = node;
}

void insertBack(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = backList;
    backList = node;
}

void deleteFront() {
    if (frontList == nullptr) {
        cout << "Node depan kosong." << endl;
        return;
    }

    Node* temp = frontList;
    frontList = frontList->next;
    delete temp;
}

void deleteMiddle() {
    if (middleList == nullptr) {
        cout << "Node tengah kosong." << endl;
        return;
    }

    Node* temp = middleList;
    middleList = middleList->next;
    delete temp;
}

void deleteBack() {
    if (backList == nullptr) {
        cout << "Node belakang kosong." << endl;
        return;
    }

    Node* temp = backList;
    backList = backList->next;
    delete temp;
}

void display(Node* node, const char* label) {
    cout << label << ": ";
    while (node != nullptr) {
        cout << node->data;
        if (node->next != nullptr) {
            cout << ", ";
        }
        node = node->next;
    }
    if (strcmp(label, "Node belakang") == 0) {
        cout << " -> NULL" << endl;
    } else {
        cout << " -> " << endl;
    }
}

int main() {
    char menu;
    int data;
    do {
        cout << "Menu:\na. Insert node depan\nb. Insert node tengah\nc. Insert node belakang\nd. Delete node\ne. Tampilkan data\nf. Keluar\nPilih menu: ";
        cin >> menu;
        switch (menu) {
            case 'a':
                cout << "Masukkan nilai: ";
                cin >> data;
                insertFront(data);
                break;
            case 'b':
                cout << "Masukkan nilai: ";
                cin >> data;
                insertMiddle(data);
                break;
            case 'c':
                cout << "Masukkan nilai: ";
                cin >> data;
                insertBack(data);
                break;
            case 'd':
                char deleteMenu;
                cout << "Menu delete:\n1. Delete node depan\n2. Delete node tengah\n3. Delete node belakang\nPilih menu delete: ";
                cin >> deleteMenu;
                switch (deleteMenu) {
                    case '1':
                        deleteFront();
                        break;
                    case '2':
                        deleteMiddle();
                        break;
                    case '3':
                        deleteBack();
                        break;
                    default:
                        cout << "Pilihan delete tidak valid." << endl;
                        break;
                }
                break;
            case 'e':
                display(frontList, "Node depan");
                display(middleList, "Node tengah");
                display(backList, "Node belakang");
                break;
            case 'f':
                cout << "Keluar." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (menu != 'f');

    return 0;
}
