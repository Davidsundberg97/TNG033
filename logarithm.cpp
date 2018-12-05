/*********************************************************
* Class Logarithm member functions implementation        *
* TNG033: Lab 2                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"
#include <cmath>
#include <algorithm>


Logarithm::Logarithm()
	: Expression(), c1{ 0 }, c2{ 1 }, base{ 2 }{
	const double a[2] = { 0,1 };
	E = new Polynomial(1, a);
}


Logarithm::Logarithm(const Expression &a, double c1, double c2, int base)
	: Expression(), E{ a.clone() }, c1{ c1 }, c2{ c2 }, base{ base }{

}

Logarithm* Logarithm::clone() const {
	return new Logarithm(*E,c1, c2,base);
}

Logarithm& Logarithm::operator=(const Logarithm& L) {

	
	/*swap(this->base, L.clone()->base);
	swap(this->c1, L.clone()->c1);
	swap(this->c2, L.clone()->c2);*/
	swap(this->E, L.clone()->E);

	return *this;

 }

double Logarithm::operator()(const double d) const
{
	double result = 0.0;

	result += c1 + ((c2* log(E->operator()(d)) / log(base)));

	//if (base == 2) {
	//	result = c1 + c2 * log10(E->operator()(d));
	//}
	//else if (base == 10) {

	//	result = c1 + c2 * log2(E->operator()(d));

	//}

	return result;
}

//bool Logarithm::isRoot(double test)
//{
//	//if (this->clone()->E->operator()(test) == 0)
//	//{
//	//	return true;
//	//}
//	//else
//	//{
//	//	return false;
//	//}
//
//}

void Logarithm::display(ostream &os) const {

	if (abs(c1) < EPSILON)
	{
		os << c2 << "*Log_" << base << "(" << *E << ")";
	}
	else {
		os << c1 << " + " << c2 << "*Log_" << base << "(" << *E << ")";

	}
	
}

Logarithm::~Logarithm() {
	c1 = 0;
	c2 = 0;
	base = 0;
	delete E;
	E = nullptr;

}


//ADD implementation of the member functions for class Logarithm
