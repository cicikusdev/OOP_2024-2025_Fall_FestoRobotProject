/*
@file Pose.cpp
@Author Suude Kaynak - 152120211110
@date 13.12.2024
@brief Pose.cpp dosyas�
*/

#include "Pose.h"
using namespace std;

Pose::Pose(double _x = 0, double _y = 0, double _th = 0) {
	x = _x;
	y = _y;
	th = _th;
	RobotAPI = nullptr;
}

/*FestoRobotAPI falan i�eren bir constructor fuct. */
Pose::Pose() {
	RobotAPI = new FestoRobotAPI;
	RobotAPI->connect();

	RobotAPI->getXYTh(x,y,th); // RobotAPI'den koordinatlar� �ekiyoruz
	
}


void Pose::getXYTh(double& X, double& Y, double& Th)const {
	X = x;
	Y = y;
	Th = th;
}

// setXYTh fonksiyonu: X, Y, Th de�erlerini set eder
void Pose::setXYTh(double _X, double _Y, double _Th) {
	x = _X;
	y = _Y;
	th = _Th;
}

/*
*operator==
*verilen pose bizim pose'umuza e�it mi diye kontrol eder
*e�itse true d�nd�r�r, de�ilse false d�nd�r�r
*/
bool Pose::operator==(const Pose& other) {
	if (this->x == other.x && this->y == other.y) {
		return true;
	}
	else {
		return false;
	}
}
/*
*operator+
*iki pose'u toplar
*toplam� d�nd�r�r
*/
Pose Pose::operator+(const Pose& other) {
	Pose p(0, 0, 0);
	p.x = this->x + other.x;
	p.y = this->y + other.y;
	return p;
}
/*
* operator-
* ki pose aras�nda ��karma i�lemi yapar
* sonucu d�nd�r�r
*/
Pose Pose::operator-(const Pose& other) {
	Pose p(0, 0, 0);
	p.x = this->x - other.y;
	p.y = this->y - other.y;
	return y;
}
/*
* operator +=
* iki pose'u toplar ve ikisinden birini result olarak ayarlar
* result'� d�nd�r�r
*/
Pose& Pose::operator+=(const Pose& other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}
/*
* operator -=
* iki pose aras�nda ��karma i�lemi yapar
* ikisinden birini result olarak ayarlar
* result'� d�nd�r�r
*/
Pose& Pose::operator-=(const Pose& other) {
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}
/*
* < operator iki pose aras�nda ��karma i�lemi yapar
* ikisinden birini sonu� olarak ayarlar
* sa�daki b�y�kse true d�nd�r�r, soldaki b�y�kse false d�nd�r�r
*/
bool Pose::operator<(const Pose& other) {
	if (this->x < other.x && this->y < other.y) {
		return true;
	}
	else {
		return false;
	}
	
}
/*
* x,y ve th parametrelerini pose'a e�itler
*/
void Pose::getPose(double& _x, double& _y, double& _th) {
	_x = x;
	_y = y;
	_th = th;
}
/*
* x,y,th(double) de�erlerini set eder
*/
void Pose::setPose(double& _x, double _y, double _th) {
	x = _x;
	y = _y;
	th = _th;
}
/*
* verilen pos de�erleri aras�ndaki mesafeyi bulur
* distance(double) de�erini d�nd�r�r
*/
double Pose::findDistanceTo(Pose pos) {
	return sqrt(((this->x - pos.x) * (this->x - pos.x)) + ((this->y - pos.y) * (this->y - pos.y)));
}
/*
* verilen pos de�erleri aras�ndaki a��y� bulur
* angle()double de�erini d�nd�r�r
*/
double Pose::findAngleTo(Pose pos) {
	return atan2(pos.y - this->y, pos.x - this->x) * (180.0 / 3.141592653589793238463);
}