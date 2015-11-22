#ifndef _DYNVECTOR_H_
#define _DYNVECTOR_H_

#include "vector.hpp"

template <typename Elem, size_t SIZE>
class FixedVector;


using namespace std;


//----------------------------------------------------------------------------
template <typename Elem>
class DynVector : virtual public Vector<Elem> {
	size_t _size;
	Elem* _val;				//tableau dynamique
public:
	DynVector();	//constructeur
	DynVector(size_t size);	//constructeur
	DynVector(const DynVector<Elem>&); //constructeur de copie
	DynVector(DynVector<Elem>&&); // constructeur de transfert
	template <size_t SIZE>
	DynVector(const FixedVector<Elem,SIZE>&); // constructeur de conversion

	size_t getSize() const override { return _size; }
	virtual Elem* getVal() const override { return _val; }
	virtual bool resize(size_t) override;

	DynVector<Elem>& operator= (const DynVector<Elem>&); //assignation de copie
	DynVector<Elem>& operator= (DynVector<Elem>&&); //assignation de transfert
	template <size_t SIZE>
	DynVector<Elem>& operator= (const FixedVector<Elem,SIZE>&);

	DynVector<Elem> operator* (const Elem&);
	DynVector<Elem>& operator*= (const Elem&);

	virtual void print(ostream&) const override;
	virtual void input(istream&) override;

	virtual ~DynVector<Elem>() { delete[] _val; }
};
//----------------------------------------------------------------------------
#include "fixedvector.hpp"


template <typename Elem>
DynVector<Elem>::DynVector(): _size(0), _val(new Elem[0]) {
	for (size_t i = 0; i < _size; ++i) _val[i] = 0;
}

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
template <size_t SIZE>
DynVector<Elem>::DynVector(const FixedVector<Elem,SIZE>& other):
	_size(other.getSize()), _val(new Elem[other.getSize()]) {
		for (size_t i = 0; i < _size; ++i) _val[i] = other[i];
}

template <typename Elem>
bool DynVector<Elem>::resize(size_t newSize){
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
	return true;
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

template <typename Elem>
template <size_t SIZE>
DynVector<Elem>& DynVector<Elem>::operator= (const FixedVector<Elem,SIZE>& other) {
	size_t newSize(other.getSize()); Elem* newVal(new Elem[newSize]);
	for (size_t i = 0; i < newSize; ++i)
		newVal[i] = other[i];
	delete[] _val; _val = newVal; _size = newSize;
	return *this;
}

template <typename Elem>
DynVector<Elem> DynVector<Elem>::operator* (const Elem& item){
	DynVector<Elem> newVect;
	newVect.resize(this->getSize());

	for (size_t i = 0; i < this->getSize(); ++i)
		newVect[i] = (*this)[i] * item;
	return newVect;
}

template <typename Elem>
DynVector<Elem> operator* (const Elem& item, const DynVector<Elem>& vector){
	DynVector<Elem> newVect;
	newVect.resize(vector.getSize());

	for (size_t i = 0; i < vector.getSize(); ++i)
		newVect[i] = vector[i] * item;
	return newVect;
}

template <typename Elem>
DynVector<Elem>& DynVector<Elem>::operator*= (const Elem& item){
	for (size_t i = 0; i < this->getSize(); ++i)
		(*this)[i] = (*this)[i] * item;
	return (*this);
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
		is >> this->getVal()[i];
}

#endif   /* _DYNVECTOR_H_ */