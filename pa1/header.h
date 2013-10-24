/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 1
Date Assigned: 8/27/13
Due Date: 9/3/13 - 12:30
Description: The purpose of this program is to act as a database for storing information about students and faculty.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#ifndef HEADER_H
#define HEADER_H

#include <fstream>
#include <list>
#include "person.h"
#include "student.h"
#include "faculty.h"

using namespace std;

//Class for the entire database
class SFDatabase
{
public:
	SFDatabase();
	~SFDatabase();

	void addFaculty();
	void addStudent();
	void deletePerson();
	void mainDriver();
	void saveLists();
	bool searchByIDAndReturnExistence(string id);

public:
	list<Student> mStudentList;
	list<Faculty> mFacultyList;
};

bool checkDouble(string& aString, double& num);

#endif HEADER_H