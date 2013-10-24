/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 2
Date Assigned: 9/5/13
Due Date: 9/12/13 - 12:30
Description: The purpose of this program is to recieve two polynomials from the user and add them together using a linkedlist backbone.
Certification of Authenticity:
I certify that this assignment is entirely my own work, with collaboration from West Hall study group*/

#ifndef HEADER_H
#define HEADER_H

#include <string>
#include "linkedList.h"
#include "term.h"

using namespace std;

void addPolynomials(LinkedList<Term>& poly1, LinkedList<Term>& poly2, LinkedList<Term>& sumPoly);
Term createTerm(const string term);
void displayPolynomial(LinkedList<Term>& listToDisplay);
string getPolynomial();
void populateLLWithPolynomial(LinkedList<Term>& aLinkedList);

#endif HEADER_H