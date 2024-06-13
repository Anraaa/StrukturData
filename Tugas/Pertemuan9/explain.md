### Header dan Namespace
```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;
```
<div style="text-align: justify;">
Bagian ini adalah inklusi header. <code>iostream</code> digunakan untuk operasi input dan output, <code>stack</code> adalah library yang menyediakan fungsi stack, dan <code>string</code> digunakan untuk operasi string. <code>using namespace std;</code> digunakan untuk menghindari penulisan std:: sebelum setiap penggunaan fungsi atau objek dari namespace std.
</div>

___
### Fungsi clearScreen
```cpp
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}
```

<div style="text-align: justify;">
Fungsi <code>clearScreen()</code> digunakan untuk membersihkan layar terminal. Fungsi ini mencetak dua kode escape ANSI ke terminal: <br>
<li><code>\033[2J</code>: Kode ini digunakan untuk membersihkan seluruh layar terminal. <code>\033[</code> adalah awalan untuk kode escape ANSI, dan <code>2J</code> adalah kode untuk membersihkan layar.</li>
<li><code>\033[1;1H</code>: Kode ini digunakan untuk memindahkan kursor ke posisi awal (baris 1, kolom 1) di layar terminal. <code>1;1H</code> adalah kode untuk memindahkan kursor ke posisi tertentu.</li>
</div>

___
### Fungsi isDigit
```cpp
void isDigit(const string& operation) {
    if (operation.length() != 1 || !isdigit(operation[0])) {
        throw invalid_argument("Input Salah. Silahkan Input 1-5 Saja");
    }
}
```
Fungsi `isDigit()` digunakan untuk memeriksa apakah input pengguna adalah digit tunggal. Jika bukan, fungsi ini akan melempar pengecualian `invalid_argument.`
> Untuk penjelasan lebih lanjut [klik disini](/Tugas/Pertemuan9/all/full-exp-1.md)
___
### Fungsi notif
```cpp
void notif(){
    cout << endl;
    cout << "Tekan Enter Untuk Melanjutkan...";
}
```
Fungsi `notif()` digunakan untuk memberikan notifikasi kepada pengguna untuk menekan Enter untuk melanjutkan.
___
### Fungsi Main
```cpp
int main() {
    stack<string> bookStack;
    string operation;
``` 
Fungsi `main()` adalah titik masuk program. `bookStack` adalah stack yang digunakan untuk menyimpan buku, dan `operation` adalah variabel yang digunakan untuk menyimpan operasi yang dipilih pengguna.
> Untuk penjelasan lebih lanjut [klik disini](/Tugas/Pertemuan9/all/full-exp-2.md)
___
### Menu Utama
```cpp
while (true) {
    clearScreen();
    cout << "Menu:" << endl;
    cout << "1. Tambah Buku (push)" << endl;
    cout << "2. Hapus Buku (pop)" << endl;
    cout << "3. Daftar Buku Paling Atas (peek)" << endl;
    cout << "4. Cek Stok Buku (isEmpty)" << endl;
    cout << "5. Cek Jumlah Buku (size)" << endl;
```
Bagian ini adalah menu utama program. Pengguna dapat memilih operasi yang ingin dilakukan.
`while (true)` adalah sebuah loop yang akan berjalan terus menerus sampai ada perintah untuk menghentikannya. `true` di sini adalah kondisi loop, dan karena kondisinya selalu `true`, loop ini akan berjalan tanpa henti.
___
### Validasi Input
```cpp
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
```
Bagian ini digunakan untuk memvalidasi input pengguna. Jika input tidak valid, program akan menampilkan pesan kesalahan dan meminta pengguna untuk memasukkan input lagi.
___
### Operasi 1: Tambah Buku
```cpp
if (operation == "1") {
    string book;
    clearScreen();
    cout << "Masukkan judul buku: ";
    cin.ignore();
    getline(cin, book);
    bookStack.push(book);
    cout << "Buku berhasil ditambahkan ke dalam stack." << endl;
    notif();
}
```
Jika pengguna memilih operasi 1, program akan meminta pengguna untuk memasukkan judul buku, lalu menambahkannya ke dalam stack. Setelah itu, program akan memberi notifikasi bahwa buku telah berhasil ditambahkan.
___
### Operasi 2: Hapus Buku
```cpp
else if (operation == "2") {
    clearScreen();
    if (!bookStack.empty()) {
        bookStack.pop();
        cout << "Buku berhasil dihapus dari stack." << endl;
    } else {
        cout << "Stack buku kosong." << endl;
    }
    notif();
}
```
Jika pengguna memilih operasi 2, program akan menghapus buku paling atas dari stack. Jika stack kosong, program akan memberi tahu pengguna bahwa tidak ada buku untuk dihapus.
___
### Operasi 3: Daftar Buku Paling Atas
```cpp
else if (operation == "3") {
    clearScreen();
    if (!bookStack.empty()) {
        cout << "Judul buku paling atas: " << bookStack.top() << endl;
    } else {
        cout << "Stack buku kosong." << endl;
    }
    notif();
}
```
Jika pengguna memilih operasi 3, program akan menampilkan judul buku paling atas di stack. Jika stack kosong, program akan memberi tahu pengguna bahwa tidak ada buku di stack.
___
### Operasi 4: Cek Stok Buku
```cpp
else if (operation == "4") {
    clearScreen();
    if (bookStack.empty()) {
        cout << "Stack buku kosong." << endl;
    } else {
        cout << "Stack buku tidak kosong." << endl;
    }
    notif();
}
```
Jika pengguna memilih operasi 4, program akan memeriksa apakah stack kosong atau tidak. Program akan menampilkan pesan yang sesuai berdasarkan kondisi stack.
___
### Operasi 5: Cek Jumlah Buku
```cpp
else if (operation == "5") {
    clearScreen();
    cout << "Jumlah buku dalam stack: " << bookStack.size() << endl;
    notif();
}
```
Jika pengguna memilih operasi 5, program akan menampilkan jumlah buku yang ada di stack.
___
### Akhir Program
```cpp
return 0;
}
```
Fungsi `main()` mengembalikan 0, yang menandakan bahwa program berakhir dengan sukses.

