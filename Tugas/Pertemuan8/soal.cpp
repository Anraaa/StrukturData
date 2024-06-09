#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertFront(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertMiddle(int data, int position) {
    if (head == nullptr) {
        cout << "List kosong. Tidak dapat memasukkan di posisi tengah." << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = data;

    Node* current = head;
    int count = 1;

    while (count < position - 1 && current->next != nullptr) {
        current = current->next;
        count++;
    }

    if (count < position - 1) {
    cout << "Posisi tengah tidak valid." << endl;
    return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void insertBack(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

void deleteFront() {
    if (head == nullptr) {
        cout << "List kosong. Tidak dapat menghapus dari depan." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteMiddle(int position) {
    if (head == nullptr) {
        cout << "List kosong. Tidak dapat menghapus dari posisi tengah." << endl;
        return;
    }

    Node* current = head;
    int count = 1;

    while (count < position - 1 && current != nullptr) {
        current = current->next;
        count++;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Posisi tengah tidak valid." << endl;
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

void deleteBack() {
    if (head == nullptr) {
        cout << "List kosong. Tidak dapat menghapus dari belakang." << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

void display() {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    Node* current = head;
    cout << "Data: ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        } else {
            cout << " -> NULL";
        }
        current = current->next;
    }
    cout << endl;
}

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

int main() {
    int menu, submenu, data, position;
    do {
        clearScreen();
        cout << "Menu:\n1. Insert\n2. Delete\n3. Keluar\nPilih menu: ";
        cin >> menu;

        switch (menu) {
            case 1:
                do {
                    clearScreen();
                    cout << "1. Insert Depan\n2. Insert Tengah\n3. Insert Belakang\n4. Tampilkan\n5. Kembali\nPilih submenu: ";
                    cin >> submenu;
                    if (submenu == 5) break;
                    if (submenu == 4){
                        getchar();
                        display();
                        cout << endl;
                        cout << "Tekan enter untuk kembali.";
                        getchar();
                    } else {
                        cout << "Masukkan nilai: ";
                        cin >> data;
                        if (submenu == 1) {
                            insertFront(data);
                        } else if (submenu == 2) {
                            cout << "Masukkan posisi: ";
                            cin >> position;
                            insertMiddle(data, position);
                        } else if (submenu == 3) {
                            insertBack(data);
                        } else {
                            cout << "Pilihan tidak valid." << endl;
                        }
                    }
                } while (submenu != 5);
                break;
            case 2:
                do {
                    clearScreen();
                    cout << "1. Delete Depan\n2. Delete Tengah\n3. Delete Belakang\n4. Tampilkan\n5. Kembali\nPilih submenu: ";
                    cin >> submenu;
                    if (submenu == 5) break;
                    if (submenu == 4){
                        getchar();
                        display();
                        cout << endl;
                        cout << "Tekan enter untuk kembali.";
                        getchar();
                    } else {
                        if (submenu == 1) {
                            deleteFront();
                        } else if (submenu == 2) {
                            cout << "Masukkan posisi: ";
                            cin >> position;
                            deleteMiddle(position);
                        } else if (submenu == 3) {
                            deleteBack();
                        } else {
                            cout << "Pilihan tidak valid." << endl;
                        }
                    }
                } while (submenu != 5);
                break;
            case 3:
                cout << "Keluar." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (menu != 3);

    return 0;
}