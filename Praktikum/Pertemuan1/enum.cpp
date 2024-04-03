// Kasus Tipe Data Enum

#include <iostream>
using namespace std;

int main (){
	enum hari {
		senin,
		selasa,
		rabu,
		kamis,
		jumat,
		sabtu,
		minggu
	};
	
	hari hari_ini = senin;
	
	cout << "tipe data enum (enumeration)" << endl;
	cout << "hari ini adalah hari ke-" << hari_ini + 1 <<endl;
	
	return 0;
	
}