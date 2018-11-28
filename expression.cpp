/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"



ostream& operator<<(ostream &os, const Expression &e) {
	e.display(os); //dynamic binding occurs
	return os;
}


//constructor




////is x a root to f(x) ?
//bool Expression::isRoot(int x) const
//{
//	//add code
//	return false;
//}

//operator()
//double Expression::operator()(const double d) const
//{
//	//add code 
//	
//	return 0.0;
//}

//ADD implementation of the member functions for class Expression

