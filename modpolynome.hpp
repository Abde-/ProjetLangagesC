#ifndef _MODPOLYNOME_H_
#define _MODPOLYNOME_H_

template <typename Elem, size_t size, const DynPolynome<Elem>& divisor>
class ModPolynome: public FixedVector<Elem,size>, public Polynome<Elem>{
public:



};

#endif	/* _MODPOLYNOME_H_ */