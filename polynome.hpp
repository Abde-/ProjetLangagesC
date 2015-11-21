#ifndef _POLYNOME_H_
#define _POLYNOME_H_

#include "vector.hpp"

template <typename Elem>
class Polynome: virtual public Vector<Elem>{
public:
	virtual int getDegree() const;

	virtual Elem operator() (const Elem& item);

	virtual void print(ostream&) const override;
};

template <typename Elem>
int Polynome<Elem>::getDegree() const{
	// generate degree with vector
	int degree = -1;
	for(size_t i = 0; i < this->getSize(); ++i)
		if ((*this)[i]) degree = i;

	return degree;
}

template <typename Elem>
void Polynome<Elem>::print(ostream& os) const{
	int degree(this->getDegree());
	if (degree != -1){
		for (size_t i = degree; i >= 0; --i){
			if ((*this)[i] > 0){
				if (i == degree)
					os << '+';
				os << (*this)[i] << '^' << degree-i << ' ';
			}
			else
				os << '-' << -(*this)[i] << '^' << degree-i << ' ';
		}
	}
	else
		os << '0';
}

template <typename PolRes, typename Elem>
PolRes operator* (const Polynome<Elem>& polyn, const Elem& item){
	PolRes newPol;

	for (size_t i = 0; i < polyn.getDegree(); ++i)
		newPol[i] = polyn[i] * item;
	return newPol;
}

template <typename Elem>
Elem Polynome<Elem>::operator() (const Elem& item){
	int degree(this->getDegree()); Elem temp((*this)[degree]);

	for (size_t i = degree-1; i >= 0; --i){
		temp = temp*item + (*this)[i];
	}
	return temp;
}

#endif	/* _POLYNOME_H_ */