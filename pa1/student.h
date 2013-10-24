/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 1
Date Assigned: 8/27/13
Due Date: 9/3/13 - 12:30
Description: The purpose of this program is to act as a database for storing information about students and faculty.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "address.h"
#include "name.h"
#include "person.h"

using namespace std;

class Student: public Person
{
public:
	Student();
	Student(string id, Name name, Address address, string phoneNumber, string major, double gpa);
	~Student();

	double getGpa();
	string getMajor();

	void setGpa(double gpa);
	void setMajor(string major);

	virtual void display();

private:
	string mMajor;
	double mGpa;
};

#endif STUDENT_H