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
	double a[2] = { 0,1 };
	E = new Polynomial(1, a);
}


Logarithm::Logarithm(const Expression &a, double c1, double c2, int base)
	: Expression(), E{ a.clone() }, c1{ c1 }, c2{ c2 }, base{ base }{

}

Logarithm* Logarithm::clone() const {
	return new Logarithm(*E,c1, c2,base);
}

double Logarithm::operator()(const double d) const
{
	return 0.0;
}

void Logarithm::display(ostream &os) const {

	if (abs(c1) < EPSILON)
	{
		os << c2 << "*Log_" << base << "(" << *E << ")";
	}
	else {
		os << c1 << " + " << c2 << "*Log_" << base << "(" << *E << ")";

	}
	
}


//ADD implementation of the member functions for class Logarithm
