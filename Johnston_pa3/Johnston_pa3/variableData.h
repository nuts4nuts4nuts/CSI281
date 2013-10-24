/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 3
Date Assigned: 9/12/13
Due Date: 9/19/13 - 12:30
Description: The purpose of this program is to recieve a infix epression,
turn it into a postfix operation and calculate it.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#ifndef VARIABLEDATA_H
#define VARIABLEDATA_H

#include <iostream>

using namespace std;

class VariableData
{
	friend ostream& operator<<(ostream& lhs, VariableData& rhs);
private:
	float mOperand;
	char mEverythingElse;
public:
	VariableData();
	VariableData(float aFloat);
	VariableData(char aChar);
	VariableData(VariableData& toBeCopied);

	~VariableData();

	inline float getOperand() { return mOperand; }
	inline char getEverythingElse() { return mEverythingElse; }

	inline void setOperand(float operand) { mOperand = operand; }
	inline void setEverythingElse(char aChar) {mEverythingElse = aChar; }

	inline VariableData operator=(float& rhs) { mOperand = rhs; }
	inline VariableData operator=(char& rhs) { mEverythingElse = rhs; }
};

#endif VARIABLEDATA_H