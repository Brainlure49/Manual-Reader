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

using namespace std;

int main()
{

	streampos size;
	char * memblock;

	ifstream myfile;
	myfile.open("LVB Elise Am.mid", ios::in | ios::ate | ios::binary);
	
	ofstream newfile;
	newfile.open("New Text.txt", ios::out);

	if (myfile.is_open()) {
		size = myfile.tellg();
		memblock = new char[size];
		myfile.seekg(0, ios::beg);
		myfile.read(memblock, size);
		myfile.close();		

		cout << "The file size is " << size << ".\n";

		//cout << memblock[0] << memblock[1] << memblock[2] << memblock[3] << "\n";

		streamoff offset = 1;

		for (int i = 0; i != size; i++) {
			cout << memblock[i];
		}

		delete[] memblock;
	}
	else {
		cout << "Error";
	}

	myfile.close();
    return 0;
}