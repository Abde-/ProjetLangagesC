
#ifndef _FIXEDVECTOR_H_
#define _FIXEDVECTOR_H_

#include "vector.hpp"
#include "dynvector.hpp"
using namespace std;

//----------------------------------------------------------------------------
template <typename Elem,size_t size>
class FixedVector: public Vector<Elem,FixedVector<Elem,size>>{
	Elem _val[size];

public:
	FixedVector(); //constructeur
	FixedVector(const FixedVector<Elem,size>&); //constructeur copie
	FixedVector(FixedVector<Elem,size>&&); // constructeur de transfert

	size_t getSize() const override { return size; }

	virtual const Elem& operator[] (ptrdiff_t) const override; //R-value
	virtual Elem& operator[] (ptrdiff_t) override; //L-value

	FixedVector<Elem,size>& operator= (FixedVector<Elem,size>&&);

	virtual FixedVector<Elem,size> operator+ (FixedVector<Elem,size>) override;
	virtual FixedVector<Elem,size> operator+ () override{ return *this; };
	virtual FixedVector<Elem,size>& operator+= (FixedVector<Elem,size>) override;
	virtual FixedVector<Elem,size> operator- (FixedVector<Elem,size>) override;
	virtual FixedVector<Elem,size> operator- () override;
	virtual FixedVector<Elem,size>& operator-= (FixedVector<Elem,size>) override;
	virtual FixedVector<Elem,size> operator* (Elem) override;

	virtual void print(ostream&) const override;
	virtual void input(istream&) override;
};
//----------------------------------------------------------------------------

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
FixedVector<Elem,size>& FixedVector<Elem,size>::operator= (FixedVector<Elem,size>&& other){
	for(size_t i = 0; i < size; ++i){
		_val[i] = other[i];
		other[i] = 0;
	}
	return *this;
}

template <typename Elem, size_t size>
FixedVector<Elem,size> FixedVector<Elem,size>::operator+ (FixedVector<Elem,size> other){
	FixedVector<Elem,size> newVect;

	for (size_t i = 0; i < size; ++i)
		newVect[i] = _val[i] + other[i];
	return newVect;
}

template <typename Elem, size_t size>
FixedVector<Elem,size>& FixedVector<Elem,size>::operator+= (FixedVector<Elem,size> other){
	for (size_t i = 0; i < size; ++i)
			_val[i] += other[i];
	return *this;
}

template <typename Elem, size_t size>
FixedVector<Elem,size> FixedVector<Elem,size>::operator- (FixedVector<Elem,size> other){
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
FixedVector<Elem,size>& FixedVector<Elem,size>::operator-= (FixedVector<Elem,size> other){
	for (size_t i = 0; i < size; ++i)
		_val[i] -= other[i];
	return *this;
}

template <typename Elem, size_t size>
FixedVector<Elem,size> FixedVector<Elem,size>::operator* (Elem item){
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