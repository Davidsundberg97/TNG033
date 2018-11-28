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
	Polynomial(int d, const double *a);

	//conversion constructor constant
	/*Polynomial(double *c);*/

	// COPY CONSTRUCTOR
	//Polynomial(const Polynomial& source);

	//assignment operator
	/*Polynomial& operator=(const Polynomial& p);

	Polynomial operator+(const Polynomial& b) const;

	Polynomial operator+(double d) const;*/

	/*int operator[](int i) const;*/


private:
	int degree;
	 double *coeff;
	 void display(ostream &os) const override;
};


#endif
