/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"

//pointers?
Polynomial::Polynomial(int d, double *a[])
	:Expression(), degree{ d }, coeff{ new double[d + 1] }
{
	for (int i = 0; i < degree + 1; i++) {
		coeff[i] = a[i];
	}
}

Polynomial::Polynomial(double *c)
	: degree{ 0 }, coeff{ new double[1] }
{
	coeff[degree] = c;
}

/* COPY CONSTRUCTOR
Polynomial::Polynomial(const Polynomial& source)
	: degree{ source.degree }, coeff{ new double[source.degree] }
{
	//Make deep copys
}

// Assignment operator
Polynomial& Polynomial::operator=(const Polynomial& p)
{
	Polynomial _copy(p);

	//swap header (pointer to list), the rest of the
	//pointers are correct, because of deep copy
	//swap(head, _copy.head);

	return *this;
}*/

int Polynomial::operator[](int i) const
{
	return 0;
}



//Polynomial Polynomial::operator+(const Polynomial& b) const {
//
//	Polynomial _copy(b);
//
//	return _copy;
//
//}
//
//
//
//Polynomial Polynomial::operator+(double d) const {
//
//	Polynomial _copy(*this);
//
//	// _copy + d 
//
//	return _copy;
//
//}
//
//int Polynomial::operator[](int i) const {
//
//	return coeff[i];
//
//}

//ADD implementation of the member functions for class Polynomial
