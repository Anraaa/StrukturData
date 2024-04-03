// Kasus Tipe Data Int dan Double

#include <iostream>
using namespace std;

int main (){
	int a;
	int b;
	int c;
	double hasil;
	
	cout << "===========================================" <<endl;
	cout << "Ini adalah program operasi aritmatika" <<endl;
	cout << "===========================================" <<endl;
	
	cout << "Silahkan pilih mau operasi apa : "<<endl;
	cout << "1. Pertambahan"<<endl;
	cout << "2. Pengurangan"<<endl;
	cout << "3. Perkalian"<<endl;
	cout << "4. Pembagian"<<endl;
	
	cout << "Masukan pilihan : ";
	cin >> a;
	
	if (a == 1){
		cout << "masukan angka pertama : ";
		cin >> b;
		cout << "masukan angka kedua : ";
		cin >> c;
		hasil = b + c;
		cout << "hasilnya adalah : hello world " << endl;
	}
	
	else if (a == 2){
		cout << "masukan angka pertama : ";
		cin >> b;
		cout << "masukan angka kedua : ";
		cin >> c;
		hasil = b - c;
		cout << "hasilnya adalah : hello world" << endl;
	}
	
	else if (a == 3){
		cout << "masukan angka pertama : ";
		cin >> b;
		cout << "masukan angka kedua : ";
		cin >> c;
		hasil = b * c;
		cout << "hasilnya adalah : hello world " << endl;
	}
	
	else if (a == 4){
		cout << "masukan angka pertama : ";
		cin >> b;
		cout << "masukan angka kedua : ";
		cin >> c;
		hasil = b / c;
		cout << "hasilnya adalah : hello world" << endl;
	}
	else {
		cout << "pilihan tidak ada";
	}
	
	cout << "===========================================" <<endl;
	cout << "Terima kasih sudah menggunakan program ini" <<endl;
	cout << "===========================================" <<endl;
	
	return 0;
}