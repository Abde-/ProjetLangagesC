#include <iostream>

#include "vector.hpp"
#include "fixedvector.hpp"
#include "dynvector.hpp"
#include "polynome.hpp"
#include "dynpolynome.hpp"
#include "modpolynome.hpp"

using namespace std;


DynPolynome<int> polyntest;

int main() {

//	FixedVector<int,5> asd;
//	FixedVector<int,5> asd2;
//
	//cin >> asd[1] >> asd[2];
	//cout << asd;
//	cin >> asd;
//	cout << asd;
//	//cout << asd + asd2;
//	cout << -asd;
//
//	for (int i = 0; i < 5; ++i){
//		asd[i] = i;
//		asd2[i] = i+5;
//	}
//
//	asd += asd2;
//	cout << asd;
//
//	DynVector<int> asd3;
//	asd3.resize(5);
//	cout << asd3;
//	asd3 = asd;
//	cout << asd3;
//
//	DynPolynome<int> polyn1, polyn2;
//	cout << polyn2 << endl;
//	cin >> polyn1;
//	cout << polyn1 << endl;
//	cin >> polyn2;
//
//	//cout << -polyn2 << endl;
//	cout << 5+6 << endl;
//
//	cout << polyn1(4);
//	polyntest = polyn2 + polyn1 ;
//	cout << polyntest << endl;
//	cout << polyn2 * polyn1 << endl;
//	const DynPolynome<int> polyn3 = polyn1;
//	cout << polyn1 << endl;
//	polyn1[0] = 1000000;
//	cout << polyn3 << endl;
//	polyntest.resize(10);
//	for(size_t i = 0; i < 10; ++i)
//		polyntest[i] = 0;
//
	cin >> polyntest;
//	DynPolynome<int> poly1;
//	cin >> poly1;
//	for (size_t i = 0; i < 20; ++i)
//		poly1 *= polyntest;
//	cout << poly1;
	ModPolynome<int,5,polyntest> modtest;
	ModPolynome<int,5,polyntest> modtest2;
	cin >> modtest;
	cin >> modtest2;
	cout << modtest + modtest2;

	cout << modtest;
	cout << -modtest;

//	
//	DynVector<int> vect1(5);
//	DynVector<int> vect2(10);
//
//	FixedVector<int,5> vect5;
//
//	for (size_t i = 0; i < vect1.getSize(); ++i)
//		vect1[i] = i;
//	for (size_t i = 0; i < vect2.getSize(); ++i)
//		vect2[i] = i+5;
//
//	vect1 = vect2;
//	vect1[0] = 5000;
//
//	cout << vect1 << endl;
//	cout << vect2 << endl;
//
//	DynVector<int> vect3 = vect1 + vect2;
//
//	cout << vect3 << endl;
//
//	vect3 -= vect3;
//
//	cout << "Hello World" << endl;
//	
//	cout << vect3 << endl;
//
//	vect3 = vect2;
//
//	cout << vect3 << endl;
//	cout << vect5 << endl;
//	cout << +vect3 << endl;
//	cout << -vect3 << endl;
//	int entier = 2;
//	cout << vect3 * entier << endl;
//	cout << entier * vect3 << endl;
//	cout << vect3 * 3 << endl;
//
//	FixedVector<int,10> vectfixed(vect1); // conversion
//	cout << vectfixed << endl;
//	cout << static_cast<FixedVector<int,10>>(vect3*3) << endl; // static_cast
//
//	cout << "Hello World 2" << endl;
//
//	cout << static_cast<DynVector<int>>(vect1) << endl;
//
//	return 0;
	
}