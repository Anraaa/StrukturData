### Fungsi isDigit
```cpp
void isDigit(const string& operation) {
    if (operation.length() != 1 || !isdigit(operation[0])) {
        throw invalid_argument("Input Salah. Silahkan Input 1-5 Saja");
    }
}
```
Fungsi `isDigit()` ini menerima satu argumen, yaitu `operation` yang merupakan referensi ke sebuah string. Fungsi ini digunakan untuk memeriksa apakah string `operation` adalah sebuah digit tunggal.

Berikut adalah penjelasan detail dari setiap bagian fungsi:

1. `if (operation.length() != 1 || !isdigit(operation[0]))`: Ini adalah kondisi yang memeriksa dua hal:
   - `operation.length() != 1`: Memeriksa apakah panjang string `operation` tidak sama dengan 1. Jika panjangnya lebih dari 1, maka string tersebut pasti bukan digit tunggal.
   - `!isdigit(operation[0])`: Fungsi `isdigit()` memeriksa apakah karakter pertama dalam string `operation` adalah digit. Jika bukan, `isdigit(operation[0])` akan menghasilkan `false`, dan `!isdigit(operation[0])` akan menghasilkan `true`.

   Jika salah satu dari dua kondisi ini benar, maka blok kode dalam kondisi `if` akan dieksekusi.

2. `throw invalid_argument("Input Salah. Silahkan Input 1-5 Saja");`: Jika kondisi `if` benar, maka fungsi ini akan melempar (throw) sebuah pengecualian `invalid_argument` dengan pesan "Input Salah. Silahkan Input 1-5 Saja". Pengecualian ini harus ditangani (catch) oleh kode yang memanggil fungsi `isDigit()`, atau program akan dihentikan.

Secara keseluruhan, fungsi `isDigit()` ini digunakan untuk memastikan bahwa string `operation` adalah digit tunggal. Jika bukan, fungsi ini akan melempar pengecualian.