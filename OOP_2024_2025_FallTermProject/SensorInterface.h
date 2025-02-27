#pragma once
#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H
#include <iostream>
#include <string>
using namespace std;
//Umay Ece Mantar 152120221127 27.12.2024

/**
 * @class SensorInterface
 * @brief this is an abstract base class (interface) for sensor-related operations.
 *
 * the SensorInterface class defines a contract for all sensor implementations.
 * derived classes must implement the pure virtual functions to provide specific behavior.
 */
class SensorInterface
{
private:
	string sensorType; //< a private member to store the type of sensor
public:
	/**
	 * virtual destructor for the SensorInterface class.
	 * ensures proper cleanup of derived class objects through base class pointers.
	 */
	~SensorInterface() = default; 
	/*pure virtual function to update the sensor state.
	 * this function must be implemented by derived classes to update the sensor's internal data.
	 */
	virtual void update() = 0;
	/**
	 * retrieves a specific sensor value.
	 * parameter it takes is the index of the data point.
	 * returns the sensor value at the given index.
	 */
	virtual double getSensorValue(int index) = 0;
	/** retrieves the type of sensor.
	 * @return sensor type (e.g., "temperature").
	 */
	virtual string getSensorType() = 0;
};

#endif SENSORINTERFACE_H