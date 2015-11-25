#ifndef _MODPOLYNOME_H_
#define _MODPOLYNOME_H_

#include "fixedvector.hpp"
#include "polynome.hpp"
#include "dynpolynome.hpp"

//----------------------------------------------------------------------------

template <typename Elem, size_t degree, const DynPolynome<Elem>& divi>
class ModPolynome: public FixedVector<Elem,degree+1>, public Polynome<Elem>{
	DynPolynome<Elem> divisor;

public:
	ModPolynome();
	ModPolynome(const Elem&);

	virtual size_t getSize() const override { return FixedVector<Elem,degree+1>::getSize(); }
	virtual bool resize(size_t x) override{ return FixedVector<Elem,degree+1>::resize(x); }
	virtual Elem* getVal() const override { return FixedVector<Elem,degree+1>::getVal(); }

	virtual ModPolynome<Elem,degree,divi> operator* ( const ModPolynome<Elem,degree,divi>& );
	virtual ModPolynome<Elem,degree,divi> operator* ( const Elem& );
	virtual ModPolynome<Elem,degree,divi>& operator*= ( const Elem& );


	virtual void print(ostream& os) const override { Polynome<Elem>::print(os); }
	virtual void input(istream& is) override { Polynome<Elem>::input(is); }

	ModPolynome<Elem,degree,divi>& operator= (const Elem&);

};

//----------------------------------------------------------------------------

template <typename Elem, size_t degree, const DynPolynome<Elem>& divi>
ModPolynome<Elem,degree,divi>::ModPolynome(){
	if (divi.getDegree() >= degree)
		throw invalid_argument("ModPolynome: Divisor degree bigger than ModPolynome degree.");
	else{
		DynPolynome<Elem> xn;
		xn.resize(degree+1); xn[degree] = 1;
		divisor = xn - divi;
	}
}

template <typename Elem, size_t degree, const DynPolynome<Elem>& divi>
ModPolynome<Elem,degree,divi>::ModPolynome(const Elem& other){
	for(size_t i = 0; i <= degree; ++i){
		if (i == 0) (*this)[i] = other;
		else (*this)[i] = 0;
	}
}

template <typename Elem, size_t degree, const DynPolynome<Elem>& divi>
ModPolynome<Elem,degree,divi> ModPolynome<Elem,degree,divi>::operator* ( const ModPolynome<Elem,degree,divi>& ){
	//TODO
}

template <typename Elem, size_t degree, const DynPolynome<Elem>& divi>
ModPolynome<Elem,degree,divi> ModPolynome<Elem,degree,divi>::operator* (const Elem& item){
	ModPolynome<Elem,degree,divi> newVect;

	for (size_t i = 0; i <= degree; ++i)
		newVect[i] = (*this)[i] * item;
	return newVect;
}

template <typename Elem, size_t degree, const DynPolynome<Elem>& divi>
ModPolynome<Elem,degree,divi>& ModPolynome<Elem,degree,divi>::operator*= (const Elem& item){
	for (size_t i = 0; i <= degree; ++i)
		(*this)[i] = (*this)[i] * item;
	return *this;
}

template <typename Elem, size_t degree, const DynPolynome<Elem>& divi>
ModPolynome<Elem,degree,divi>& ModPolynome<Elem,degree,divi>::operator= (const Elem& other){
	for(size_t i = 0; i <= degree; ++i){
		if (i == 0) (*this)[i] = other;
		else (*this)[i] = 0;
	}
	return *this;
}

#endif	/* _MODPOLYNOME_H_ */