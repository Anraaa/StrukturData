// Struct Untuk Manajemen Keuangan

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Transaksi
{
    string jenis;
    int jumlah;
    string keterangan;
};

void displayTransaction(const Transaksi &t)
{
    cout << setw(15) << left << t.jenis << setw(15) << "Rp. " + to_string(t.jumlah) << setw(15) << t.keterangan << endl;
}

double hitungTotalPemasukan(const vector<Transaksi> &transaksi)
{
    double totalPemasukan = 0.0;
    for (const auto &t : transaksi)
    {
        if (t.jenis == "Pemasukan")
        {
            totalPemasukan += t.jumlah;
        }
    }
    return totalPemasukan;
}

double hitungTotalPengeluaran(const vector<Transaksi> &transaksi)
{
    double totalPengeluaran = 0.0;
    for (const auto &t : transaksi)
    {
        if (t.jenis == "Pengeluaran")
        {
            totalPengeluaran += t.jumlah;
        }
    }
    return totalPengeluaran;
}

int main()
{
    vector<Transaksi> transaksiPemasukan;
    vector<Transaksi> transaksiPengeluaran;
    string jenis;
    string keterangan;
    double jumlah;
    char input;
    cout << "===================================================" << endl;
    cout << "= SELAMAT DATANG DI APLIKASI MANAJEMEN TRANSAKSI! =" << endl;
    cout << "===================================================" << endl;
    cout << "MADE BY KELOMPOK 6" << endl;
    cout << "press any key to continue...";
    cin.get();

    do
    {
        system("clear");
        fflush(stdin);
        do
        {
            cout << "Masukkan data transaksi (jenis, jumlah, keterangan): " << endl;
            cout << "Jenis : " << endl;
            cout << "1. Pemasukan" << endl;
            cout << "2. Pengeluaran" << endl;
            cout << "Pilih jenis transaksi (1/2)    : ";
            getline(cin, jenis);
            if (jenis == "1")
            {
                jenis = "Pemasukan";
            }
            else if (jenis == "2")
            {
                jenis = "Pengeluaran";
            }
            else
            {
                cout << "Input Tidak Valid. Input harus berupa angka. Silahkan coba lagi.\n";
                fflush(stdin);
                cout << "Press any key to continue...";
                getchar();
                system("clear");
            }
        } while (jenis != "Pemasukan" && jenis != "Pengeluaran");

        cout << "Jumlah                         : ";
        while (!(cin >> jumlah))
        {
            cout << "Input Tidak Valid. Input harus berupa angka. Silahkan coba lagi.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Add this line to clear the input buffer
        fflush(stdin);


        cout << "Keterangan                     : ";
        getline(cin, keterangan);
        Transaksi t = {jenis, static_cast<int>(jumlah), keterangan};
        if (jenis == "Pemasukan")
        {
            transaksiPemasukan.push_back(t);
        }
        else if (jenis == "Pengeluaran")
        {
            transaksiPengeluaran.push_back(t);
        }

        // Menampilkan detail transaksi setelah ditambahkan
        cout << endl << "Detail Transaksi:" << endl;
        cout << setw(15) << left << "Jenis" << setw(15) << "Jumlah" << setw(15) << "Keterangan" << endl;
        displayTransaction(t);

        cout << "Apakah ada transaksi lain? (y/n): ";
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Add this line to clear the input buffer


    } while (input == 'y' || input == 'Y');

    // Menampilkan detail semua pemasukan
    cout << endl << "Detail Semua Pemasukan:" << endl;
    cout << setw(15) << left << "Jenis" << setw(15) << "Jumlah" << setw(15) << "Keterangan" << endl;
    for (const auto &t : transaksiPemasukan)
    {
        displayTransaction(t);
    }

    // Menampilkan detail semua pengeluaran
    cout << endl << "Detail Semua Pengeluaran:" << endl;
    cout << setw(15) << left << "Jenis" << setw(15) << "Jumlah" << setw(15) << "Keterangan" << endl;
    for (const auto &t : transaksiPengeluaran)
    {
        displayTransaction(t);
    }

    // Menampilkan total pemasukan dan pengeluaran
    cout << endl << "Total Pemasukan: " << hitungTotalPemasukan(transaksiPemasukan) << endl;
    cout << "Total Pengeluaran: " << hitungTotalPengeluaran(transaksiPengeluaran) << endl;

    return 0;
}