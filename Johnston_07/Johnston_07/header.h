/*Author: David Johnston
Class: CSI-281-01
Assignment: pa 7
Date Assigned: 10/31/13
Due Date: 11/07/13 - 12:30
Description: The purpose of this program is to recieve a message and encrypt it based on a codebook.
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#ifndef HEADER_H
#define HEADER_H

#define MAX_ARRAY (uint32_t)8388608 //power of two large safe array size
#define MASK_23 (((uint32_t)1<<23)-1) 

#include <string>
#include <stdint.h>

using namespace std;

uint32_t fnv1a(unsigned char oneChar, uint32_t hash);
void encryptFile(string inFile, string codeArray[], string nameArray[]);
void loadCodebook(string codeArray[], string nameArray[], string bookName);
uint32_t stringHash(const char *theString, int numChars);

#endif HEADER_H
