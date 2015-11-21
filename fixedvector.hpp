
#ifndef _FIXEDVECTOR_H_
#define _FIXEDVECTOR_H_

#include "vector.hpp"

template <typename Elem>
class DynVector;

using namespace std;
//----------------------------------------------------------------------------
template <typename Elem,size_t size>
class FixedVector: virtual public Vector<Elem>{
	Elem* _val;

public:
	FixedVector(); //constructeur
	FixedVector(const FixedVector<Elem,size>&); //constructeur copie
	FixedVector(FixedVector<Elem,size>&&); // constructeur de transfert
	FixedVector(const DynVector<Elem>&); // constructeur conversion

	size_t getSize() const override { return size; }
	virtual Elem* getVal() const override { return _val; }
	virtual bool resize(size_t x) { return x>size? false : true; }

	FixedVector<Elem,size>& operator= (const FixedVector<Elem,size>&);
	FixedVector<Elem,size>& operator= (FixedVector<Elem,size>&&); // transfert
	FixedVector<Elem,size>& operator= (const DynVector<Elem>&); // conversion

	virtual void print(ostream&) const override;
	virtual void input(istream&) const override;

	virtual ~FixedVector<Elem,size>() { delete[] _val; }
};
//----------------------------------------------------------------------------
#include "dynvector.hpp"


template <typename Elem, size_t size>
FixedVector<Elem,size>::FixedVector(): _val(new Elem[size]){
	for (size_t i = 0; i < size; ++i) _val[i] = 0;
}

template <typename Elem, size_t size>
FixedVector<Elem,size>::FixedVector
	(const FixedVector<Elem,size>& other): _val(new Elem[size]) {
	for (size_t i = 0; i < size; ++i) _val[i] = other[i];
}

template <typename Elem, size_t size>
FixedVector<Elem,size>::FixedVector
	(FixedVector<Elem,size>&& other): _val(new Elem[size]){
	for(size_t i = 0; i < size; ++i){
		_val[i] = other[i];
		other[i] = 0;
	}
}

template <typename Elem, size_t size>
FixedVector<Elem,size>::FixedVector 
	(const DynVector<Elem>& other): _val(new Elem[size]){
	for(size_t i = 0; i < size; ++i){
		if (i < other.getSize())
			_val[i] = other[i];
		else
			_val[i] = 0;
	}
}

template <typename Elem, size_t size>
FixedVector<Elem,size>& FixedVector<Elem,size>::operator= 
	(const FixedVector<Elem,size>& other) {
	for(size_t i = 0; i < size; ++i){
		_val[i] = other[i];
	}
	return *this;
}

template <typename Elem, size_t size>
FixedVector<Elem,size>& FixedVector<Elem,size>::operator= 
	(FixedVector<Elem,size>&& other) {
	for(size_t i = 0; i < size; ++i){
		_val[i] = other[i];
		other[i] = 0;
	}
	return *this;
}


template <typename Elem, size_t size>
FixedVector<Elem,size>& FixedVector<Elem,size>::operator= 
	(const DynVector<Elem>& other){
	for(size_t i = 0; i < size; ++i){
		if (i < other.getSize())
			_val[i] = other[i];
		else
			_val[i] = 0;
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
void FixedVector<Elem,size>::input(istream& is) const {
	for (size_t i=0; i < size; ++i)
		is >> _val[i];
}

#endif   /* _FIXEDVECTOR_H_ */