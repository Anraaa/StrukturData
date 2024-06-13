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

Jika pengguna memilih operasi "3" (`else if (operation == "3")`), maka kode berikut akan dijalankan:

- `clearScreen();`: Membersihkan layar. Fungsi ini biasanya digunakan untuk membuat tampilan program lebih rapi.

- `if (!bookStack.empty())`: Mengecek apakah tumpukan buku (`bookStack`) kosong atau tidak. Jika tidak kosong, maka kode berikutnya akan dijalankan.

- `cout << "Judul buku paling atas: " << bookStack.top() << endl;`: Menampilkan judul buku yang berada di paling atas tumpukan buku (`bookStack`).

Jika tumpukan buku kosong (`else`), maka kode berikut akan dijalankan:

- `cout << "Stack buku kosong." << endl;`: Menampilkan pesan bahwa tumpukan buku kosong.

Setelah itu, kode berikut akan dijalankan:

- `notif();`: Memanggil fungsi `notif()` yang mungkin menampilkan notifikasi tertentu.