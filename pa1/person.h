/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 1
Date Assigned: 8/27/13
Due Date: 9/3/13 - 12:30
Description: The purpose of this program is to act as a database for storing information about students and faculty.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "address.h"
#include "name.h"

using namespace std;

class Person
{
public:
	Person();
	Person(string id, Name name, Address address, string phoneNumber);
	~Person();

	Address getAddress();
	string getID();
	Name getName();
	string getPhoneNumber();

	void setAddress(Address address);
	void setID(string id);
	void setName(Name name);
	void setPhoneNumber(string phoneNumber);

	virtual void display() = 0;

protected:
	string mID;
	Name mName;
	Address mAddress;
	string mPhoneNumber;
};

#endif PERSON_H