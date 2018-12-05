/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"
#include <cmath>

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
		if (i == 0) os << coeff[i] ;
		else os << " + "<< coeff[i] << "x^" << i;
	
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

Polynomial* Polynomial::clone() const {
	
	
	
	return new Polynomial(degree-1, coeff);
}


// d ska vara  f(x) = 2.2 + 3.3x + 4.4x^2 <=> f(d) = 2.2+ 3.3*d + 4.4*d^2
//vill loopa d^i loopar degree längd
double Polynomial::operator()(const double d) const
{
	double ans = 0;
	for (int i = 0; i < degree; i++) {
		ans = ans + coeff[i] * pow(d , i);
	}

	// TODO: insert return statement here

	return ans;
}

//bool Polynomial::isRoot(double test) 
//{
//	
//		if (operator()(test) == 0)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	
//	
//}



// Assignment operator
Polynomial& Polynomial::operator=(const Polynomial& p)
{
	Polynomial _copy(p);

	//
	swap(this->coeff, _copy.coeff);
	swap(this->degree, _copy.degree);


	

	return *this;

	/*degree = p.degree;

	if (coeff != p.coeff) {
		delete[] coeff;
		coeff = new double[degree];

		for (int i = 0; i < degree; i++) {
			coeff[i] = p.coeff[i];
		}

		return *this;
	}*/

	
}

double &Polynomial::operator[](int i) const
{

	
	return coeff[i];
}



Polynomial Polynomial::operator+(const Polynomial& b) const {

	Polynomial _copy(b);
	Polynomial _thiscopy(*this);
	Polynomial _thiscopy2(*this);
	int i = 0;


	if (b.degree < degree) {

		for (i; i < b.degree; i++) {

			_thiscopy2.coeff[i] = _copy.coeff[i] + _thiscopy.coeff[i];

		}
		for (i; i < degree; i++) {

			_thiscopy2.coeff[i] = _thiscopy.coeff[i];

		}
	}
	else {

		for (i; i < degree; i++) {

			_thiscopy2.coeff[i] = _copy.coeff[i] + _thiscopy.coeff[i];

		}
		for (i; i < b.degree; i++) {

			_thiscopy2.coeff[i] = _copy.coeff[i];

		}
	}

	return _thiscopy2;
}
//
//
////
 Polynomial operator+(const double d, Polynomial &P)   {

	Polynomial _copy(P);
	Polynomial doublepol(d);
	

	

	doublepol = _copy + doublepol;

		return doublepol;

}

 Polynomial::~Polynomial() {

	 delete[] coeff;
	 coeff = nullptr;
	 degree = 0;
 }
////
//int Polynomial::operator[](int i) const {
//
//	return coeff[i];
//
//}

//ADD implementation of the member functions for class Polynomial
