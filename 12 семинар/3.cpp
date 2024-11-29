#include <iostream>
#include <vector>
using namespace std;
int main() {
	int* p = new int(123);
	cout << *p << endl;
	delete p;
	string* p1 = new string("Cats and Dogs");
	cout << *p1 << endl;
	delete p1;
	int* p2 = new int[5] {10, 20, 30, 40, 50};
	for (int i = 0; i < 5; i++) {
		cout << p2[i] << " ";
	}
	cout << endl;
	delete[] p2;
	vector<int>* p3 = new vector<int> { 10, 20, 30, 40, 50 };
	for (int i = 0; i < 5; i++) {
		cout << (*p3)[i] << " ";
	}
	cout << endl;
	delete p3;
	string* p4 = new string[3]{ "Cat", "Dog", "Mouse" };
	for (int i = 0; i < 3; i++) {
		cout << p4[i] << " ";
	}
	cout << endl;
	delete[] p4;
	return 0;
}