/*
* @File SafeNavigation.cpp
* @Author Suude KAYNAK - 152120211110
* @Date 18.12.2024
* @Brief SafeNavigation sýnýfýnýn fonksiyonlarýnýn tanýmlandýðý dosya
*/
#include "SafeNavigation.h"
#include "IRSensor.h"
#include "RobotControler.h"
#include <iostream>
using namespace std;


//Aþama 2 Kodlarý: Umay Ece Mantar 152120221127 28.12.2024

// SafeNavigation constructor initializes the sensor, controller, and sets the initial state to STOP
SafeNavigation::SafeNavigation(SensorInterface* sns, RobotControler* cntrl)
    : sensor(sns), controller(cntrl), state(MOVESTATE::STOP)
{
}

// safely moves the robot forward if the path ahead is clear
void SafeNavigation::moveForwardSafe() {
    if (sensor == nullptr || controller == nullptr) {
        return; // check if sensor and controller are valid
    }
    const double safe_distance = 0.3; // define the minimum safe distance
    while (true) {
        sensor->update();
        double front = sensor->getSensorValue(0); // get the distance from the front sensor
        double front_left = sensor->getSensorValue(1);
        double front_right = sensor->getSensorValue(8);
        cout << "IR Sensor [Front]: " << front << endl;
        cout << "IR Sensor [Front Left]: " << front_left << endl;
        cout << "IR Sensor [Front Right]: " << front_right << endl;

        if (front > safe_distance && front_left > safe_distance && front_right > safe_distance) {
            state = MOVESTATE::MOVING; // change state to MOVING
            controller->moveForward();  // command robot to move forward
        }
        else {
            cout << "Obstacle detected for forward, stopping." << endl;
            state = MOVESTATE::STOP; // change state to STOP
            controller->stop(); // stop the robot
            break;
        }
    }
}

void SafeNavigation::moveBacwardSafe() { // safely moves the robot backward if the path behind is clear
    if (sensor == nullptr || controller == nullptr) {
        return; // check if sensor and controller are valid
    }
    const double safe_distance = 0.3; // define the minimum safe distance
    while (true) {
        sensor->update();
        /*double back_distance = sensor->getSensorValue(5);*/ // get the distance from the back sensor
        double back_left_one = sensor->getSensorValue(4); // left-back sensor
        double back_right_one = sensor->getSensorValue(5); // right-back sensor
        cout << "IR Sensor [back left]: " << back_left_one << endl;
        cout << "IR Sensor [back right]: " << back_right_one << endl;

        if (back_left_one > safe_distance && back_right_one > safe_distance) {

            state = MOVESTATE::MOVING; // change state to MOVING
            controller->moveBackward(); // command robot to move backward

        }
        else {
            cout << "Obstacle detected for backward, stopping." << endl;
            state = MOVESTATE::STOP; // change state to STOP
            controller->stop(); // stop the robot
            return;
        }
    }    
}
