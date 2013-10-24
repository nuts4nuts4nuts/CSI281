/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 2
Date Assigned: 9/5/13
Due Date: 9/12/13 - 12:30
Description: The purpose of this program is to recieve two polynomials from the user and add them together using a linkedlist backbone.
Certification of Authenticity:
I certify that this assignment is entirely my own work, with collaboration from West Hall study group*/

#include <iostream>
#include "linkedList.h"
#include "term.h"
#include "header.h"

using namespace std;

int main()
{
	LinkedList<Term> firstPolynomial;
	populateLLWithPolynomial(firstPolynomial);

	LinkedList<Term> secondPolynomial;
	populateLLWithPolynomial(secondPolynomial);

	LinkedList<Term> finalPolynomial;
	addPolynomials(firstPolynomial, secondPolynomial, finalPolynomial);

	cout << "The sum of your polynomials is: ";
	displayPolynomial(finalPolynomial);

	system("pause");
	return 0;
}