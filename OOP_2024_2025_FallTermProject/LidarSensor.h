#ifndef LIDARSENSOR_H
#define LIDARSENSOR_H

#include "FestoRobotAPI.h"
#include <vector>
#include <cmath>
#include <stdexcept>
#include "FestoRobotSensorInterface.h"
#include <iostream>
//Ka�an Ba� 152120201083 20.12.2024

using namespace std; // Standart namespace kullan�m�

//1. A�ama Kodlar�:

//class LidarSensor: public FestoRobotSensorInterface {
//private:
//    vector<double> ranges;  // Lidar mesafeleri
//    FestoRobotAPI* roboAPI; // Robot API'si pointer
//    int rangeNumber;        // Lidar veri say�s�
//
//public:
//    // Constructor
//    LidarSensor(FestoRobotAPI* robotAPI);
//
//    // G�ncel lidar mesafelerini ranges dizisine y�kler
//    void update();
//
//    // i. indeksindeki lidar verisini d�nd�r�r
//    double getRange(int i) const;
//
//    // En k���k uzakl�k ve indeksini d�nd�r�r
//    pair<int, double> getMin() const;
//
//    // En b�y�k uzakl�k ve indeksini d�nd�r�r
//    pair<int, double> getMax() const;
//
//    // [] operat�r�: getRange ile ayn� i�lev
//    double operator[](int i) const;
//
//    // i. indeksteki lidar verisinin robota g�re a��s�n� d�nd�r�r
//    double getAngle(int i) const;
//};

//2. A�ama Kodlar�:

//Umay Ece Mantar 152120221127 27.12.2024

class LidarSensor : public FestoRobotSensorInterface {
private:
	double* ranges; // stores the distance readings
	int rangeNumber; // total number of range values
public:
	
	//abstract interface implementations
    LidarSensor(FestoRobotAPI* api); // constructor initializing the lidar sensor
    LidarSensor(const LidarSensor& other); // copy constructor
    ~LidarSensor(); // destructor


   void update() override; // updates the sensor data
   string getSensorType()  override; // returns the type of the sensor
   double getSensorValue(int index) override; // retrieves a specific sensor value

    double operator[](int index) const; // overload for accessing range values
    double& operator[](int index); // overload for the non const objects

    double getRange(int index) const; // gets the range at a specific index
    double getMax(int& index) const; // finds the maximum range from its index
    double getMin(int& index) const; // finds the minimum range from its index
    double getAngle(int i) const; // calculates the angle for a given index
};

#endif // LIDARSENSOR_H