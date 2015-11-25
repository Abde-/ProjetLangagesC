#ifndef _DYNPOLYNOME_H_
#define _DYNPOLYNOME_H_

#include "dynvector.hpp"
#include "polynome.hpp"

//----------------------------------------------------------------------------

template <typename Elem>
class DynPolynome: public DynVector<Elem>, public Polynome<Elem>{
public:
	// initialisées dans dynyvector, ainsi que l'assignation etc...
	DynPolynome() {}
	DynPolynome(const Elem&); //constructeur conversion

	virtual size_t getSize() const override { return DynVector<Elem>::getSize(); }
	virtual bool resize(size_t x) override{ return DynVector<Elem>::resize(x); }
	virtual Elem* getVal() const override { return DynVector<Elem>::getVal(); }

	virtual DynPolynome<Elem> operator* ( const Elem& );
	virtual DynPolynome<Elem>& operator*= ( const Elem& );

	virtual void print(ostream& os) const override { Polynome<Elem>::print(os); }
	virtual void input(istream& is) override { Polynome<Elem>::input(is); }

	DynPolynome<Elem>& operator= (const Elem&);

};

//----------------------------------------------------------------------------

template <typename Elem>
DynPolynome<Elem>::DynPolynome(const Elem& other){
	if (other == 0)
		this->resize(0);
	else{
		this->resize(1);
		(*this)[0] = other;
	}
}

template <typename Elem>
DynPolynome<Elem> DynPolynome<Elem>::operator* (const Elem& item){
	DynPolynome<Elem> newVect;
	newVect.resize(this->getSize());

	for (int i = 0; i < this->getDegree(); ++i)
		newVect[i] = (*this)[i] * item;
	return newVect;
}

template <typename Elem>
DynPolynome<Elem> operator* (const Elem& item, const DynPolynome<Elem>& vector){
	DynPolynome<Elem> newVect;
	newVect.resize(vector.getSize());

	for (size_t i = 0; i < vector.getDegree(); ++i)
		newVect[i] = vector[i] * item;
	return newVect;
}

template <typename Elem>
DynPolynome<Elem>& DynPolynome<Elem>::operator*= (const Elem& item){
	for (int i = 0; i < this->getDegree(); ++i)
		(*this)[i] = (*this)[i] * item;
	return *this;
}

template <typename Elem>
DynPolynome<Elem>& DynPolynome<Elem>::operator= (const Elem& other){
	if (other == 0)
		this->resize(0);
	else{
		this->resize(1);
		(*this)[0] = other;
	}
	return *this;
}

#endif	/* _DYNPOLYNOME_H_ */