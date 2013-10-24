/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 1
Date Assigned: 8/27/13
Due Date: 9/3/13 - 12:30
Description: The purpose of this program is to act as a database for storing information about students and faculty.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#include <fstream>
#include <sstream>
#include <iostream>
#include "header.h"
#include "person.h"
#include "student.h"
#include "faculty.h"
#include "address.h"
#include "name.h"

using namespace std;

/*Pre: Nothing
*Post: Everything
*Purpose: To create the Student/Faculty Database
and populate the lists with information from students.txt and faculty.txt
*************************************************************************/
SFDatabase::SFDatabase()
{
	ifstream aFileStream;
	aFileStream.open("students.txt");

	string id;
	Name name;
	Address address;
	string phoneNumber;
	string major;
	double gpa;

	while(!aFileStream.eof())
	{
		getline(aFileStream, id);

		getline(aFileStream, name.mLastName);
		getline(aFileStream, name.mFirstName);

		getline(aFileStream, address.mStreetAddress);
		getline(aFileStream, address.mCity);
		getline(aFileStream, address.mState);
		getline(aFileStream, address.mZip);

		getline(aFileStream, phoneNumber);

		getline(aFileStream, major);

		aFileStream >> gpa;
		aFileStream.ignore();

		Student aStudent(id, name, address, phoneNumber, major, gpa);

		mStudentList.push_back(aStudent);
	}

	aFileStream.close();

	aFileStream.open("faculty.txt");

	string department;
	string rank;

	while(!aFileStream.eof())
	{
		getline(aFileStream, id);

		getline(aFileStream, name.mLastName);
		getline(aFileStream, name.mFirstName);

		getline(aFileStream, address.mStreetAddress);
		getline(aFileStream, address.mCity);
		getline(aFileStream, address.mState);
		getline(aFileStream, address.mZip);

		getline(aFileStream, phoneNumber);

		getline(aFileStream, department);
		
		getline(aFileStream, rank);

		Faculty aFaculty(id, name, address, phoneNumber, department, rank);

		mFacultyList.push_back(aFaculty);
	}
	
	aFileStream.close();
}

SFDatabase::~SFDatabase()
{

}


/*Pre: The main menu
*Post: The main menu
*Purpose: To add a faculty member to the faculty list
*****************************************************/
void SFDatabase::addFaculty()
{
	string informationCorrect = "n";
	Faculty aFaculty;

	while( informationCorrect != "y" && informationCorrect != "yes" )
	{

		string id;
		bool idExists = true;

		while( idExists )
		{
			cout << "Enter the new faculty's ID: ";
			getline(cin, id);

			idExists = searchByIDAndReturnExistence(id);

			if( idExists )
			{
				cout << "\nThat ID already exists.\n";
			}
		}


		Name name;
		Address address;
		string phoneNumber;
		string department;
		string rank;

		cout << "Enter the new faculty's last name: ";
		getline(cin, name.mLastName);
		cout << "\nEnter the new faculty's first name: ";
		getline(cin, name.mFirstName);

		cout << "\nEnter the new faculty's street address: ";
		getline(cin, address.mStreetAddress);
		cout << "\nEnter the new faculty's city: ";
		getline(cin, address.mCity);
		cout << "\nEnter the new faculty's state: ";
		getline(cin, address.mState);
		cout << "\nEnter the new faculty's zip code: ";
		getline(cin, address.mZip);

		cout << "\nEnter the new faculty's phone number: ";
		getline(cin, phoneNumber);

		cout << "\nEnter the new faculty's department: ";
		getline(cin, department);

		cout << "\nEnter the new faculty's rank: ";
		getline(cin, rank);

		aFaculty.setID(id);
		aFaculty.setName(name);
		aFaculty.setAddress(address);
		aFaculty.setPhoneNumber(phoneNumber);
		aFaculty.setDepartment(department);
		aFaculty.setRank(rank);
		
		system("cls");

		aFaculty.display();
	
		informationCorrect = "";

		while( informationCorrect != "y" && informationCorrect != "yes" && informationCorrect != "n" && informationCorrect != "no" )
		{
			cout << "\nIs this information correct? y/n\n";
			getline(cin, informationCorrect);
		}
	}


	cout << "\nThe faculty has been added.\n";
	mFacultyList.push_back(aFaculty);
}

/*Pre: The main menu
*Post: The main menu
*Purpose: To add a student to the student list
**********************************************/
void SFDatabase::addStudent()
{
	string informationCorrect = "n";
	Student aStudent;

	while( informationCorrect != "y" && informationCorrect != "yes" )
	{

		string id;
		bool idExists = true;

		while( idExists )
		{
			cout << "Enter the new student's ID: ";
			getline(cin, id);

			idExists = searchByIDAndReturnExistence(id);

			if( idExists )
			{
				cout << "\nThat ID already exists.\n";
			}
		}


		Name name;
		Address address;
		string phoneNumber;
		string major;
		string gpaString;
		double gpa;

		cout << "Enter the new student's last name: ";
		getline(cin, name.mLastName);
		cout << "\nEnter the new student's first name: ";
		getline(cin, name.mFirstName);

		cout << "\nEnter the new student's street address: ";
		getline(cin, address.mStreetAddress);
		cout << "\nEnter the new student's city: ";
		getline(cin, address.mCity);
		cout << "\nEnter the new student's state: ";
		getline(cin, address.mState);
		cout << "\nEnter the new student's zip code: ";
		getline(cin, address.mZip);

		cout << "\nEnter the new student's phone number: ";
		getline(cin, phoneNumber);

		cout << "\nEnter the new student's major: ";
		getline(cin, major);

		bool isGpaValid = false;
		while( !isGpaValid || gpa < 0 || gpa > 4 )
		{
			cout << "\nEnter the new student's gpa: ";
			getline(cin, gpaString);
			isGpaValid = checkDouble(gpaString, gpa);

			if( !isGpaValid || gpa < 0 || gpa > 4 )
			{
				cout << "That is not a valid gpa!\n";
			}
		}

		aStudent.setID(id);
		aStudent.setName(name);
		aStudent.setAddress(address);
		aStudent.setPhoneNumber(phoneNumber);
		aStudent.setMajor(major);
		aStudent.setGpa(gpa);
		
		system("cls");

		aStudent.display();
	
		informationCorrect = "";

		while( informationCorrect != "y" && informationCorrect != "yes" && informationCorrect != "n" && informationCorrect != "no" )
		{
			cout << "\nIs this information correct? y/n\n";
			getline(cin, informationCorrect);
		}
	}


	cout << "\nThe student has been added.\n";
	mStudentList.push_back(aStudent);
}

/*Pre: The main menu
*Post: The main menu
*Purpose: To delete a person from his or her respective list
************************************************************/
void SFDatabase::deletePerson()
{
	bool idExists = false;
	string id;

		while( !idExists )
		{
			cout << "Enter the ID of the person you would like to delete: ";
			getline(cin, id);

			idExists = searchByIDAndReturnExistence(id);

		}

	string deleteYesOrNo = "";

	while( deleteYesOrNo != "y" && deleteYesOrNo != "yes" && deleteYesOrNo != "n" && deleteYesOrNo != "no" )
	{
		cout << "Would you really like to delete this person? y/n\n";
		getline(cin, deleteYesOrNo);

		if( deleteYesOrNo == "y" || deleteYesOrNo == "yes" )
		{
			for( list<Student>::iterator it = mStudentList.begin(); it != mStudentList.end(); ++it )
			{
				if( it->getID() == id )
				{
					if( it == mStudentList.begin() )
					{
						it = mStudentList.erase(it);
					}
					else
					{
						it = mStudentList.erase(it);
						--it;
					}
				}
			}

			for( list<Faculty>::iterator it = mFacultyList.begin(); it != mFacultyList.end(); ++it )
			{
				if( it->getID() == id )
				{
					if( it == mFacultyList.begin() )
					{
						it = mFacultyList.erase(it);
					}
					else
					{
						it = mFacultyList.erase(it);
						--it;
					}
				}
			}

			cout << "Deletion successful!\n";
		}
		else if( deleteYesOrNo == "n" || deleteYesOrNo == "no" )
		{

		}
		else
		{
			cout << "That is not a valid input!\n";
		}
	}
}
/*Pre: The creation of the SFDatabase
*Post: The termination of the program
*Purpose: To drive the menu system of the program
*************************************************/
void SFDatabase::mainDriver()
{
	string userInput = "";
	int inputInt;
	string searchID;

	while( userInput != "5" )
	{
		cout << "What would you like to do?\n\n"
			<< "(1) Search for a person.\n"
			<< "(2) Add a student.\n"
			<< "(3) Add a faculty member.\n"
			<< "(4) Delete a person.\n"
			<< "(5) Quit the program.\n";

		getline(cin, userInput);

		if( userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5" )
		{
			cout << "That is not a valid input, please try again.\n\n";
		}
		else
		{
			stringstream aStream;
			aStream << userInput;
			aStream >> inputInt;

			switch( inputInt )
			{
			case 1:
				cout << "Please enter the id of the person for whom you are searching: ";
				getline(cin, searchID);
				searchByIDAndReturnExistence(searchID);
				break;
			case 2:
				addStudent();
				break;
			case 3:
				addFaculty();
				break;
			case 4:
				deletePerson();
				break;
			case 5:
				cout << "Thank you, goodbye.\n";
				saveLists();
				break;
			}
		}
	}
}

/*Pre: All of the alterations made to the database
*Post: The termination of the program
*Purpose: To save the lists for later alteration or perusal
***********************************************************/
void SFDatabase::saveLists()
{
	//Student list
	remove("students.txt");

	ofstream outputStream;
	outputStream.open("students.txt");

	for( list<Student>::iterator it = mStudentList.begin(); it != mStudentList.end(); ++it )
	{
		if( it == mStudentList.begin() )
		{
			outputStream << it->getID() << endl;
		}
		else
		{
			outputStream << endl << it->getID() << endl;
		}
		
		outputStream << it->getName().mLastName << endl;
		outputStream << it->getName().mFirstName << endl;

		outputStream << it->getAddress().mStreetAddress << endl;
		outputStream << it->getAddress().mCity << endl;
		outputStream << it->getAddress().mState << endl;
		outputStream << it->getAddress().mZip << endl;

		outputStream << it->getPhoneNumber() << endl;
		
		outputStream << it->getMajor() << endl;

		outputStream << it->getGpa();
	}
	outputStream.close();

	//Faculty list
	remove("faculty.txt");

	outputStream.open("faculty.txt");

	for( list<Faculty>::iterator it = mFacultyList.begin(); it != mFacultyList.end(); ++it )
	{
		if( it == mFacultyList.begin() )
		{
			outputStream << it->getID() << endl;
		}
		else
		{
			outputStream << endl << it->getID() << endl;
		}
		
		outputStream << it->getName().mLastName << endl;
		outputStream << it->getName().mFirstName << endl;

		outputStream << it->getAddress().mStreetAddress << endl;
		outputStream << it->getAddress().mCity << endl;
		outputStream << it->getAddress().mState << endl;
		outputStream << it->getAddress().mZip << endl;

		outputStream << it->getPhoneNumber() << endl;
		
		outputStream << it->getDepartment() << endl;

		outputStream << it->getRank();
	}
}

/*Pre: The main menu
*Post: The main menu, or adding or deleting any person
*Purpose: To search the database, display the person it finds if it finds someone
and return a boolean telling of the existence of an id
*********************************************************************************/
bool SFDatabase::searchByIDAndReturnExistence(string id)
{
	bool idFound = false;

	for( list<Student>::iterator it = mStudentList.begin(); it != mStudentList.end() && !idFound; ++it )
	{
		if( it->getID() == id )
		{
			it->display();
			idFound = true;
		}
	}

	for( list<Faculty>::iterator it = mFacultyList.begin(); it != mFacultyList.end() && !idFound; ++it )
	{
		if( it->getID() == id )
		{
			it->display();
			idFound = true;
		}
	}

	if( !idFound )
	{
		cout << "No person was found to have that ID\n";
		return false;
	}
	else
	{
		return true;
	}
}
/*Pre: A situation in which one might want to validate a string as a double
*Post: Almost anything...
*Purpose: To check if a string is in fact a double precision floating point number
*********************************************************************************/
bool checkDouble(string& aString, double& num)
{
	stringstream aStream;

	aStream << aString;
	aStream >> num;

	if( aStream.fail() )
	{
		return false;
	}
	else
	{
		return true;
	}
}