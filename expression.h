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
	 ~Expression() = default; //Expression is a polymorphic class

	 

	//clone
	 //Expression* clone() = 0; //objects of class Expr. can create copies of themselves

	//To evaluate an expression
	//virtual double evaluate() const = 0;

	//bool isRoot(int x) const;

	friend ostream& operator<<(ostream &os, const Expression &e);

	//double operator()(const double d) const;

protected:
	//Constructor
	Expression() = default;

	//Copy constructor
	Expression(const Expression&) = default;

	//display
	virtual void display(ostream &os) const = 0;

	//Assignment operator
	Expression& operator=(const Expression&) = default;

};



#endif
