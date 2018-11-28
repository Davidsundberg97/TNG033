/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"

//pointers?
Polynomial::Polynomial(int d, const double *a)
	:Expression(), degree{ d +1}, coeff{ new double[degree] }
{
	for (int i = 0; i < degree; i++) {
		coeff[i] = a[i];
	}
}

void Polynomial::display(ostream & os) const // jlr loops / ifsatser
{
	
	
	for(int i = 0; i < degree; i++)
	{
		if (i == 0) os << coeff[i] << " + ";
		else os << coeff[i] << "x^" << i << " ";
	
	}
	
}


//convert double to plynomial
Polynomial::Polynomial(double c)
	: degree{ 1 }, coeff{ new double[degree] }
{
	coeff[0] = c;
}

//COPY CONSTRUCTOR
Polynomial::Polynomial(const Polynomial& source)
	: degree{ source.degree }, coeff{ new double[source.degree] }
{
	for (int i = 0; i < degree; i++) {
		coeff[i] = source.coeff[i];
	
	}	//Make deep copys
}

Polynomial &Polynomial::operator()(const double d) const
{
	// TODO: insert return statement here
}


/*
// Assignment operator
Polynomial& Polynomial::operator=(const Polynomial& p)
{
	Polynomial _copy(p);

	//swap header (pointer to list), the rest of the
	//pointers are correct, because of deep copy
	//swap(head, _copy.head);

	return *this;
}*/

//int Polynomial::operator[](int i) const
//{
//	return 0;
//}



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
