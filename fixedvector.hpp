
#ifndef _FIXEDVECTOR_H_
#define _FIXEDVECTOR_H_

#include "vector.hpp"
using namespace std;

template <typename Elem>
class DynamicVector;

//----------------------------------------------------------------------------
template <typename Elem,size_t size>
class FixedVector: public Vector<Elem,FixedVector<Elem,size>>{
	Elem _val[size];

public:
	FixedVector(); //constructeur
	FixedVector(const FixedVector<Elem,size>&); //constructeur copie
	FixedVector(FixedVector<Elem,size>&&); // constructeur de transfert
	FixedVector(const DynVector<Elem>&); // constructeur conversion

	size_t getSize() const override { return size; }

	virtual const Elem& operator[] (ptrdiff_t) const override; //R-value
	virtual Elem& operator[] (ptrdiff_t) override; //L-value

	FixedVector<Elem,size>& operator= (FixedVector<Elem,size>&&); // transfert
	FixedVector<Elem,size>& operator= (const DynVector<Elem>&); // conversion

	virtual FixedVector<Elem,size> operator+ (const FixedVector<Elem,size>) override;
	virtual FixedVector<Elem,size> operator+ () override{ return *this; };
	virtual FixedVector<Elem,size>& operator+= (const FixedVector<Elem,size>) override;
	virtual FixedVector<Elem,size> operator- (const FixedVector<Elem,size>) override;
	virtual FixedVector<Elem,size> operator- () override;
	virtual FixedVector<Elem,size>& operator-= (const FixedVector<Elem,size>) override;
	virtual FixedVector<Elem,size> operator* (const Elem) override;
	virtual FixedVector<Elem,size>& operator*= (const Elem) override;

	virtual void print(ostream&) const override;
	virtual void input(istream&) override;
};
//----------------------------------------------------------------------------

#include "dynvector.hpp"

template <typename Elem, size_t size>
FixedVector<Elem,size>::FixedVector(){
	for (size_t i = 0; i < size; ++i) _val[i] = 0;
}

template <typename Elem, size_t size>
FixedVector<Elem,size>::FixedVector(const FixedVector<Elem,size>& other) {
	for (size_t i = 0; i < size; ++i) _val[i] = other[i];
}

template <typename Elem, size_t size>
const Elem& FixedVector<Elem,size>::operator[](ptrdiff_t index) const {
	if (size_t(index) >= size)
		throw out_of_range("FixedVector: Index Out of Range");
	return _val[index];
}

template <typename Elem, size_t size>
Elem& FixedVector<Elem,size>::operator[](ptrdiff_t index) {
	if (size_t(index) >= size)
		throw out_of_range("FixedVector: Index Out of Range");
	return _val[index];
}

template <typename Elem, size_t size>
FixedVector<Elem,size>::FixedVector(FixedVector<Elem,size>&& other){
	for(size_t i = 0; i < size; ++i){
		_val[i] = other[i];
		other[i] = 0;
	}
}

template <typename Elem, size_t size>
FixedVector<Elem,size>::FixedVector(const DynVector<Elem>& other){
	for(size_t i = 0; i < size; ++i){
		if (i < other.getSize())
			_val[i] = other[i];
		else
			_val[i] = 0;
	}
}
template <typename Elem, size_t size>
FixedVector<Elem,size>& FixedVector<Elem,size>::operator= (FixedVector<Elem,size>&& other){
	for(size_t i = 0; i < size; ++i){
		_val[i] = other[i];
		other[i] = 0;
	}
	return *this;
}

template <typename Elem, size_t size>
FixedVector<Elem,size>& FixedVector<Elem,size>::operator= (const DynVector<Elem>& other){
	for(size_t i = 0; i < size; ++i){
		if (i < other.getSize())
			_val[i] = other[i];
		else
			_val[i] = 0;
	}	

	return *this;
}

template <typename Elem, size_t size>
FixedVector<Elem,size> FixedVector<Elem,size>::operator+ (const FixedVector<Elem,size> other){
	FixedVector<Elem,size> newVect;

	for (size_t i = 0; i < size; ++i)
		newVect[i] = _val[i] + other[i];
	return newVect;
}

template <typename Elem, size_t size>
FixedVector<Elem,size>& FixedVector<Elem,size>::operator+= (const FixedVector<Elem,size> other){
	for (size_t i = 0; i < size; ++i)
			_val[i] += other[i];
	return *this;
}

template <typename Elem, size_t size>
FixedVector<Elem,size> FixedVector<Elem,size>::operator- (const FixedVector<Elem,size> other){
	FixedVector<Elem,size> newVect;

	for (size_t i = 0; i < size; ++i)
		newVect[i] = _val[i] - other[i];
	return newVect;
}

template <typename Elem, size_t size>
FixedVector<Elem,size> FixedVector<Elem,size>::operator- (){
	FixedVector<Elem,size> newVect;
	for (size_t i = 0; i < size; ++i)
		newVect[i] = -_val[i];
	return newVect;
}

template <typename Elem, size_t size>
FixedVector<Elem,size>& FixedVector<Elem,size>::operator-= (const FixedVector<Elem,size> other){
	for (size_t i = 0; i < size; ++i)
		_val[i] -= other[i];
	return *this;
}

template <typename Elem, size_t size>
FixedVector<Elem,size> FixedVector<Elem,size>::operator* (const Elem item){
	FixedVector<Elem,size> newVect;

	for (size_t i = 0; i < size; ++i) {
		newVect[i] = _val[i] * item;
	}
	return newVect;
}

template <typename Elem, size_t size>
FixedVector<Elem,size> operator* (Elem item, FixedVector<Elem,size> v){
	return v*item;
}

template <typename Elem, size_t size>
FixedVector<Elem,size>& FixedVector<Elem,size>::operator*= (const Elem item){
	for (size_t i = 0; i < size; ++i) {
		_val[i] = _val[i] * item;
	}
	return *this;
}

template <typename Elem, size_t size>
void FixedVector<Elem,size>::print(ostream& os) const {
	os << "[";
	for (size_t i=0; i < size; ++i){ 
		os << _val[i];
		if (i != size-1)
			os << ",";
	 }
	os << "]";
}
template <typename Elem, size_t size>
void FixedVector<Elem,size>::input(istream& is) {
	for (size_t i=0; i < size; ++i)
				is >> _val[i];
}

#endif   /* _FIXEDVECTOR_H_ */