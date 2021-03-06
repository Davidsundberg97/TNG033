/*************************
* Class Expression       *
* TNG033: Lab 2          *
**************************/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>

using namespace std;

const double EPSILON = 1.0e-5;


class Expression
{

public:

	//Destructor
	virtual ~Expression() = default; //Expression is a polymorphic class

	 

	//clone
	virtual Expression* clone() const = 0; //objects of class Expr. can create copies of themselves

	//To evaluate an expression
	//virtual double evaluate() const = 0;

	bool isRoot(const double x) const ;

	friend ostream& operator<<(ostream &os, const Expression &e);

	virtual double operator()(const double d) const = 0;

protected:
	//Constructor
	Expression() = default;

	//Copy constructor
	Expression(const Expression&) = default;

	//display
	virtual void display(ostream &os) const = 0;

	//Assignment operator
	Expression& operator=(const Expression&) = default;

	//virtual double operator()(const double d) const = 0;

};



#endif
