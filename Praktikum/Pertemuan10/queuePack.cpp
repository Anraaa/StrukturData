#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> antrian;

    antrian.push(10);
    antrian.push(25);
    antrian.push(5);

    cout << "Ukuran antrean: " << antrian.size() << endl;
    
    cout << "Elemen terdepan: " << antrian.front() << endl;

    antrian.pop();

    cout << "Elemen depan (setelah pop): " << antrian.front() << endl;

    return 0;
}