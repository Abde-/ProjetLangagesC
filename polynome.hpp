#ifndef _POLYNOME_H_
#define _POLYNOME_H_

template <typename Elem>
class Polynome: Vector<Elem>{
	int _degree;
public:
	virtual int getDegree();

	virtual void print(ostream&) const override;
	virtual void input(istream&) const override;
};

template <typename Elem>
int Polynome<Elem>::getDegree(){
	// get degree for positive (how to do negative?)
	int degree = 0;
	for(size_t i = 0; i < this->getSize(); ++i)
		if (this->getVal()[i]) degree = i;

	return degree;
}

#endif	/* _POLYNOME_H_ */