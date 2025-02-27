#ifndef RECORD_H
#define RECORD_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

//author: Umay Ece Mantar 152120221127 13.12.2024
//This file is the definition of the Record class

class Record
{
private:
	string fileName; //name of the file 
	fstream file; //to read and write object
	
public: 
	Record(string FileName) { //as a constructor, this code executes the following steps when a Record object is created:
		setFileName(FileName); //sets the file name 
		openFile(); //opens the file 
		writeLine("Start"); //writes the string "Start" to the file
	};
	~Record() {
		/*as a deconstructor, this code executes(nearly the opposite of the constructor) the following
		steps when a Record object is out of the scope and it is being deleted:*/
		if (file.is_open()) { //checks if the file has opened
			writeLine("End"); //if it is open, writes the string "End"
		}
		closeFile(); //Then, closes the file
	};
	bool openFile(); //opens the file of the Record object to read and write
	bool closeFile(); //closes the file of the Record object to read and write
	void setFileName(string name); //sets the file name of the Record object which will be read and written
	string readLine(); //function to read 
	bool writeLine(string str);
	Record& operator<<(string data); //writes the object data 
	Record& operator>>(string data); //reads the object data

};

#endif