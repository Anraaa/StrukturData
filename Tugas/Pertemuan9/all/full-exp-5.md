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

Jika pengguna memilih operasi "2" (`else if (operation == "2")`), maka kode berikut akan dijalankan:

- `clearScreen();`: Membersihkan layar. Fungsi ini biasanya digunakan untuk membuat tampilan program lebih rapi.

- `if (!bookStack.empty())`: Mengecek apakah tumpukan buku (`bookStack`) kosong atau tidak. Jika tidak kosong, maka kode berikutnya akan dijalankan.

- `bookStack.pop();`: Menghapus buku teratas dari tumpukan buku (`bookStack`).

- `cout << "Buku berhasil dihapus dari stack." << endl;`: Menampilkan pesan bahwa buku telah berhasil dihapus.

Jika tumpukan buku kosong (`else`), maka kode berikut akan dijalankan:

- `cout << "Stack buku kosong." << endl;`: Menampilkan pesan bahwa tumpukan buku kosong.

Setelah itu, kode berikut akan dijalankan:

- `notif();`: Memanggil fungsi `notif()` yang mungkin menampilkan notifikasi tertentu.