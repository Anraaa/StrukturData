#include <iostream>

using namespace std;

// Kelas Node untuk menyimpan data dan pointer ke node berikutnya
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Kelas SingleLinkedList untuk mengelola operasi-operasi pada linked list
class SingleLinkedList {
private:
    Node* head;

public:
    SingleLinkedList() {
        head = nullptr;
    }

    // Menyisipkan data di depan linked list
    void insertDepan(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Menyisipkan data di tengah linked list pada posisi tertentu
    void insertTengah(int data, int posisi) {
        if (posisi == 0) {
            insertDepan(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* current = head;
        int count = 0;

        while (current != nullptr && count < posisi - 1) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Menyisipkan data di belakang linked list
    void insertBelakang(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = newNode;
    }

    // Menghapus data dari depan linked list
    void deleteDepan() {
        if (head == nullptr) {
            cout << "List kosong, tidak ada yang dihapus!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Menghapus data dari tengah linked list pada posisi tertentu
    void deleteTengah(int posisi) {
        if (head == nullptr) {
            cout << "List kosong, tidak ada yang dihapus!" << endl;
            return;
        }

        if (posisi == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        int count = 0;

        while (current != nullptr && count < posisi - 1) {
            current = current->next;
            count++;
        }

        if (current == nullptr || current->next == nullptr) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Menghapus data dari belakang linked list
    void deleteBelakang() {
        if (head == nullptr) {
            cout << "List kosong, tidak ada yang dihapus!" << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* secondLast = head;
        while (secondLast->next->next != nullptr) {
            secondLast = secondLast->next;
        }

        delete secondLast->next;
        secondLast->next = nullptr;
    }

    // Menampilkan seluruh data dalam linked list
    void tampilkanData() {
        if (head == nullptr) {
            cout << "List kosong!" << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "None" << endl;
    }
};

int main() {
    SingleLinkedList sll;
    char pilihan;
    int data, posisi;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Insert Depan" << endl;
        cout << "2. Insert Tengah" << endl;
        cout << "3. Insert Belakang" << endl;
        cout << "4. Delete Depan" << endl;
        cout << "5. Delete Tengah" << endl;
        cout << "6. Delete Belakang" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Keluar" << endl;

        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                cout << "Masukkan data: ";
                cin >> data;
                sll.insertDepan(data);
                break;
            case '2':
                cout << "Masukkan data: ";
                cin >> data;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                sll.insertTengah(data, posisi);
                break;
            case '3':
                cout << "Masukkan data: ";
                cin >> data;
                sll.insertBelakang(data);
                break;
            case '4':
                sll.deleteDepan();
                break;
            case '5':
                cout << "Masukkan posisi: ";
                cin >> posisi;
                sll.deleteTengah(posisi);
                break;
            case '6':
                sll.deleteBelakang();
                break;
            case '7':
                sll.tampilkanData();
                break;
            case '8':
                cout << "Keluar dari program." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
}