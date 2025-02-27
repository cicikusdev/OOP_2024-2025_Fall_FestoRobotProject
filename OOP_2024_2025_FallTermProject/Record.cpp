#include "Record.h"
//Umay Ece Mantar 152120221127 13.12.2024
//This file is the implementation of the Record class

bool Record::openFile()
{
	file.open(fileName, fstream::in | fstream::out | fstream::app); //declaration of how a file object from a fstream class is opened with modes
	if (file.is_open()) { //returns true if file is opened
		return true;
	}
	else {
		return false; //returns false if the file is not opened
	}
}

bool Record::closeFile()
{
	file.close(); //closes the file
	if (file.is_open()) {
		return false; //if the file is opened, return false. otherwise, return true.
	}
	else {
		return true;
	}
}

void Record::setFileName(string name) 
{
	fileName = name; //sets the name of the file 
}

string Record::readLine()
{
	if (!file.is_open()) {
		throw runtime_error("File is not open!"); //if file is not open, an exception handling technique is used as "throw runtime_error
	}
	string line; //declaring a string variable
	if (getline(file, line)) { //getline reads a line from the file and assings it to the "line" variable
		return line; //if succesfull, returns line
	}
}

bool Record::writeLine(string str)
{
	if (file.is_open()) { //checking if the file is open
		file << str << endl; //this command writes the content of the variable str to the file stream named file
		return true;
	}
	else {
		return false; //if file is not open, returns false
	}
}

Record& Record::operator<<(string data) //operator overloading, it helps to write object datas
{
	writeLine(data);
	return *this;
}

Record& Record::operator>>(string data) //operator overloading, it helps to read the object data
{
	data = readLine();
	return *this;
}
