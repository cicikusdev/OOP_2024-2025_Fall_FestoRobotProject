#ifndef FESTOROBOTINTERFACE_H
#define FESTOROBOTINTERFACE_H

#include "RobotInterface.h"
#include "FestoRobotAPI.h"

#include <iostream>
using namespace std;
//Umay Ece Mantar 27.12.2024 152120221127
class RobotInterface;

class FestoRobotInterface : public RobotInterface
{
private:
    FestoRobotAPI* robotAPI; // pointer to the robot API for robot control
    DIRECTION currentDirection; // current movement direction of the robot
public:
	FestoRobotInterface(FestoRobotAPI* api);
    virtual void turnLeft() override; // turns the robot to the left
    virtual void turnRight() override; // turns the robot to the right
    virtual void moveForward() override; // moves the robot forward
    virtual void moveBackward() override; // moves the robot backward
    virtual void moveLeft() override; // moves the robot to the left
    virtual void moveRight() override; // moves the robot to the right
    virtual void print() override; // prints the robot's current state

    virtual void stop() override; //stops the robot
    virtual Pose* getPose() override; // retrieves the current pose of the robot

    virtual bool connectRobot() override; // connects to the robot
    virtual bool disconnectRobot() override; // disconnects the robot
    
};

#endif //FESTOROBOTINTERFACE_H