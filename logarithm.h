/*************************
* Class Logarithm        *
* TNG033: Lab 2          *
**************************/


#ifndef LOGARITHM_H
#define LOGARITHM_H

#include <iostream>

#include "expression.h"

using namespace std;

class Logarithm : public Expression
{

public:
	//Constructor default
	Logarithm();

	Logarithm(const Expression &E, double c1, double c2, int base);

	//clone()
	Logarithm *clone() const override;

	Logarithm& operator=(const Logarithm& L);

	//operator() assign
	double operator()(const double d) const override;

	//bool isRoot(double test);



private:
	Expression *E;

		double c1;
		double c2;
		int base;

		//display
		void display(ostream &os) const override;


};

#endif
