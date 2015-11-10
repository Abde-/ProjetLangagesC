#include <iostream>

#include "vector.hpp"
#include "dynvector.hpp"
#include "fixedvector.hpp"

using namespace std;

int main() {
	DynVector<int> vect1(5);
	DynVector<int> vect2(5);

	FixedVector<int,5> vect5;

	for (size_t i = 0; i < vect1.getSize(); ++i){
		vect1[i] = i;
		vect2[i] = i+5;
	}

	vect1 = vect2;
	vect1[0] = 5000;

	cout << vect1 << endl;
	cout << vect2 << endl;

	DynVector<int> vect3 = vect1 + vect2;

	cout << vect3 << endl;

	vect3 -= vect3;

	cout << "Hello World" << endl;
	
	cout << vect3 << endl;

	vect3 = vect2;

	cout << vect3 << endl;
	cout << vect5 << endl;
	cout << +vect3 << endl;
	cout << -vect3 << endl;
	int entier = 2;
	cout << vect3 * entier << endl;
	cout << entier * vect3 << endl;
	cout << vect3 * 3 << endl;
	cout << 3 * vect3 << endl;

	FixedVector<int,10> vectfixed(vect1); // conversion
	cout << vectfixed << endl;
	cout << static_cast<FixedVector<int,10>>(vect3*3) << endl; // static_cast

	return 0;
}