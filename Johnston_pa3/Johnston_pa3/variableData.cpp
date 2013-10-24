/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 3
Date Assigned: 9/12/13
Due Date: 9/19/13 - 12:30
Description: The purpose of this program is to recieve a infix epression,
turn it into a postfix operation and calculate it.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#include "variableData.h"

VariableData::VariableData()
{
	mOperand = 0;
	mEverythingElse = '(';
}

VariableData::VariableData(float anInt)
{
	mOperand = anInt;
	mEverythingElse = '(';
}

VariableData::VariableData(char aChar)
{
	mEverythingElse = aChar;
	mOperand = 0;
}

VariableData::VariableData(VariableData& toBeCopied)
{
	mEverythingElse = toBeCopied.getEverythingElse();
	mOperand = toBeCopied.getOperand();
}

VariableData::~VariableData()
{

}

ostream& operator<<(ostream& lhs, VariableData& rhs)
{
	if(rhs.mOperand != 0)
	{
		lhs << rhs.mOperand;
	}
	else if(rhs.mEverythingElse != 0)
	{
		lhs << rhs.mEverythingElse;
	}
	else
	{
		lhs << rhs.mOperand;
	}

	return lhs;
}