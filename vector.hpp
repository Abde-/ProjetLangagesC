#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>	//istream, ostream
#include <cstddef>	//ptrdiff_t, size_t

using namespace std;

//----------------------------------------------------------------------------

template <typename Elem>
class Vector{
public:
	virtual size_t getSize() const = 0;
	virtual Elem* getVal() const = 0;
	virtual bool resize(size_t) = 0;

	virtual const Elem& operator[] (ptrdiff_t) const;
	virtual Elem& operator[] (ptrdiff_t);

	friend ostream& operator<< (ostream& os, const Vector<Elem>& v) {
		v.print(os);
		return os;
	};
	
	friend istream& operator>> (istream& is, Vector<Elem>& v) {
		v.input(is);
		return is;
	};

	virtual void print(ostream&) const = 0; //methodes pour rendre iostream virtuellement pure
	virtual void input(istream&) = 0;

	virtual ~Vector<Elem>() = default;
};

//----------------------------------------------------------------------------

template <typename Elem>
const Elem& Vector<Elem>::operator[] (ptrdiff_t index) const{
	if (size_t(index) >= this->getSize())
		throw out_of_range("Vector: Index Out of Range");
	return this->getVal()[index];
}

template <typename Elem>
Elem& Vector<Elem>::operator[] (ptrdiff_t index){
	if (size_t(index) >= this->getSize())
		throw out_of_range("Vector: Index Out of Range");
	return this->getVal()[index];
}

template <typename VectRes>
//unary
VectRes operator+ (const VectRes& first){ 
	return first; 
}

template <typename VectRes>
//binary
VectRes operator+ (const VectRes& first, const VectRes& second){
	size_t newSize;

	if (first.getSize() > second.getSize())
		newSize = first.getSize();
	else{ newSize = second.getSize(); }

	VectRes newVect;
	newVect.resize(newSize);

	for (size_t i = 0; i < newSize; ++i)
		newVect[i] = first[i] + second[i];
	return newVect;
}

template <typename VectRes>
VectRes& operator+= (VectRes& first, const VectRes& second){
	first = first + second;
	return first;
}

template <typename VectRes>
VectRes operator- (const VectRes& first){
	VectRes newVect;
	newVect.resize(first.getSize());
	for (size_t i = 0; i < first.getSize(); ++i)
		newVect[i] = -first[i];
	return newVect;
}

template <typename VectRes>
VectRes operator- (const VectRes& first, const VectRes& second){
    size_t newSize;

	if (first.getSize() > second.getSize())
		newSize = first.getSize();
	else{ newSize = second.getSize(); }

	VectRes newVect;
	newVect.resize(newSize);

	for (size_t i = 0; i < newSize; ++i)
		newVect[i] = first[i] - second[i];
	return newVect;
}

template <typename VectRes>
VectRes& operator-= (VectRes& first, const VectRes& second){
	first = first - second;
	return first;
}

#endif	/* _VECTOR_H_ */