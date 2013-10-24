/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 1
Date Assigned: 8/27/13
Due Date: 9/3/13 - 12:30
Description: The purpose of this program is to act as a database for storing information about students and faculty.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include "address.h"
#include "name.h"
#include "person.h"

using namespace std;

class Faculty: public Person
{
public:
	Faculty();
	Faculty(string id, Name name, Address address, string phoneNumber, string department, string rank);
	~Faculty();

	string getDepartment();
	string getRank();

	void setDepartment(string department);
	void setRank(string rank);

	virtual void display();

private:
	string mDepartment;
	string mRank;
};

#endif FACULTY_H