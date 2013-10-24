/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 3
Date Assigned: 9/12/13
Due Date: 9/19/13 - 12:30
Description: The purpose of this program is to recieve a infix epression,
turn it into a postfix operation and calculate it.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <ctype.h>
#include "queue.h"
#include "variableData.h"

enum charTypes
{
	OPEN_PAREN,
	CLOSE_PAREN,
	OPERAND,
	OPERATOR,
	SPACE,
	GARBAGE
};

float calculatePostfixExpression(Queue<VariableData>& postfixExpression);
charTypes parser(char aCharacter);
string promptInfixExpression();
void makePostfixExpression(string infixExpression, Queue<VariableData>& expressionQueue);

#endif HEADER_H