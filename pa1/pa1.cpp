/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 1
Date Assigned: 8/27/13
Due Date: 9/3/13 - 12:30
Description: The purpose of this program is to act as a database for storing information about students and faculty.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#include "header.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	SFDatabase aDatabase;

	aDatabase.mainDriver();

	system("pause");
	return 0;
}