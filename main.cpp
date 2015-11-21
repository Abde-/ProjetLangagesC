#include <iostream>

#include "vector.hpp"
#include "fixedvector.hpp"
#include "dynvector.hpp"
#include "polynome.hpp"
#include "dynpolynome.hpp"

using namespace std;

int main() {

	FixedVector<int,5> asd;
	FixedVector<int,5> asd2;

	//cin >> asd[1] >> asd[2];
	//cout << asd;
	cin >> asd;
	cout << asd;
	//cout << asd + asd2;
	cout << -asd;

	for (int i = 0; i < 5; ++i){
		asd[i] = i;
		asd2[i] = i+5;
	}

	asd += asd2;
	cout << asd;

	DynVector<int> asd3;
	asd3.resize(5);
	cout << asd3;
	asd3 = asd;
	cout << asd3;

	DynPolynome<int> polyn1, polyn2;
	cout << polyn2 << endl;
	cin >> polyn1;
	cout << polyn1 << endl;
	cin >> polyn2;
	//cout << polyn2 << endl;
	//cout << -polyn2 << endl;
	cout << 5+6 << endl;


	DynPolynome<int> polyntest;
	polyntest = polyn2 + polyn1;
	//cout << polyn2[5] << endl;
	
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

	FixedVector<int,10> vectfixed(vect1); // conversion
	cout << vectfixed << endl;
	cout << static_cast<FixedVector<int,10>>(vect3*3) << endl; // static_cast

	cout << "Hello World 2" << endl;

	cout << static_cast<DynVector<int>>(vect1) << endl;

	return 0;
	
}