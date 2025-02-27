#include "IRSensor.h"
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;
//Umay Ece Mantar 152120221127 17.12.2024
//this is the declaration of the IRSensor class

//1. Aþama Kodlarý:

//IRSensor::IRSensor()
//{
//	// default constructor for IRSensor class.
//	for (int i = 0; i < 9; i++) {
//		this->ranges[i] = 0.0; //this function resets all the range values to 0.0 when the object is created
//	}
//	robotAPI = nullptr;
//}
//
//IRSensor::IRSensor(FestoRobotAPI* robotAPI) : robotAPI(robotAPI)// constructor that holds a pointer to a FestoRobotAPI object.
//{
//	for (int i = 0; i < 9; i++) { 
//		ranges[i] = 0.0; //this function resets all the range values to 0.0 when the object is created
//	}
//}
//
//IRSensor::~IRSensor() //default decontructor of the IRSensor class
//{
//}
//
//void IRSensor::update()
//{
//	if (!robotAPI) {
//		throw runtime_error("robotAPI is not initialized."); // throw and exception if there is no robotAPI
//	}
//	for (int i = 0; i < 9; i++) {
//		ranges[i] = robotAPI->getIRRange(i); // updating the value of every sensor
//	}
//}
//
//double IRSensor::getRange(int i) //returns the range value at the specified index 'i'.
//{
//	 //ensure that the range values are up-to-date before accessing them.
//	if (i < 0 || i>9) {
//		return -1.0;  //returns -1 if the index is out of range (valid indices are 0-9)
//	}
//	return ranges[i]; //returns the value if the range is between the valid indices (0-9) 
//}
//
//double IRSensor::operator[](int i)
//{
//	if (i < 0 || i >= 9) {
//		throw out_of_range("Out Of Range"); // invalid index
//	}
//	return ranges[i]; // return directly the array
//}


//2. Aþama Kodlarý: Umay Ece Mantar 152120221127 27.12.2024

IRSensor::IRSensor(FestoRobotAPI* api): FestoRobotSensorInterface(api), sensorValues(numberOfSensors, 0.0)
{
	// initialize the sensor values vector with default values (0.0)
}

IRSensor::IRSensor(const IRSensor& other): FestoRobotSensorInterface(other.robotAPI), sensorValues(other.sensorValues)
{
	// copy constructor: clone sensor values vector
}

void IRSensor::update()
{
	if (!robotAPI) {
		return;
	}
	// update sensor values from the robot API
	for (int i = 0; i < numberOfSensors; ++i) {
		sensorValues[i] = robotAPI->getIRRange(i); // fetch the IR range value for each sensor
	}
}

string IRSensor::getSensorType()
{
	// return the type of sensor
	return "IR Sensor";
}

double IRSensor::getSensorValue(int index)
{
	// validate index and return the corresponding sensor value
	if (!isValidIndex(index, numberOfSensors)) {
		throw out_of_range("IR sensor is out of range");
	}
	return sensorValues[index];
}



int IRSensor::getNumberOfSensors() const
{
	return numberOfSensors; // return the total number of sensors
}

double IRSensor::operator[](int index) // overload operator[] for read-only(const) access to sensor values
{
	return getSensorValue(index);
}
