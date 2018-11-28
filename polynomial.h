/*************************
* Class Polynomial       *
* TNG033: Lab 2          *
**************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

#include "expression.h"


class Polynomial : public Expression
{
public:
	//Constructor
	Polynomial(int d, double *a[]);

	//conversion constructor constant
	Polynomial(double *c);

	// COPY CONSTRUCTOR
	Polynomial(const Polynomial& source);

	//assignment operator
	/*Polynomial& operator=(const Polynomial& p);

	Polynomial operator+(const Polynomial& b) const;

	Polynomial operator+(double d) const;*/

	int operator[](int i) const;


protected:
	const int degree;
	const double *coeff[];
};


#endif
