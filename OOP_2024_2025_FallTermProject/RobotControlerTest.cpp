///*
//* @File RobotControlerTest.cpp
//* @Author Suude Kaynak - 152120211110
//* @Date 18.12.2024
//* @Brief RobotControler sýnýfýnýn test dosyasýdýr
//*/
//#include "RobotControler.h"
//#include <iostream>
//#include <vector>
//#include <thread> // For std::this_thread::sleep_for
//#include <chrono> // For std::chrono::seconds
//
//using namespace std;
//
//int main() {
//    // Simulated command sequence
//    vector<string> commands = {
//        "connectRobot", "print", "moveForward", "turnLeft", "moveRight",
//        "moveBackWard", "turnRight", "stop", "getPose", "disconnectRobot"
//    };
//
//    // Create RobotControler instance
//    RobotControler robotControl;
//
//    for (const string& command : commands) {
//        cout << "Executing: " << command << endl;
//
//        if (command == "connectRobot") {
//            if (robotControl.connectRobot()) {
//                cout << "Robot successfully connected.\n";
//            }
//            else {
//                cout << "Failed to connect the robot.\n";
//            }
//        }
//        if (command == "disconnectRobot") {
//            if (robotControl.disconnectRobot()) {
//                cout << "Robot successfully disconnected.\n";
//            }
//            else {
//                cout << "Failed to disconnect the robot.\n";
//            }
//        }
//        if (command == "turnLeft") {
//            robotControl.turnLeft();
//        }
//        if (command == "turnRight") {
//            robotControl.turnRight();
//        }
//        if (command == "moveForward") {
//            robotControl.moveForward();
//        }
//        if (command == "moveBackWard") {
//            robotControl.moveBackWard();
//        }
//        if (command == "moveLeft") {
//            robotControl.moveLeft();
//        }
//        if (command == "moveRight") {
//            robotControl.moveRight();
//        }
//        if (command == "stop") {
//            robotControl.stop();
//        }
//        if (command == "getPose") {
//            Pose pose = robotControl.getPose();
//            double x, y, th;
//            pose.getXYTh(x, y, th);
//            cout << "Pose -> X: " << x << ", Y: " << y << ", TH: " << th << endl;
//        }
//        if (command == "print") {
//            robotControl.print();
//        }
//
//        // Pause between commands
//        this_thread::sleep_for(chrono::seconds(2)); // Replace 10 seconds with 2 seconds for faster testing
//    }
//
//    return 0;
//}
//
