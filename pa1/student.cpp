/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 1
Date Assigned: 8/27/13
Due Date: 9/3/13 - 12:30
Description: The purpose of this program is to act as a database for storing information about students and faculty.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#include <iostream>
#include <iomanip>
#include "student.h"

Student::Student()
{

}

Student::Student(string id, Name name, Address address, string phoneNumber, string major, double gpa)
	:Person(id, name, address, phoneNumber)
{
	mMajor = major;
	mGpa = gpa;
}

Student::~Student()
{

}

double Student::getGpa()
{
	return mGpa;
}

string Student::getMajor()
{
	return mMajor;
}

void Student::setGpa(double gpa)
{
	mGpa = gpa;
}

void Student::setMajor(string major)
{
	mMajor = major;
}

void Student::display()
{
	cout << "ID: " << mID << "\n"
		<< "First name: " << mName.mFirstName << "\n"
		<< "Last name: " << mName.mLastName << "\n"
		<< "Street address: " << mAddress.mStreetAddress << "\n"
		<< "City: " << mAddress.mCity << "\n"
		<< "State: " << mAddress.mState << "\n"
		<< "Zip code: " << mAddress.mZip << "\n"
		<< "Phone Number: " << mPhoneNumber << "\n"
		<< "Major: " << mMajor << "\n"
		<< fixed << setprecision(2) << "GPA: " << mGpa << "\n\n";
}