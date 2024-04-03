#include <iostream>
using namespace std;

struct Address {
  string street;
  string city;
  string state;
  int zip;
};

struct Student {
  string name;
  int age;
  int grade;
  Address address;
};

int main() {
  Student student1;

  cout << "Enter student name: ";
  getline(cin, student1.name);

  cout << "Enter student age: ";
  cin >> student1.age;

  cout << "Enter student grade: ";
  cin >> student1.grade;

  cin.ignore(); // to clear the newline character from the input buffer

  cout << "Enter street address: ";
  getline(cin, student1.address.street);

  cout << "Enter city: ";
  getline(cin, student1.address.city);

  cout << "Enter state: ";
  getline(cin, student1.address.state);

  cout << "Enter zip code: ";
  cin >> student1.address.zip;

  cout << "Student Name: " << student1.name << endl;
  cout << "Age: " << student1.age << endl;
  cout << "Grade: " << student1.grade << endl;
  cout << "Address:" << endl;
  cout << student1.address.street << endl;
  cout << student1.address.city << ", " << student1.address.state << " " << student1.address.zip << endl;

  return 0;
}