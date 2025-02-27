#ifndef POSE_H
#define POSE_H


#include <iostream>
#include "FestoRobotAPI.h"
#include "Point.h"
using namespace std;
/*
@File Pose.h
@Author Suude Kaynak-152120211110
@Date 13.12.2024
@brief Pose s�n�f�n�n tan�m�n� yapan dosyad�r
*/
class Pose
{
	friend class RobotControler;
	friend class Point;
private:
	double x;
	double y;
	double th;
public:
	FestoRobotAPI* RobotAPI;
	void getXYTh(double& X, double& Y, double& Th)const; /* X, Y ve Z axislerindeki de�erleri metre cinsinden d�nd�r�r */
	void setXYTh(double _X, double _Y, double _Th); /* X, Y ve Z axislerindeki de�erleri metre cinsinden ayarlar */
	bool operator==(const Pose & other);/* == operator */
	Pose operator+(const Pose& other);/* + operator*/
	Pose operator-(const Pose& other);/* - operator*/
	Pose& operator+=(const Pose& other);/* += operator */
	Pose& operator-=(const Pose& other);/* -= operator */
	bool operator<(const Pose& other);/* < operator*/
	void getPose(double& _x, double& _y, double& _th); /* pos de�erini al�r */
	void setPose(double& _x, double _y, double _th); /* pos de�erini set eder */
	double findDistanceTo(Pose pos); /* verilen pos'a olan uzakl��� bulur*/
	double findAngleTo(Pose pos); /* verilern pos'a olan a��y� bulur */
	Pose(double _x, double _y, double Th); /* constructor function */
	Pose(); /* default constructor */

};

#endif // !1