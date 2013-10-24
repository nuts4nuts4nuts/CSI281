/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 2
Date Assigned: 9/5/13
Due Date: 9/12/13 - 12:30
Description: The purpose of this program is to recieve two polynomials from the user and add them together using a linkedlist backbone.
Certification of Authenticity:
I certify that this assignment is entirely my own work, with collaboration from West Hall study group*/

#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;

class Term
{
	friend ostream& operator<<(ostream& out, Term theTerm);
	friend istream& operator>>(istream& in, Term& theTerm);

private:
	int mCoefficient;
	int mExponent;
	char mVariable;
	
public:
	Term();
	Term(int coefficient, int exponent, char variable);
	~Term();

	inline int getCoefficient(){ return mCoefficient; }
	inline int getExponent(){ return mExponent; }
	inline char getVariable(){ return mVariable; }

	inline void setCoefficient(int coeffecient){ mCoefficient = coeffecient; }
	inline void setExponent(int exponent){ mExponent = exponent; }
	inline void setVariable(char variable){ mVariable = variable; }

	Term operator+(Term& rhs);
	bool operator<(Term& rhs);
	bool operator>(Term& rhs);
	bool operator<=(Term& rhs);
	bool operator>=(Term& rhs);
};

#endif TERM_H