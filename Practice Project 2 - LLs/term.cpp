/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 2
Date Assigned: 9/5/13
Due Date: 9/12/13 - 12:30
Description: The purpose of this program is to recieve two polynomials from the user and add them together using a linkedlist backbone.
Certification of Authenticity:
I certify that this assignment is entirely my own work, with collaboration from West Hall study group*/

#include "term.h"
#include <string>

Term::Term()
{
	mCoefficient = 1;
	mExponent = 1;
	mVariable = ' ';
}

Term::Term(int coefficient, int exponent, char variable)
{
	mCoefficient = coefficient;
	mExponent = exponent;
	mVariable = variable;
}

Term::~Term()
{

}

Term Term::operator+(Term& rhs)
{
	int newCoefficient;
	newCoefficient = this->getCoefficient() + rhs.getCoefficient();

	Term sumTerm(newCoefficient, this->getExponent(), this->getVariable());
	return sumTerm;
}

bool Term::operator<(Term& rhs)
{
	if(this->getExponent() < rhs.getExponent())
	{
		return true;
	}

	if(this->getExponent() == rhs.getExponent())
	{
		if(this->getVariable() < rhs.getVariable())
		{
			return true;
		}
	}
	return false;
}

bool Term::operator>(Term& rhs)
{
	if(this->getExponent() > rhs.getExponent())
	{
		return true;
	}

	if(this->getExponent() == rhs.getExponent())
	{
		if(this->getVariable() > rhs.getVariable())
		{
			return true;
		}
	}
	return false;
}

bool Term::operator<=(Term& rhs)
{
	if(this->getExponent() <= rhs.getExponent())
	{
		return true;
	}
	return false;
}

bool Term::operator>=(Term& rhs)
{
	if(this->getExponent() >= rhs.getExponent())
	{
		return true;
	}
	return false;
}

ostream& operator<<(ostream& out, Term theTerm)
{
	if(theTerm.getCoefficient() > 1 || (theTerm.getCoefficient() > 0 && theTerm.getVariable() == ' '))
	{
		out << theTerm.getCoefficient();
	}

	if(theTerm.getVariable() != ' ')
	{
		out << theTerm.getVariable();
	}

	if(theTerm.getExponent() > 1)
	{
		out << theTerm.getExponent();
	}

	return out;
}