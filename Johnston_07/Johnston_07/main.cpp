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

	delete []codeArray;
	delete []nameArray;

	return 0;
}