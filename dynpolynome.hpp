#ifndef _DYNPOLYNOME_H_
#define _DYNPOLYNOME_H_

#include "dynvector.hpp"
#include "polynome.hpp"

template <typename Elem>
class DynPolynome: public DynVector<Elem>, public Polynome<Elem>{
public:
	// constructor par defaut non défini car toutes variables
	// initialisées dans dynyvector, ainsi que l'assignation etc...
	DynPolynome() { DynVector<Elem>(); }
	DynPolynome(const Elem&); //constructeur conversion

	virtual size_t getSize() const override { return DynVector<Elem>::getSize(); }
	virtual bool resize(size_t x) override{ return DynVector<Elem>::resize(x); }
	virtual Elem* getVal() const override { return DynVector<Elem>::getVal(); }

	//DynPolynome operator+(const DynPolynome& other);

	virtual void print(ostream& os) const override { Polynome<Elem>::print(os); }
	virtual void input(istream& is) override;

	DynPolynome<Elem>& operator= (const Elem&);

};

template <typename Elem>
DynPolynome<Elem>::DynPolynome(const Elem& other){
	if (other == 0)
		this->resize(0);
	else{
		this->resize(1);
		(*this)[0] = other;
	}
}

//template <typename Elem>
//DynPolynome<Elem> DynPolynome<Elem>::operator+(const DynPolynome& other){
//	size_t newSize;
//
//	if (this->getSize() > other.getSize())
//		newSize = this->getSize();
//	else{ newSize = other.getSize(); }
//
//	DynPolynome newVect;
//	newVect.resize(newSize);
//
//	for (size_t i = 0; i < newSize; ++i)
//		newVect[i] = this->getVal()[i] + other[i];
//	return newVect;
//}

template <typename Elem>
void DynPolynome<Elem>::input(istream& is){
	int degree; bool resizeable;
	cout << "Degree:"; cin >> degree;

	resizeable = this->resize(degree+1);

	if (resizeable){
		if(degree != -1){	
			for (int i = degree; i <= degree && i >= 0; --i)
				is >> (*this)[i];
			}
		else
			(*this)[0] = 0;
	}
	else{
		cout << "Degree not valid. (cannot resize)";
	}
}

template <typename Elem>
DynPolynome<Elem>& DynPolynome<Elem>::operator= (const Elem& other){
	if (other == 0)
		this->resize(0);
	else{
		this->resize(1);
		(*this)[0] = other;
	}
	return this;
}	


#endif	/* _DYNPOLYNOME_H_ */