#include <iostream>
#include <stack>
#include <string>

using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void isDigit(const string& operation) {
    if (operation.length() != 1 || !isdigit(operation[0])) {
        throw invalid_argument("Input Salah. Silahkan Input 1-5 Saja");
    }
}

void notif(){
    cout << endl;
    cout << "Tekan Enter Untuk Melanjutkan...";
}

int main() {
    stack<string> bookStack;
    string operation;

    while (true) {
        clearScreen();
        cout << "Menu:" << endl;
        cout << "1. Tambah Buku (push)" << endl;
        cout << "2. Hapus Buku (pop)" << endl;
        cout << "3. Daftar Buku Paling Atas (peek)" << endl;
        cout << "4. Cek Stok Buku (isEmpty)" << endl;
        cout << "5. Cek Jumlah Buku (size)" << endl;
        
        bool validInput = false;
        while (!validInput) {
            try {
                cout << "Pilih operasi (1-5): ";
                cin >> operation;
                isDigit(operation);
                validInput = true;
            } catch (invalid_argument& e) {
                cout << e.what() << endl;
            }
        }

        if (operation == "1") {
            string book;
            //getchar();
            clearScreen();
            cout << "Masukkan judul buku: ";
            cin.ignore();
            getline(cin, book);
            bookStack.push(book);
            cout << "Buku berhasil ditambahkan ke dalam stack." << endl;
            //getchar();
            notif();
        } else if (operation == "2") {
            getchar();
            clearScreen();
            if (!bookStack.empty()) {
                bookStack.pop();
                cout << "Buku berhasil dihapus dari stack." << endl;
            } else {
                cout << "Stack buku kosong." << endl;
            }
            getchar();
            notif();
        } else if (operation == "3") {
            getchar();
            clearScreen();
            if (!bookStack.empty()) {
                cout << "Judul buku paling atas: " << bookStack.top() << endl;
            } else {
                cout << "Stack buku kosong." << endl;
            }
            getchar();
            notif();
        } else if (operation == "4") {
            getchar();
            clearScreen();
            if (bookStack.empty()) {
                cout << "Stack buku kosong." << endl;
            } else {
                cout << "Stack buku tidak kosong." << endl;
            }
            getchar();
            notif();
        } else if (operation == "5") {
            getchar();
            clearScreen();
            cout << "Jumlah buku dalam stack: " << bookStack.size() << endl;
            getchar();
            notif();
        } else {
            cout << "Operasi tidak valid." << endl;
        }
    }

    return 0;
}