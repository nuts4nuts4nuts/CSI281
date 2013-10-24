/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 3
Date Assigned: 9/12/13
Due Date: 9/19/13 - 12:30
Description: The purpose of this program is to recieve a infix epression,
turn it into a postfix operation and calculate it.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#include <iostream>
#include <string>
#include <cmath>
#include "header.h"
#include "queue.h"
#include "stack.h"
#include "variableData.h"

using namespace std;

float calculatePostfixExpression(Queue<VariableData>& postfixExpression)
{
	Stack<VariableData> expressionStack;
	float result = (float)HUGE_VAL;

	float lhsOperand;
	float rhsOperand;
	char theOperator;

	while(!postfixExpression.isEmpty())
	{
		expressionStack.push(postfixExpression.dequeue());

		if(parser(expressionStack.getData(0).getEverythingElse()) == OPERATOR)
		{
			if(!expressionStack.isEmpty())
			{
				theOperator = expressionStack.pop().getEverythingElse();
			}
			else
			{
				result = (float)HUGE_VAL;
				return result;
			}

			if(!expressionStack.isEmpty())
			{
				rhsOperand = expressionStack.pop().getOperand();
			}
			else
			{
				result = (float)HUGE_VAL;
				return result;
			}

			if(!expressionStack.isEmpty())
			{
				lhsOperand = expressionStack.pop().getOperand();
			}
			else
			{
				result = (float)HUGE_VAL;
				return result;
			}

			switch(theOperator)
			{
			case '+':
				result = lhsOperand + rhsOperand;
				break;
			case '-':
				result = lhsOperand - rhsOperand;
				break;
			case '*':
				result = lhsOperand * rhsOperand;
				break;
			case '/':
				if( rhsOperand == 0 )
				{
					result = (float)HUGE_VAL;
					return result;
				}
				result = lhsOperand / rhsOperand;
				break;
			case '^':
				result = pow(lhsOperand, rhsOperand);
				break;
			}

			expressionStack.push(result);
		}
		else if(parser(expressionStack.getData(0).getEverythingElse()) == GARBAGE)
		{
			result = (float)HUGE_VAL;
			return result;
		}
	}

	if( expressionStack.getCount() > 1)
	{
		result = (float)HUGE_VAL;
	}
	return result;
}

charTypes parser(char aCharacter)
{
	if(isdigit(aCharacter))
	{
		return OPERAND;
	}
	else if(aCharacter == '+' || aCharacter == '-' || aCharacter == '*'
			|| aCharacter == '/' || aCharacter == '^')
	{
		return OPERATOR;
	}
	else if(aCharacter == '(')
	{
		return OPEN_PAREN;
	}
	else if(aCharacter == ')')
	{
		return CLOSE_PAREN;
	}
	else if(isspace(aCharacter))
	{
		return SPACE;
	}
	else
	{
		return GARBAGE;
	}
}

string promptInfixExpression()
{
	string userExpression;

	cout << "Please enter a fully parenthesized expression." << endl;

	getline(cin, userExpression);

	return userExpression;
}

void makePostfixExpression(string infixExpression, Queue<VariableData>& expressionQueue)
{
	Stack<VariableData> operatorStack;
	float operand = 0;
	charTypes currentCharType;

	for(size_t i = 0; i < infixExpression.length(); i++)
	{
		currentCharType = parser(infixExpression.at(i));
		operand = 0;

		switch(currentCharType)
		{
		case OPERAND:
			while(currentCharType == OPERAND && i != infixExpression.length())
			{
				operand *= 10; //move over digit
				operand += infixExpression.at(i) - '0'; //add number character as actual number

				i++;
				if( i != infixExpression.length() )
				{
					currentCharType = parser(infixExpression.at(i));
				}
			}

			i--;
			expressionQueue.enqueue(operand);
			break;
		case OPERATOR:
			operatorStack.push(infixExpression.at(i));
			break;
		case CLOSE_PAREN:
			if(!operatorStack.isEmpty())
			{
				expressionQueue.enqueue(operatorStack.pop());
			}
			else
			{
				return;
			}
			break;
		case GARBAGE:
			{
				expressionQueue.enqueue(infixExpression.at(i));
				return;
			}
		}
	}

	if(!operatorStack.isEmpty())
	{
		VariableData trashData('a');
		expressionQueue.enqueue(trashData); //Throw some trash in there for error checking purposes
	}
}