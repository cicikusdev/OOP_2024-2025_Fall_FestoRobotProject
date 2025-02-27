#ifndef ROBOTINTERFACE_H
#define ROBOTINTERFACE_H
#include <vector>
#include <iostream>
#include "Pose.h"
#include "SensorInterface.h"
using namespace std;

//Umay Ece Mantar 152120221127 27.12.2024
//

class RobotInterface
{
protected:
    Pose* position;                // tracks the robot's current position
    bool connectionStatus;         // indicates whether the robot is connected
    //vector<SensorInterface*> sensorList; // list of attached sensors
public:
	virtual ~RobotInterface() = default; // ensures proper cleanup for derived classes

    // pure virtual functions for robot movement and actions
    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    virtual void moveForward() = 0;
    virtual void moveBackward() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void print() = 0;

    virtual void stop() = 0;
    // retrieves the current position of the robot
    virtual Pose* getPose() = 0;

    // connects or disconnects the robot
    virtual bool connectRobot() = 0;
    virtual bool disconnectRobot() = 0;

    // adds a sensor to the list of attached sensors
    //virtual void addSensor(SensorInterface* sensor) {
    //    if (sensor != nullptr) {
    //        sensorList.push_back(sensor);
    //    }
    // }

    // updates all sensors attached to the robot
    //void updateSensors() {
    //    for (auto sensor : sensorList) {
    //        sensor->update();
    //    }
    //}
};

#endif //ROBOTINTERFACE_H