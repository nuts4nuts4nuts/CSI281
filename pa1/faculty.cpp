/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 1
Date Assigned: 8/27/13
Due Date: 9/3/13 - 12:30
Description: The purpose of this program is to act as a database for storing information about students and faculty.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#include "faculty.h"
#include <iostream>

Faculty::Faculty()
{

}

Faculty::Faculty(string id, Name name, Address address, string phoneNumber, string department, string rank)
	:Person(id, name, address, phoneNumber)
{
	mDepartment = department;
	mRank = rank;
}

Faculty::~Faculty()
{

}

string Faculty::getDepartment()
{
	return mDepartment;
}

string Faculty::getRank()
{
	return mRank;
}

void Faculty::setDepartment(string department)
{
	mDepartment = department;
}

void Faculty::setRank(string rank)
{
	mRank = rank;
}

void Faculty::display()
{
	cout << "ID: " << mID << "\n"
		<< "First name: " << mName.mFirstName << "\n"
		<< "Last name: " << mName.mLastName << "\n"
		<< "Street address: " << mAddress.mStreetAddress << "\n"
		<< "City: " << mAddress.mCity << "\n"
		<< "State: " << mAddress.mState << "\n"
		<< "Zip code: " << mAddress.mZip << "\n"
		<< "Phone Number: " << mPhoneNumber << "\n"
		<< "Department: " << mDepartment << "\n"
		<< "Rank: " << mRank << "\n\n";
}