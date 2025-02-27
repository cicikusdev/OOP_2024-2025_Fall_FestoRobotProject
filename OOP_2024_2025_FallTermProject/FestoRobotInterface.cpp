#include "FestoRobotInterface.h"
#include <iostream>
using namespace std;
//Umay Ece Mantar 28.12.2024 152120221127
FestoRobotInterface::FestoRobotInterface(FestoRobotAPI* api): robotAPI(api)
{
	robotAPI = new FestoRobotAPI;
	position = new Pose();
	connectionStatus = false;
	currentDirection = FORWARD;
}

void FestoRobotInterface::turnLeft()
{
	if (connectionStatus == true) {
		robotAPI->rotate(LEFT);
	}
}

void FestoRobotInterface::turnRight()
{
	if (connectionStatus == true) {
		robotAPI->rotate(RIGHT);
	}
	
}

void FestoRobotInterface::moveForward()
{
	if (connectionStatus == true) {
		robotAPI->move(FORWARD);
	}
}

void FestoRobotInterface::moveBackward()
{
	if (connectionStatus == true) {
		robotAPI->move(BACKWARD);
	}
}

void FestoRobotInterface::moveLeft()
{
	if (connectionStatus == true) {
		robotAPI->move(LEFT);
	}
}

void FestoRobotInterface::moveRight()
{
	if (connectionStatus == true) {
		robotAPI->move(RIGHT);
	}
}

void FestoRobotInterface::print()
{
	double x, y, th;
	position->getXYTh(x, y, th);
	cout << "-Robot Position- X: " << x << " Y: " << y << " Angle: " << th << endl;
}
void FestoRobotInterface::stop()
{
	robotAPI->stop();
}

Pose* FestoRobotInterface::getPose()
{
	double x, y, th;
	robotAPI->getXYTh(x, y, th);
	position->setPose(x, y, th);
	return position;
	
}

bool FestoRobotInterface::connectRobot()
{
	if (connectionStatus == false) {
		robotAPI->connect();
		connectionStatus = true;
	}
	return connectionStatus;
}

bool FestoRobotInterface::disconnectRobot()
{
	if (connectionStatus == true) {
		robotAPI->disconnect();
		connectionStatus = false;
	}
	return connectionStatus;
}
