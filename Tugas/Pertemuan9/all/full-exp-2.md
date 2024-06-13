### Fungsi Main
```cpp
int main() {
    stack<string> bookStack;
    string operation;
``` 
Fungsi `main()` ini adalah titik masuk utama program. Di dalam fungsi ini, kita mendeklarasikan dua variabel: `bookStack` dan `operation`.

1. `stack<string> bookStack;`: Ini adalah deklarasi dari sebuah stack (tumpukan) yang berisi string. Stack adalah struktur data yang mengikuti prinsip "Last In, First Out" (LIFO). Artinya, elemen yang terakhir ditambahkan ke stack akan menjadi elemen pertama yang diambil dari stack. Dalam konteks ini, `bookStack` bisa digunakan untuk menyimpan daftar buku, di mana buku yang terakhir ditambahkan ke stack adalah buku yang pertama akan diambil dari stack.

2. `string operation;`: Ini adalah deklarasi dari sebuah string bernama `operation`. String ini bisa digunakan untuk menyimpan operasi yang ingin dilakukan pengguna, seperti menambahkan buku ke stack atau mengambil buku dari stack.
