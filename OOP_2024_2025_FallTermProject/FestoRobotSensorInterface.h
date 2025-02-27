#pragma once
#ifndef FESTOROBOTSENSORINTERFACE_H
#define FESTOROBOTSENSORINTERFACE_H
#include "SensorInterface.h"
#include "FestoRobotAPI.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Umay Ece Mantar 152120221127 27.12.2024

class FestoRobotSensorInterface : public SensorInterface
{
protected:
	FestoRobotAPI* robotAPI; //pointer for robotAPI to access the sensor data
	bool isValidIndex(int index, int maxIndex) const { //proteted method to check if the sensor index is valid
		return(index >= 0 && index < maxIndex);
	}
	FestoRobotAPI* getRobotAPI() const { //protected method to access the robotAPI
		return robotAPI;
	}
public:
	//Constructor that takes a pointer to FestoRobotAPI
	FestoRobotSensorInterface(FestoRobotAPI* api): robotAPI(api){ // initializes with a robot API pointer
		if (!api) { //if there is no api object
			throw runtime_error("Invalid FestoRobotAPI pointer");
	}
}
	virtual ~FestoRobotSensorInterface() {}; //virtual destructor
	//virtual void updateSensor() = 0; // updates sensor data as the function of the abstract class
	//virtual string getSensorType() const = 0; // retrieves the sensor type as the function of the abstract class
	//virtual double getSensorValue(int index) const = 0; // gets a value from the sensor as the function of the abstract class

};

#endif // !FESTOROBOTSENSORINTERFACE_H