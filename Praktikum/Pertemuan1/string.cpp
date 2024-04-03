// kasus Tipe Data String   

#include <iostream>
using namespace std;

int main (){
	string Nama;
	string NIM;
	string fakultas;
	string jurusan;
	
	cout << "===========================================" <<endl;
	cout << "Program mengisi data dan tampilkan data" <<endl;
	cout << "===========================================" <<endl;
	
	cout << "masukkan Nama Mahasiswa : " ;
	getline (cin, Nama);
	
	cout << "masukkan NIM Mahasiswa : " ;
	getline (cin, NIM);
	
	cout << "masukkan fakultas mahasiswa : " ;
	getline (cin, fakultas);
	
	cout << "masukkan jurusan mahasiswa : " ;
	getline (cin, jurusan);
	
	cout << "===========================================" <<endl;
	cout << "Terimakasih"<<endl;
	cout << ""<<endl;
	cout << "===========================================" <<endl;
	
	return 0;
}