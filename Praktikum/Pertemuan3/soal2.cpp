#include <iostream>
using namespace std;

struct Film {
    string judul;
    string sutradara;
    int tahun;
    float rating;
};

void clearScreen() {
    // ANSI escape code to clear screen
    std::cout << "\x1B[2J\x1B[H";
}

void ratingFilm(Film &flm) {
    cout << "Masukkan Judul: ";
    getline(cin, flm.judul);

    cout << "Masukkan Sutradara: ";
    getline(cin, flm.sutradara);

    cout << "Masukkan Tahun Rilis:  ";
    cin >> flm.tahun;

    cout << "Berikan Ratingnya:  ";
    cin >> flm.rating;

    cin.ignore();
}

int main() {
    Film flm1, flm2;

    clearScreen();
    cout << "=====" << endl;
    cout << "Isi Data Film  1" << endl;
    ratingFilm(flm1);
    cout << "========" << endl;
    cout << "Isi Data Film 2" << endl;
    ratingFilm(flm2);
    cout << endl;

    cout << "Data Film 1" << endl;
    cout << "Judul Film : " << flm1.judul << endl;
    cout << "Sutradara: " << flm1.sutradara << endl;
    cout << "Tahun Rilis: " << flm1.tahun << endl;
    cout << "Rating : " << flm1.rating << endl;

    cout << "Data Film 2" << endl;
    cout << "Judul Film : " << flm2.judul << endl;
    cout << "Sutradara: " << flm2.sutradara << endl;
    cout << "Tahun Rilis: " << flm2.tahun << endl;
    cout << "Rating : " << flm2.rating << endl;
    cout << endl;

    return 0;
}