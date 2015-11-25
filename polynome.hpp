#ifndef _POLYNOME_H_
#define _POLYNOME_H_

#include "vector.hpp"

//----------------------------------------------------------------------------

template <typename Elem>
class Polynome: virtual public Vector<Elem>{
public:
	virtual int getDegree() const;

	virtual Elem operator() (const Elem& item);

	virtual void print(ostream&) const override;
	virtual void input(istream& is) override;

	virtual ~Polynome<Elem>() = default;
};

//----------------------------------------------------------------------------

template <typename Elem>
int Polynome<Elem>::getDegree() const{
	// generate degree with vector
	int degree = -1;
	for(size_t i = 0; i < this->getSize(); ++i)
		if ((*this)[i]) degree = i;
	return degree;
}

template <typename PolRes>
//binary
PolRes operator* (const PolRes& first, const PolRes& second){
	PolRes newPol; int firstSize(first.getDegree()), secondSize(second.getDegree());
	if (firstSize != -1 && secondSize != -1){
		newPol.resize(firstSize + secondSize);

		for(int i = 0; i < firstSize; ++i){
			for(int j = 0; j < secondSize; ++j){
				newPol[i+j] += (first[i] * second[j]);
			}
		}
	}
	return newPol;
}

template <typename PolRes>
PolRes& operator*= (PolRes& first, const PolRes& second){
	first = first * second;
	return first;
}

template <typename Elem>
void Polynome<Elem>::print(ostream& os) const{

	int degree(this->getDegree());
	if (degree != -1){
		for (int i = degree; i <= degree && i >= 0; --i){
			if ((*this)[i] != 0){
				if ((*this)[i] > 0 && i != degree)
					os << '+';
				os << (*this)[i];
				if(i != 0) os << 'x'<< '^' << i ;
				os << ' ';
			}
		}
	}
	else
		os << '0';
}

template <typename Elem>
void Polynome<Elem>::input(istream& is){
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
Elem Polynome<Elem>::operator() (const Elem& item){
	int degree(this->getDegree()); Elem temp((*this)[degree]);

	for (int i = degree-1; i <= degree && i >= 0; --i){
		temp = temp*item + (*this)[i];
	}
	return temp;
}

#endif	/* _POLYNOME_H_ */