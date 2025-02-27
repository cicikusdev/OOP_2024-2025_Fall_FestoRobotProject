/*
 * @file RobotControler.cpp
 * @Author Suude Kaynak - 152120211110
 * @date 16.12.2024
 * @brief RobotControler sýnýfýnýn fonksiyonlarýnýn tanýmlandýðý dosya.
 */
#include "RobotControler.h"
#include "FestoRobotAPI.h"
#include <iostream>
#include "FestoRobotInterface.h"

using namespace std;

//1. aþama Kodlarý:

//RobotControler::RobotControler(RobotInterface& robotInterface) : robot(robotInterface), accessGranted(false)
//{
//    connectionStatus = false;
//    position = new Pose();
//    RobotAPI = new FestoRobotAPI();
//}
//RobotControler::~RobotControler()
//{
//    delete position;
//    delete RobotAPI;
//}
///**
// * @brief Robotu sola döndürür.
// */
//void RobotControler::turnLeft() {
//    if (connectionStatus) {
//        RobotAPI->rotate(LEFT); // Sadece dönme iþlemi
//    }
//}
//
//
///**
// * @brief Robotu saða döndürür.
// */
//void RobotControler::turnRight() {
//    if (connectionStatus) {
//        RobotAPI->rotate(RIGHT); // Saða dön
//    }
//}
//
//
//void RobotControler::move(DIRECTION dir)
//{
//    if (connectionStatus) {
//        RobotAPI->move(dir);
//    }
//}
//
///**
// * @brief Robotu ileri hareket ettirir.
// */
//void RobotControler::moveForward() {
//    move(FORWARD);
//}
//
///**
// * @brief Robotu geri hareket ettirir.
// */
//void RobotControler::moveBackWard() {
//    move(BACKWARD);
//}
//
//
///**
// * @brief Robotu sola hareket ettirir.
// */
//void RobotControler::moveLeft() {
//    move(LEFT);
//}
//
///**
// * @brief Robotu saða hareket ettirir.
// */
//void RobotControler::moveRight() {
//    move(RIGHT);
//}
//
///**
// * @brief Robotu durdurur.
// */
//void RobotControler::stop() {
//    // Durma iþlemi ile ilgili robotun mevcut pozisyonunda bir deðiþiklik yapýlmaz.
//    cout << "Robot durduruldu. Mevcut pozisyon deðiþmeden kalýyor." << endl;
//
//    // Robotun kontrol API'sinden durma komutu
//    RobotAPI->stop();
//}
//
//
///**
// * @brief Robotun mevcut pozisyonunu döner.
// * @return Pose sýnýfýndan mevcut pozisyon.
// */
//Pose RobotControler::getPose() {
//    double x, y, th;
//    if (connectionStatus) {
//        RobotAPI->getXYTh(x, y, th);
//    }
//    position->setPose(x, y, th);
//    return *position;
//}
//
///**
// * @brief Robotun baðlantý durumunu ekrana yazdýrýr.
// */
//void RobotControler::print() {
//    if (connectionStatus) {
//        cout << "Robot baðlantý durumu: Baðlý" << endl;
//        double x, y, th;
//        position->getXYTh(x, y, th);
//        cout << "Robot Pozisyonu -> X: " << x << ", Y: " << y << ", TH: " << th << endl;
//    }
//    else {
//        cout << "Robot baðlantý durumu: Baðlý deðil" << endl;
//    }
//}
///**
// * @brief Robot ile baðlantý kurar.
// * @return Baðlantý baþarýlý ise true, deðilse false.
// */
//bool RobotControler::connectRobot(){
//    // Robot baðlantý iþlemi yapýlýr
//    if (!connectionStatus) { // Eðer connectionStatus false ise
//        RobotAPI->connect(); //True'ya döndür ( Robotu baðla)
//        connectionStatus = true;
//    }
//    // Durumu döndür
//    return connectionStatus;
//}
//
//
///**
// * @brief Robot ile baðlantýyý keser.
// * @return Baðlantý baþarýyla kesilirse true, deðilse false.
// */
//bool RobotControler::disconnectRobot() {
//    // disconnect() iþlemini çaðýr
//    if (connectionStatus) {
//        RobotAPI->disconnect();
//        connectionStatus = false;
//   }
//    // Baðlantý durumunu false olarak güncelle
//    // Baðlantý baþarýyla kesilmiþ varsayýlarak true dön
//    return !connectionStatus;
//}
//
//void RobotControler::addSensor(shared_ptr<SensorInterface> sensor)
//{
//    if (accessGranted) {
//        robot.addSensor(sensor);
//    }
//}
//
//void RobotControler::updateSensors()
//{
//    if (accessGranted) {
//        robot.updateSensors();
//    }
//}
//
//void RobotControler::openAccess(const string& password)
//{
//    if (password == "correct-one") {
//        accessGranted = true;
//    }
//}
//
//void RobotControler::closeAccess()
//{
//    if (accessGranted == true) {
//        accessGranted = false;
//    }
//}

//2. Aþama Kodlarý: Umay Ece Mantar 152120221127 27.12.2024


// RobotControler constructor initializes the robot interface and operator pointers, sets access to false
RobotControler::RobotControler(RobotInterface* robotInt, RobotOperator* robop): robot(robotInt), robotOperator(robop), isAccessGranted(false)
{

	robotOperator = new RobotOperator();
	if (robot == nullptr) {
		robot = new FestoRobotInterface(api);
	}
}

// RobotControler destructor clears the sensor list but does not delete robot or operator pointers
RobotControler::~RobotControler()
{ //we will not delete robot and operator pointers here
	sensorList.clear();
	delete robotOperator;
}

// commands the robot to turn left if access is granted
void RobotControler::turnLeft()
{
	if (!isAccessGranted) {
		return; // check access permission
	}
	if (robot) {
		robot->turnLeft(); // execute turn left
	}
}

// commands the robot to turn right if access is granted
void RobotControler::turnRight()
{
	if (!isAccessGranted) {
		return; // check access permission
	}
	if (robot) {
		robot->turnRight(); // execute turn right
	}
}

// commands the robot to move forward if access is granted
void RobotControler::moveForward()
{
	if (!isAccessGranted) {
		return; // check access permission
	}
	if (robot) {
		robot->moveForward(); // execute move forward
	}
}

// commands the robot to move backward if access is granted
void RobotControler::moveBackward()
{
	if (!isAccessGranted) {
		return; // check access permission
	}
	if (robot) {
		robot->moveBackward(); // execute move backward
	}
}

// commands the robot to move left if access is granted
void RobotControler::moveLeft()
{
	if (!isAccessGranted) {
		return; // check access permission
	}
	if (robot) {
		robot->moveLeft(); //execute move left
	}
}

// commands the robot to move right if access is granted
void RobotControler::moveRight()
{
	if (!isAccessGranted) {
		return; // check access permission
	}
	if (robot) {
		robot->moveRight(); //execute move right
	}
}

// commands the robot to stop if access is granted
void RobotControler::stop()
{
	if (!isAccessGranted) {
		return; // check access permission
	}
	if (robot) {
		robot->stop(); // execute stop
	}
}

// retrieves the current pose of the robot if access is granted
Pose* RobotControler::getPose()
{
	if (!isAccessGranted) {
		return nullptr; // check access permission
	}
	if (robot) {
		return robot->getPose(); // get pose from the robot
	}
	return nullptr;
}

// prints robot information if access is granted
void RobotControler::print()
{
	if (!isAccessGranted) {
		return; // check access permission
	}

	if (robot) {
		robot->print(); // print robot details
	}
}

// establishes a connection with the robot if access is granted
bool RobotControler::connectRobot()
{
	if (!isAccessGranted) { //access control
		return false; //no access, connection failure
	}
	if (!robot) { //is there a robot object?
		return false;  //there is no robot object, connection failure
	}
	return robot->connectRobot();	//yes there is, returns the result of the connection of robot
}

// disconnects the robot if access is granted
bool RobotControler::disconnectRobot()
{
	if (!isAccessGranted) { // check access permission
		return false; 
	}
	if (!robot) {
		return false;  // disconnect robot
	}
	return robot->disconnectRobot();
}

// adds a sensor to the robot if access is granted
void RobotControler::addSensor(SensorInterface* sensor)
{
	if (sensor) {
		//robot->addSensor(sensor); // add sensor to robot
		sensorList.push_back(sensor); // add to local list
	}
}

// updates all sensors connected to the robot
void RobotControler::updateSensors()
{
	if (!isAccessGranted) {
		return;
	}

	for (auto sensor : sensorList) {
		sensor->update();
	}

	
}

// grants control access to the robot if the access code is correct
bool RobotControler::openAccess(int code)
{
	if (robotOperator->checkAccessCode(code)) { // control of the correct access code
		isAccessGranted = true; // access granted
		cout << "Access granted. You can now control the robot." << endl;
		return true; 
	}
	else {
		cout << "Invalid access code. Access denied." << endl;
		return false;
	}
}

// revokes control access if the access code is correct
bool RobotControler::closeAccess(int code)
{
	if (robotOperator->checkAccessCode(code)) { // control of the correct access code
		isAccessGranted = false; // access revoked
		cout << "Access denied. Robot control is disabled." << endl;
		return true;
	}
	else {
		cout << "Invalid access code. Unable to revoke access." << endl;
		return false;
	}
}
