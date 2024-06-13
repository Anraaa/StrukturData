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

Jika pengguna memilih operasi "4" (`else if (operation == "4")`), maka kode berikut akan dijalankan:

- `clearScreen();`: Membersihkan layar. Fungsi ini biasanya digunakan untuk membuat tampilan program lebih rapi.

- `if (bookStack.empty())`: Mengecek apakah tumpukan buku (`bookStack`) kosong atau tidak. Jika kosong, maka kode berikutnya akan dijalankan.

- `cout << "Stack buku kosong." << endl;`: Menampilkan pesan bahwa tumpukan buku kosong.

Jika tumpukan buku tidak kosong (`else`), maka kode berikut akan dijalankan:

- `cout << "Stack buku tidak kosong." << endl;`: Menampilkan pesan bahwa tumpukan buku tidak kosong.

Setelah itu, kode berikut akan dijalankan:

- `notif();`: Memanggil fungsi `notif()` yang mungkin menampilkan notifikasi tertentu.