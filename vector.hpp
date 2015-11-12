#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>	//istream, ostream
#include <cstddef>	//ptrdiff_t, size_t

using namespace std;

//----------------------------------------------------------------------------
// Template pour type d'element dans le vecteur / type de vecteur à renvoyer
template <typename Elem, typename VectRes>
// Classe abstraite Vector - pere de tous les autres
class Vector {
public:

	virtual size_t getSize() const = 0;

	virtual const Elem& operator[] (ptrdiff_t) const = 0;	//R-value
	virtual Elem& operator[] (ptrdiff_t) = 0;				//L-value

    virtual VectRes operator+ (const VectRes) = 0;				//binaire
    virtual VectRes operator+ () = 0;						//unaire
	virtual VectRes& operator+=(const VectRes) = 0;
	virtual VectRes operator- (const VectRes) = 0;				//binaire
	virtual VectRes operator- () = 0;						//unaire
	virtual VectRes& operator-=(const VectRes) = 0;
	virtual VectRes operator* (const Elem) = 0;
	virtual VectRes& operator*=(const Elem) = 0;

	friend ostream& operator<< (ostream& os, const Vector<Elem,VectRes>& v) {
		v.print(os);
		return os;
	};
	
	friend istream& operator>> (istream& is, const Vector<Elem,VectRes>& v) {
		v.input(is);
		return is;
	};

	virtual void print(ostream&) const = 0; //methodes pour rendre iostream virtuellement pure
	virtual void input(istream&) = 0;

	virtual ~Vector<Elem,VectRes>() = default;
	
};
//----------------------------------------------------------------------------

#endif   /* _VECTOR_H_ */