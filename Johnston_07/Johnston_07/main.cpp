/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 7
Date Assigned: 10/31/13
Due Date: 11/07/13 - 12:30
Description: The purpose of this program is to recieve a message and encrypt it based on a codebook.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	const string CODEBOOK = "codes.txt";

	cout << "Allocating memory...\n";
	string inFile;
	string outFile;
	string *codeArray = new string[MAX_ARRAY]();
	string *nameArray = new string[MAX_ARRAY]();

	loadCodebook(codeArray, nameArray, CODEBOOK);

	while(inFile != "exit")
	{
		cout << "\nPlease enter the name of your input file: ";
		cin >> inFile;

		encryptFile(inFile, codeArray, nameArray);
	}

	system("cls");
	cout << "Shutting down...";

	//Never stops deleting...
	/*cout << "\nDeleting first array...";
	delete []codeArray;
	cout << "\nDeleting second array..."; 
	delete []nameArray;*/

	return 0;
}