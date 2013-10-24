/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 1
Date Assigned: 8/27/13
Due Date: 9/3/13 - 12:30
Description: The purpose of this program is to act as a database for storing information about students and faculty.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#include "person.h"

using namespace std;

// Constructors / destructors
Person::Person()
{

}

Person::Person(string id, Name name, Address address, string phoneNumber)
{
	mID = id;
	mName = name;
	mAddress = address;
	mPhoneNumber = phoneNumber;
}

Person::~Person()
{

}

Address Person::getAddress()
{
	return mAddress;
}

string Person::getID()
{
	return mID;
}

Name Person::getName()
{
	return mName;
}

string Person::getPhoneNumber()
{
	return mPhoneNumber;
}

void Person::setAddress(Address address)
{
	mAddress = address;
}

void Person::setID(string id)
{
	mID = id;
}

void Person::setName(Name name)
{
	mName = name;
}

void Person::setPhoneNumber(string phoneNumber)
{
	mPhoneNumber = phoneNumber;
}