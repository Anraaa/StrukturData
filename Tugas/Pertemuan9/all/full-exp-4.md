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

Jika pengguna memilih operasi "1" (`if (operation == "1")`), maka kode berikut akan dijalankan:

- `string book;`: Membuat variabel `book` untuk menyimpan judul buku.

- `clearScreen();`: Membersihkan layar. Fungsi ini biasanya digunakan untuk membuat tampilan program lebih rapi.

- `cout << "Masukkan judul buku: ";`: Menampilkan teks "Masukkan judul buku:" untuk memberi tahu pengguna bahwa mereka harus memasukkan judul buku.

- `cin.ignore();`: Mengabaikan karakter berikutnya yang dimasukkan pengguna. Ini biasanya digunakan setelah `cin >>` untuk mencegah masalah dengan input.

- `getline(cin, book);`: Membaca baris teks selanjutnya yang dimasukkan pengguna dan menyimpannya dalam variabel `book`.

- `bookStack.push(book);`: Menambahkan buku yang baru dimasukkan pengguna ke dalam tumpukan buku (`bookStack`).

- `cout << "Buku berhasil ditambahkan ke dalam stack." << endl;`: Menampilkan pesan bahwa buku telah berhasil ditambahkan.

- `notif();`: Memanggil fungsi `notif()` yang mungkin menampilkan notifikasi tertentu.