#ifndef _MODPOLYNOME_H_
#define _MODPOLYNOME_H_

#include "fixedvector.hpp"
#include "polynome.hpp"
#include "dynpolynome.hpp"

template <typename Elem, size_t size, const DynPolynome<Elem>& divi>
class ModPolynome: public FixedVector<Elem,size>, public Polynome<Elem>{
	DynPolynome<Elem> divisor;

public:
	ModPolynome();

	size_t getSize() override { return FixedVector<Elem,size>::getSize(); }
	virtual bool resize(size_t x) override{ return FixedVector<Elem,size>::resize(x); }
	virtual Elem* getVal() const override { return FixedVector<Elem,size>::getVal(); }


	virtual void print(ostream& os) const override { Polynome<Elem>::print(os); }
	virtual void input(istream& is) override { Polynome<Elem>::input(is); }

	
};

template <typename Elem, size_t size, const DynPolynome<Elem>& divi>
ModPolynome<Elem,size,divi>::ModPolynome(){
	DynPolynome<Elem> xn;
	xn.setSize(size+1); xn[size] = 1;
	divisor = xn - divi;
}

#endif	/* _MODPOLYNOME_H_ */