/*
* @File RobotControler.h
* @AuthorSuude Kaynak - 152120211110
* @Date 16.12.2024
* @Brief RobotControler sýnýfýnýn tanýmýný içeren header dosyasý
*/

#ifndef ROBOTCONTROLER_H
#define ROBOTCONTROLER_H


#pragma once
#include <iostream>
#include "FestoRobotAPI.h"
#include "Pose.h"
#include "RobotInterface.h"
#include "SensorInterface.h"
#include "RobotOperator.h"

#include <string>
#include <list>

using namespace std;

//1. Aþama Kodlarý:

//class RobotControler
//{
//private:
//	
//	bool connectionStatus;
//	Pose* position;
//	FestoRobotAPI* RobotAPI;
//	
//public:
//	explicit RobotControler(RobotInterface& robotInterface): robot(robotInterface){}
//	~RobotControler() = default;
//	void turnLeft();
//	void turnRight();
//
//	void move(DIRECTION dir);
//	void moveForward();
//	void moveBackWard();
//	void moveLeft();
//	void moveRight();
//
//	void stop();
//
//	Pose getPose();
//
//	void print();
//
//	bool connectRobot();
//	bool disconnectRobot();
//
//	//2. aþama
//	void addSensor(shared_ptr<SensorInterface> sensor);
//	void updateSensors();
//	void openAccess(const string& password);
//	void closeAccess();
//};


//2. Aþama:

//Umay Ece Mantar 27.12.2024 152120221127

class RobotControler
{
private:
	FestoRobotAPI* api;
	RobotInterface* robot;             // pointer to the robot being controlled
	RobotOperator* robotOperator;      // pointer to the operator controlling the robot
	bool isAccessGranted;              // indicates whether access is granted for control
	list<SensorInterface*> sensorList; // list of sensors managed by the controller
public:
	RobotControler(RobotInterface* robotInt, RobotOperator* robop); // constructor initializes the robot and operator pointers
	~RobotControler();  // destructor handles cleanup if needed

	// movement functions to control the robot
	void turnLeft(); 
	void turnRight();
	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveRight();
	void stop();

	// retrieves the robot's current position
	Pose* getPose();

	// prints robot information or state
	void print();

	// manages robot connection
	bool connectRobot();
	bool disconnectRobot();

	// adds and updates sensors
	void addSensor(SensorInterface* sensor);
	void updateSensors();

	// manages access to the robot for control purposes
	bool openAccess(int);
	bool closeAccess(int);
};

#endif ROBOTCONTROLER_H