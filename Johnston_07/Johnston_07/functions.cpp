#include <string>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include "header.h"
#include "timerSystem.h"

using namespace std;

const uint32_t PRIME = 16777619;
const uint32_t SEED = 2166136261;

void encryptFile(string inFile, string outFile, string codeArray[], string nameArray[])
{
	TimerSystem timer;
	double time = 0;

	string currentWord;
	bool wordFound = true;
	uint32_t currentHash = 0;
	int collisionOffset = 0;

	ifstream inStream;
	ofstream outStream;

	int numWords = 0;
	string *inArray;
	string *outArray;

	inStream.open(inFile);

	if(inStream.good())
	{
		outStream.open(outFile);

		while(!inStream.eof())
		{
			inStream >> currentWord;
			numWords++;
		}

		inStream.clear();
		inArray = new string[numWords];
		outArray = new string[numWords];

		for(int i = 0; i < numWords; i++)
		{
			inStream >> inArray[i];
		}

		inStream.clear();

		timer.startClock();
		for(int i = 0; i < numWords; i++)
		{
			currentWord = inArray[i];
			currentHash = stringHash(currentWord.c_str(), currentWord.length());

			if(nameArray[currentHash + collisionOffset] != currentWord)
			{
				while(nameArray[currentHash + collisionOffset] != currentWord && wordFound)
				{
					collisionOffset++;
					
					if(codeArray[currentHash + collisionOffset] != "")
					{
						wordFound = false;
					}
				}

				collisionOffset = 0;

				outArray[i] = currentWord;
			}
			else
			{
				outArray[i] = codeArray[currentHash + collisionOffset] + " ";
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

uint32_t stringHash(const char *theString, int numChars)
{
	uint32_t hash = SEED;

	while (numChars--)
	{
		hash = fnv1a(*theString++, hash);
	}

	return (hash>>24) ^ (hash & MASK_23);
}

uint32_t fnv1a(unsigned char oneChar, uint32_t hash)
{
	return (oneChar ^ hash) * PRIME;
}