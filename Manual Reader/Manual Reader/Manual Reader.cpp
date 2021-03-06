// Manual Reader.cpp : Defines the entry point for the console application.
//

//Info at http://courses.cs.vt.edu/~cs2604/fall00/binio.html
//and
//http://www.cplusplus.com/doc/tutorial/files/
//and
//http://www.ccarh.org/courses/253/handout/smf/

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{

	streampos size;
	streampos pos;
	char * memblock;

	char * tempblock;

	string string1;

	ifstream myfile;
	myfile.open("LVB Elise Am.mid", ios::in | ios::ate | ios::binary);
	
	ofstream newfile;
	newfile.open("New Text.txt", ios::out);

	if (myfile.is_open()) {
		size = myfile.tellg();
		memblock = new char[5];
		memblock[4] = '\0';
		tempblock = new char[5];
		tempblock[4] = '\0';
		myfile.seekg(0, ios::beg);

		pos = myfile.tellg();
		cout << "The pointer position before reading is " << pos << ".\n";
		cout << "The file size is " << size << ".\n";

		int headercount = 0;
		int trackcount = 0;

		while (myfile.tellg() <= size) {

			myfile.read(memblock, 4);

			string1 = memblock;

			if (string1 == "MThd") {
				headercount++;
				cout << "Found " << headercount << " header chunks.\n";
			}
			else if (string1 == "MTrk") {
				trackcount++;
				cout << "Found " << trackcount << " track chunks.\n";
			}

			myfile.seekg(-3, ios::cur);

		}

		while(4 == 3) {
			myfile.read(memblock, 4);


			pos = myfile.tellg();
			cout << "The pointer position is " << pos << ".\n";

			myfile.seekg(-3, ios::cur);

			pos = myfile.tellg();
			cout << "The pointer position is " << pos << ".\n";

			string string1 = memblock;

			if (string1 == "MThd") {
				cout << "Header Chunk\n";
				headercount++;
			}
			else if (string1 == "MTrk") {
				cout << "Track Chunk\n";
				trackcount++;
			}
			else { cout << "\n"; }

		} //while (pos < size);

		myfile.close();	
		delete[] memblock;
	}
	else {
		cout << "Error";
	}

	myfile.close();
    return 0;
}