### Operasi 5: Cek Jumlah Buku
```cpp
else if (operation == "5") {
    clearScreen();
    cout << "Jumlah buku dalam stack: " << bookStack.size() << endl;
    notif();
}
```

Jika pengguna memilih operasi "5" (`else if (operation == "5")`), maka kode berikut akan dijalankan:

- `clearScreen();`: Membersihkan layar. Fungsi ini biasanya digunakan untuk membuat tampilan program lebih rapi.

- `cout << "Jumlah buku dalam stack: " << bookStack.size() << endl;`: Menampilkan jumlah buku dalam tumpukan buku (`bookStack`).

- `notif();`: Memanggil fungsi `notif()` yang mungkin menampilkan notifikasi tertentu.