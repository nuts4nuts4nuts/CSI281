/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 2
Date Assigned: 9/5/13
Due Date: 9/12/13 - 12:30
Description: The purpose of this program is to recieve two polynomials from the user and add them together using a linkedlist backbone.
Certification of Authenticity:
I certify that this assignment is entirely my own work, with collaboration from West Hall study group*/

#include <string>
#include <sstream>
#include <cstddef>
#include <iostream>
#include "header.h"
#include "linkedList.h"
#include "term.h"

using namespace std;

/*      Pre:  We have two polynomials stored in linkedlists that we would like to add together
 *     Post:  We have a third linked list which is the sum of the first two
 *  Purpose:  To add two polynomials together
 *****************************************************************************/
void addPolynomials(LinkedList<Term>& poly1, LinkedList<Term>& poly2, LinkedList<Term>& sumPoly)
{
	int firstTerm = 0;

	while(!poly1.isEmpty() && !poly2.isEmpty())
	{
		if( poly1.getData(firstTerm) > poly2.getData(firstTerm) )
		{
			Term newTerm = poly1.getData(firstTerm);
			sumPoly.insert(newTerm);

			poly1.removeElementAt(firstTerm);
		}
		else if( poly1.getData(firstTerm) < poly2.getData(firstTerm) )
		{
			Term newTerm = poly2.getData(firstTerm);
			sumPoly.insert(newTerm);

			poly2.removeElementAt(firstTerm);
		}
		else
		{
			Term newTerm = poly1.getData(firstTerm);
			int newCoefficient = poly1.getData(firstTerm).getCoefficient() + poly2.getData(firstTerm).getCoefficient();

			newTerm.setCoefficient(newCoefficient);
			sumPoly.insert(newTerm);

			poly1.removeElementAt(firstTerm);
			poly2.removeElementAt(firstTerm);
		}
	}

	if( !poly1.isEmpty() )
	{
		while( !poly1.isEmpty() )
		{
			Term newTerm = poly1.getData(firstTerm);
			sumPoly.insert(newTerm);

			poly1.removeElementAt(firstTerm);
		}
	}
	else if( !poly2.isEmpty() )
	{
		while( !poly2.isEmpty() )
		{
			Term newTerm = poly2.getData(firstTerm);
			sumPoly.insert(newTerm);

			poly2.removeElementAt(firstTerm);
		}
	}
}

/*      Pre:  We have a string that we would like to turn into a term
 *     Post:  We have a term with which to do whatever we please
 *  Purpose:  To turn a string into a term
 *****************************************************************************/
Term createTerm(const string term)
{
	int coefficient = 0;
	int exponent = 0;
	char variable = ' ';
	bool isVariable = false;

	for(size_t i = 0; i < term.length(); i++)
	{
		if(isdigit(term.at(i)) && !isVariable)
		{
			coefficient *= 10; //push everything over one digit
			coefficient += (term.at(i) - '0'); //turns the character of a digit into the actual number
		}
		else if(isalpha(term.at(i)))
		{
			variable = term.at(i);
			isVariable = true;
		}
		else if(isdigit(term.at(i)) && isVariable)
		{
			exponent *= 10; //push everything over one digit
			exponent += (term.at(i) - '0'); //turns the character of a digit into the actual number
		}
	}

	Term theTerm;
	if(coefficient)
	{
		theTerm.setCoefficient(coefficient);
	}
	if(exponent)
	{
		theTerm.setExponent(exponent);
	}

	theTerm.setVariable(variable);

	return theTerm;
}

/*      Pre:  We have a polynomial
 *     Post:  Anything
 *  Purpose:  To display a polynomial stored in a linkedlist in a pleasing manner
 *****************************************************************************/
void displayPolynomial(LinkedList<Term>& listToDisplay)
{
	for( int i = 0; i < listToDisplay.getCount(); i++ )
	{
		if( i == listToDisplay.getCount() - 1 )
		{
			cout << listToDisplay.getData(i) << endl;
		}
		else
		{
			cout << listToDisplay.getData(i) << " + ";
		}
	}
}

/*      Pre:  We would like the user to enter a polynomial
 *     Post:  We have a polynomial as a string
 *  Purpose:  To prompt the user to enter a polynomial, recieve it, and return it
 *****************************************************************************/
string getPolynomial()
{
	string userPolynomial;

	cout << "Please enter your polynomial: ";
	getline(cin, userPolynomial);
	return userPolynomial;
}

/*      Pre:  None
 *     Post:  We have a linked list with a polynomial in it
 *  Purpose:  To get a string polynomial and turn it into a linkedlist
 *****************************************************************************/
void populateLLWithPolynomial(LinkedList<Term>& aLinkedList)
{
	string userPolynomial;
	userPolynomial = getPolynomial();

	char space = ' ';
	bool termTime = true;

	size_t secondSpace = 0;
	size_t firstSpace = 0;
	while(secondSpace != string::npos)
	{
		firstSpace = secondSpace;
		secondSpace = userPolynomial.find_first_of(space, secondSpace+1);

		string culledTerm = userPolynomial.substr(firstSpace, secondSpace - firstSpace);

		if(termTime)
		{
			Term aTerm;
			aTerm = createTerm(culledTerm);

			aLinkedList.insert(aTerm);

			termTime = false;
		}
		else
		{
			termTime = true;
		}
	}
}