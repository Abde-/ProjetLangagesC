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

	virtual void print(ostream& os) const override { Polynome<Elem>::print(os); }
	virtual void input(istream& is) const override;

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

template <typename Elem>
void DynPolynome<Elem>::input(istream& is) const{
	int degree;
	cout << "Degree:"; cin >> degree;

	if (degree <= this->getSize()){
		for (int i = 0; i < degree; ++i)
			is >> this->getVal()[i];
	}
	else
		cout << "Degree not valid. (do resize)";
	cout << "hello" << endl;
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