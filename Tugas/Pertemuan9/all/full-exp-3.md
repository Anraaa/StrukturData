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

1. `bool validInput = false;`: Ini adalah deklarasi dan inisialisasi variabel boolean `validInput` dengan nilai `false`. Variabel ini digunakan untuk mengendalikan loop `while` berikutnya.

2. `while (!validInput) { ... }`: Ini adalah loop `while` yang akan terus berjalan selama `validInput` bernilai `false`. Loop ini digunakan untuk meminta input dari pengguna sampai input tersebut valid.

3. Di dalam loop `while`, kita memiliki blok `try-catch` yang digunakan untuk menangani pengecualian yang mungkin dilempar oleh fungsi `isDigit()`.

4. `cout << "Pilih operasi (1-5): ";`: Ini adalah pernyataan yang mencetak prompt ke console.

5. `cin >> operation;`: Ini adalah pernyataan yang membaca input dari pengguna dan menyimpannya dalam variabel `operation`.

6. `isDigit(operation);`: Ini adalah pemanggilan fungsi `isDigit()` yang memeriksa apakah `operation` adalah digit tunggal. Jika bukan, fungsi ini akan melempar pengecualian `invalid_argument`.

7. `validInput = true;`: Jika fungsi `isDigit(operation)` tidak menemukan masalah (yaitu, pengguna memasukkan angka seperti yang diminta), maka baris kode ini akan dijalankan. Baris kode ini mengubah `validInput` menjadi `true`, yang berarti input pengguna sudah benar dan loop `while` akan berhenti.

8. `catch (invalid_argument& e) { ... }`: Ini adalah bagian kode yang berfungsi untuk "menangkap" kesalahan tertentu, dalam hal ini kesalahan `invalid_argument`. Jika ada kesalahan `invalid_argument` yang terjadi (misalnya, pengguna memasukkan sesuatu yang bukan angka saat diminta angka), maka bagian kode ini akan dijalankan. Pesan kesalahan tersebut akan ditampilkan di layar.

9. `cout << e.what() << endl;`: Ini adalah baris kode yang menampilkan pesan kesalahan ke layar. `e.what()` adalah fungsi yang mengambil pesan dari kesalahan yang terjadi, dan `cout` digunakan untuk menampilkan pesan tersebut.

