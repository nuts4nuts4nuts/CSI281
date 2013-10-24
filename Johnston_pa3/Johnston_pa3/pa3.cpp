/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 3
Date Assigned: 9/12/13
Due Date: 9/19/13 - 12:30
Description: The purpose of this program is to recieve a infix epression,
turn it into a postfix operation and calculate it.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#include "queue.h"
#include "stack.h"
#include "header.h"
#include "variableData.h"

int main()
{
	
	Queue<VariableData> aQueue;
	string infixExpression;
	float result;

	infixExpression = promptInfixExpression();

	makePostfixExpression(infixExpression, aQueue);

	result = calculatePostfixExpression(aQueue);

	if(result == HUGE_VAL)
	{
		cout << "The expression was not valid.\n";
	}
	else
	{
		cout << result << endl;
	}
	system("pause");
	return 0;
}