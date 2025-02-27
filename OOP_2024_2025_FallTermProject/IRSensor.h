#ifndef IRSENSOR_H
#define IRSENSOR_H
#include <iostream>
#include "FestoRobotAPI.h"
#include "FestoRobotSensorInterface.h"
#include <string>
using namespace std;
/*  Umay Ece Mantar 152120221127 16.12.2024
 The IRSensor class is designed to interface with the IR sensor data of the robot.
*/

// 1. Aþama Kodlarý:

//class IRSensor : public FestoRobotAPI // IRSensor class inherits from FestoRobotAPI, granting access to FestoRobotAPI's public elements
//{
//private:
//	double ranges[9]; // array to store the distance values from 9 IR sensors
//	FestoRobotAPI* robotAPI; // pointer to a FestoRobotAPI object to interact with the robot
//public:
//	IRSensor();// default constructor
//	IRSensor(FestoRobotAPI* robotAPI); //constructor that initializes IRSensor with a FestoRobotAPI object
//    ~IRSensor();//destructor of the class
//	void update();//updates the range values of the sensors by fetching the latest data from the robot system
//	double getRange(int i); //returns the range value of the sensor at index 'i'
//	double operator[](int i); //overloaded [] operator to easily retrieve the sensor value at a specific index
//};
//#endif IRSENSOR_H

//2. Aþama Kodlarý:

//Umay Ece Mantar 27.12.2024 152120221127

class IRSensor : public FestoRobotSensorInterface // IRSensor class inherits from FestoRobotAPI, granting access to FestoRobotAPI's public elements
{
private:
	static const int numberOfSensors = 9; //number of sensors on the robot
	vector<double> sensorValues; //to store the current sensor data, we define a vector
public: 
	IRSensor(FestoRobotAPI* api); //constructor
	IRSensor(const IRSensor& other); //copy constructor

	//~IRSensor() = default;

	void update() override;  //implement pure virtual functions from the interface
	string getSensorType() override;
	double getSensorValue(int index) override;

	int getNumberOfSensors() const; 
	
	double operator[](int index); // overload for accessing range values
};
#endif IRSENSOR_H
