// Kasus Tipe Data Char

#include <iostream>
using namespace std;

int main (){
	
	//Program mengkonversi angka ke ASCII
	int angka;
	cout << "Masukan angka : ";
	cin >> angka;
	
	if (angka < 32 || angka > 126){
		cout << "Angka yang dimasukan tidak valid" <<endl;
	}
	else if (angka == 32){
		cout << "Hasil konversi: spasi" <<endl;
	}
	
	else if (angka == 127){
		cout << "Hasil konversi: delete" <<endl;
	}
	
	else {
		char konversi = angka;
		cout << "Hasil konversi: " << konversi << endl;
	}
	
	cout << "===========================================" <<endl;
	cout << "Terima kasih sudah menggunakan program ini" <<endl;
	cout << "===========================================" <<endl;
	
	return 0;
}