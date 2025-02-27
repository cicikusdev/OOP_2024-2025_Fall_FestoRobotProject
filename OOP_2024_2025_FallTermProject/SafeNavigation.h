/*
* @File SafeNavigation.h
* @Author Suude Kaynak - 152120211110
* @Date 18.12.2024
* @Brief SafeNavigation sýnýfýnýn tanýmýný içeren header dosyasý
*/
#ifndef SAFENAVIGATION_H
#define SAFENAVIGATION_H
#pragma once
//#include "IRSensor.h"
#include "SensorInterface.h"
#include "RobotControler.h"


enum MOVESTATE {
	MOVING,
	STOP
};

//Aþama 1 Kodlarý:

//
//class SafeNavigation 
//{
//private:
//	IRSensor* IR;                  // Kýzýlötesi sensör objesi
//	RobotControler* controller;   // RobotController objesi
//	enum MOVESTATE { MOVING, STOP }; // Hareket durumu enum
//	MOVESTATE state;               // Hareket durumu deðiþkeni
//public:
//	SafeNavigation(IRSensor* IR, RobotControler* controller);  // Constructor
//	void moveForwardSafe();
//	void moveBacwardSafe();
//
//};

//Aþama 2 Kodlarý: 
// Umay Ece Mantar 28.12.2024 152120221127

class SafeNavigation
{
private:
    SensorInterface* sensor;      // pointer to a sensor object to gather environmental data
    RobotControler* controller;   // pointer to a controller object for managing robot movements
    MOVESTATE state;               // current movement state of the robot

public:
    // constructor initializes the sensor and controller pointers (default is nullptr)
    SafeNavigation(SensorInterface* sns = nullptr, RobotControler* cntrl= nullptr);  

    void moveForwardSafe();  // moves the robot forward, ensuring safety using sensor data
    void moveBacwardSafe(); // moves the robot backward, avoiding collisions based on sensor readings
};

#endif SAFENAVIGATION_H