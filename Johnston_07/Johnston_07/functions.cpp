/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 7
Date Assigned: 10/31/13
Due Date: 11/07/13 - 12:30
Description: The purpose of this program is to recieve a message and encrypt it based on a codebook.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#include <string>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include "header.h"
#include "timerSystem.h"

using namespace std;

const uint32_t PRIME = 16777619; //Large prime optimal for 32-bit fnv algorithm
const uint32_t SEED = 2166136261; //Seed optimal for 32-bit fnv algorithm


/*      Pre:  We have a file which we want to encrypt, and a codebook loaded into arrays.
 *     Post:  We have an encrypted file.
 *  Purpose:  To encrypt a file according to a codebook.
 *****************************************************************************/
void encryptFile(string inFile, string codeArray[], string nameArray[])
{
	TimerSystem timer;
	double time = 0;

	string currentWord;
	bool wordFound = true;
	uint32_t currentHash = 0;
	int collisionOffset = 0;
	int trueIndex = currentHash + collisionOffset;

	string outFile;
	ifstream inStream;
	ofstream outStream;

	int numWords = 0;

	inStream.open(inFile);

	if(inStream.good())
	{
		cout << "\nPlease enter the name of your output file: ";
		cin >> outFile;

		outStream.open(outFile);

		timer.startClock();
		while(!inStream.eof())
		{
			inStream >> currentWord;
			currentHash = stringHash(currentWord.c_str(), currentWord.length());
			trueIndex = currentHash;

			if(nameArray[trueIndex] != currentWord)
			{
				while(nameArray[trueIndex] != currentWord && wordFound)
				{
					trueIndex++;
					
					if(codeArray[trueIndex] != "")
					{
						wordFound = false;
					}
				}

				outStream << currentWord;
			}
			else
			{
				outStream << codeArray[trueIndex] << " ";
			}
		}

		time = timer.getTime();
		cout << time << "s\n";

	}
	else
	{
		cout << "Oops, that file does not exist.";
	}

	inStream.close();
	outStream.close();
}


/*      Pre:  We have the name of the codebook which we would like to load,
			  and two large array in which to load the book.
 *     Post:  We have a codebook loaded into two arrays.
 *  Purpose:  To load a codebook into two arrays, indexed by a hashing algorithm.
 *****************************************************************************/
void loadCodebook(string codeArray[], string nameArray[], string bookName)
{
	ifstream inStream;
	string currentString;
	int i = 0;
	int collisionOffset = 0;

	inStream.open(bookName);

	cout << "Loading...";

	while(!inStream.eof())
	{
		inStream >> currentString;

		if(codeArray[stringHash(currentString.c_str(), currentString.length()) + collisionOffset] != "")
		{
			while(codeArray[stringHash(currentString.c_str(), currentString.length()) + collisionOffset] != "")
			{
				collisionOffset++;
			}
			collisionOffset = 0;
		}

		nameArray[stringHash(currentString.c_str(), currentString.length()) + collisionOffset] = currentString;

		inStream >> codeArray[stringHash(currentString.c_str(), currentString.length()) + collisionOffset];
	}

}


/*      Pre:  We have a string we would like to hash.
 *     Post:  We have a (in this case) 23-bit hash value.
 *  Purpose:  To quickly and effectively hash a string.
 *****************************************************************************/
uint32_t stringHash(const char *theString, int numChars)
{
	uint32_t hash = SEED;

	while (numChars--)
	{
		hash = fnv1a(*theString++, hash);
	}

	return (hash>>24) ^ (hash & MASK_23);
}


/*      Pre:  We have one byte we would like to hash.
 *     Post:  We have a 32-bit hash value.
 *  Purpose:  To nicely hash a single byte.
 *****************************************************************************/
uint32_t fnv1a(unsigned char oneChar, uint32_t hash)
{
	return (oneChar ^ hash) * PRIME;
}