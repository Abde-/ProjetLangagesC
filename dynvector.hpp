#ifndef _DYNVECTOR_H_
#define _DYNVECTOR_H_

#include "vector.hpp"
using namespace std;

template <typename Elem, size_t SIZE>
class FixedVector;

//----------------------------------------------------------------------------
template <typename Elem>
class DynVector : public Vector<Elem,DynVector<Elem>> {
	size_t _size;
	Elem* _val;				//tableau dynamique
public:
	DynVector(size_t size);	//constructeur
	DynVector(const DynVector<Elem>&); //constructeur de copie
	DynVector(DynVector<Elem>&&); // constructeur de transfert
	template <size_t SIZE>
	DynVector(const FixedVector<Elem,SIZE>&); // TODO

	size_t getSize() const override { return _size; }
	void resize(size_t);

	virtual const Elem& operator[] (ptrdiff_t) const override; //R-value
	virtual Elem& operator[] (ptrdiff_t) override;			 //L-value

	DynVector<Elem>& operator= (const DynVector<Elem>&); //assignation de copie
	DynVector<Elem>& operator= (DynVector<Elem>&&); //assignation de transfert

	virtual DynVector<Elem> operator+ (const DynVector<Elem>) override;
	virtual DynVector<Elem> operator+ () override { return *this; };
	virtual DynVector<Elem>& operator+=(const DynVector<Elem>) override;
	virtual DynVector<Elem> operator- (const DynVector<Elem>) override;
	virtual DynVector<Elem> operator- () override;	
	virtual DynVector<Elem>& operator-=(const DynVector<Elem>) override;
	virtual DynVector<Elem> operator* (const Elem) override;

	virtual void print(ostream&) const override;
	virtual void input(istream&) override;

	virtual ~DynVector<Elem>() { delete[] _val; }
};
//----------------------------------------------------------------------------

#include "fixedvector.hpp"

template <typename Elem>
DynVector<Elem>::DynVector(size_t size): _size(size), _val(new Elem[size]) {
	for (size_t i = 0; i < _size; ++i) _val[i] = 0;
}

template <typename Elem>
DynVector<Elem>::DynVector(const DynVector<Elem>& other):
	_size(other.getSize()), _val(new Elem[other.getSize()]) {
	for (size_t i = 0; i < _size; ++i) _val[i] = other[i];
}

template <typename Elem>
DynVector<Elem>::DynVector(DynVector<Elem>&& other):
	_size(other.getSize()), _val(new Elem[other.getSize()]) {
	for(size_t i = 0; i < _size; ++i){
		_val[i] = other[i];
		other[i] = 0;
	}
}

template <typename Elem>
void DynVector<Elem>::resize(size_t newSize){
	Elem* newVal = new Elem[newSize];

	if(_size > newSize){
		for(size_t i = 0; i < newSize; ++i)
			newVal[i] = _val[i];
	}
	else{
		for(size_t i = 0; i < _size; ++i)
			newVal[i] = _val[i];
		for(size_t i = _size; i < newSize; ++i)
			newVal[i] = 0;
	}
	_val = newVal; _size = newSize;

}

template <typename Elem> // works
const Elem& DynVector<Elem>::operator[](ptrdiff_t index) const {
	if (size_t(index) >= _size)
		throw out_of_range("DynVector: Index Out of Range");
	return _val[index];
}


template <typename Elem> // works
Elem& DynVector<Elem>::operator[](ptrdiff_t index) {
	if (size_t(index) >= _size)
		throw out_of_range("DynVector: Index Out of Range");
	return _val[index];
}


template <typename Elem>
DynVector<Elem>& DynVector<Elem>::operator= (const DynVector<Elem>& other) {
	size_t newSize(other.getSize()); Elem* newVal(new Elem[newSize]);
	for (size_t i = 0; i < newSize; ++i)
		newVal[i] = other[i];
	delete[] _val; _val = newVal; _size = newSize;
	return *this;
}

template <typename Elem>
DynVector<Elem>& DynVector<Elem>::operator= (DynVector<Elem>&& other){
	size_t newSize(other.getSize()); Elem* newVal(new Elem[newSize]);
	for (size_t i = 0; i < newSize; ++i){
		newVal[i] = other[i];
		other[i] = 0;
	}
	delete[] _val; _val = newVal; _size = newSize;
	return *this;
}

template <typename Elem> // works -> optimiser, marche pas dans tous les cas
DynVector<Elem> DynVector<Elem>::operator+ (const DynVector<Elem> other) {
    size_t newSize;

	if (_size > other.getSize())
		newSize = _size;
	else{ newSize = other.getSize(); }

	DynVector<Elem> newVect(newSize);

	for (size_t i = 0; i < newSize; ++i)
		newVect[i] = _val[i] + other[i];
	return newVect;
}

template <typename Elem> // works
DynVector<Elem>& DynVector<Elem>::operator+= (const DynVector<Elem> other) {
	size_t newSize;

	if (_size < other.getSize()){
		newSize = other.getSize();
		resize(newSize); 
	}
	else { newSize = other.getSize(); }

	for (size_t i = 0; i < newSize; ++i)
		_val[i] += other[i];
	return *this;
}

template <typename Elem> // works -> optimiser, marche pas dans tous les cas
DynVector<Elem> DynVector<Elem>::operator-(const DynVector<Elem> other) {
    size_t newSize;

	if (_size > other.getSize())
		newSize = _size;
	else{ newSize = other.getSize(); }

	DynVector<Elem> newVect(newSize);

	for (size_t i = 0; i < newSize; ++i)
		newVect[i] = _val[i] - other[i];
	return newVect;
}

template <typename Elem>
DynVector<Elem> DynVector<Elem>::operator-() {
	DynVector<Elem> newVect(_size);
	for (size_t i = 0; i < _size; ++i)
		newVect[i] = -_val[i];
	return newVect;
}

template <typename Elem> // works
DynVector<Elem>& DynVector<Elem>::operator-=(const DynVector<Elem> other) {
	size_t newSize;

	if (_size < other.getSize()){
		newSize = other.getSize();
		resize(newSize);
	}
	else { newSize = other.getSize(); }

	for (size_t i = 0; i < newSize; ++i)
		_val[i] -= other[i];
	return *this;
}

template <typename Elem>
DynVector<Elem> DynVector<Elem>::operator*(const Elem item) {
	DynVector<Elem> newVect(_size);

	for (size_t i = 0; i < _size; ++i)
		newVect[i] = _val[i] * item;
	return newVect;
}

template <typename Elem>
DynVector<Elem> operator*(Elem item, DynVector<Elem> v){
	return v*item;
}

template <typename Elem> // works
void DynVector<Elem>::print(ostream& os) const {
	os << "[";
	for (size_t i=0; i < _size; ++i){ 
		os << _val[i];
		if (i != _size-1)
			os << ",";
	 }
	 os << "]";
}

template <typename Elem> // works
void DynVector<Elem>::input(istream& is) {
	for (size_t i=0; i < _size; ++i)
		is >> _val[i];
}

#endif   /* _DYNVECTOR_H_ */