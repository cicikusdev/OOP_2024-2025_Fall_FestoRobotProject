//
//#include <iostream>
//#include "IRSensor.h"
//#include "FestoRobotAPI.h"
//using namespace std;
////Umay Ece Mantar 152120221127 18.12.2024
////This is the test file of the IRSensor class
//
//int main() {
//	//First, we have to create an object of the FestoRobot class
//	FestoRobotAPI* roboAPI = new FestoRobotAPI;
//		roboAPI->connect(); //we connected the example roboAPI object to the simulation
//
//	//Then, we have to create the IRSensor object
//	IRSensor irsensor(roboAPI); //default constructor is holding the FestoRobotAPI object as a parameter
//
//	cout << "getRange() Test" << endl; //getRange(int i) Test
//	for (int i = 0; i < 9; i++) { //this function is to check if getRange is working correctly
//		cout << "The value of the sensor number " << i << "is: " << irsensor.getRange(i) << endl;
//}
//	
//	//update() Test
//	cout << "update() test" << endl;
//	cout << "before the update:" << endl;
//	//before update:
//	for (int i = 0; i < 9; i++) {
//		cout << "not updated ranges[" << i << "] = " << irsensor.getRange(i) << endl;
//	}
//	irsensor.update(); //update the values
//
//	cout << "after the update:" << endl;
//	//after the update
//	for (int i = 0; i < 9; i++) {
//		cout << "updated ranges[" << i << "] = " << irsensor.getRange(i) << endl;
//	}
//
//	//operator[] Test
//	//for valid indices:
//	cout << "operator[] test:" << endl;
//	try {
//		for (int i = 0; i < 9; i++) {
//			cout << "operator[] overloaded irsensor[" << i << "] = " << irsensor[i] << endl;
//		}
//	}
//	catch (const exception& e) {
//		cerr << "unexpected exception for valid indices: " << e.what() << endl;
//	}
//	//for invalid indices:
//	try {
//		cout << "testing invalid index -1: ";
//		cout << irsensor[-1] << endl; // this should throw an exception
//	}
//	catch (const out_of_range& e) {
//		cout << "caught exception as expected: " << e.what() << endl;
//	}
//
//	try {
//		cout << "testing invalid index 10: ";
//		cout << irsensor[10] << endl; // this should throw an exception
//	}
//	catch (const out_of_range& e) {
//		cout << "caught exception as expected: " << e.what() << endl;
//	}
//
//	roboAPI->disconnect(); //disconnecting the object from the simulation
//	delete roboAPI; //deleting the object from the memory
//
//	return 0;
//}
//
