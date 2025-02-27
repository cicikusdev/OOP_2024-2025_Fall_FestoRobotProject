#include "Point.h"
#include "Pose.h"
#include <iostream>
#include <cmath>
using namespace std;
//Umay Ece Mantar 152120221127 18.12.2024
//This file is to declare the member functions of Point class

Point::Point(): x(0), y(0)
{
	/*
	This is the default constructor for the Point class. It initializes the x and y coordinates to 0.
	This constructor is called when a Point object is created without any initial values for the coordinates.
	*/
}

Point::Point(double x_, double y_): x(x_), y(y_)
{
	/*
	This is a parameterized constructor. It initializes the Point object with the values passed as arguments (_x and _y). 
	These values are used to set the x and y coordinates of the point.
	*/
}

Point::~Point()
{
	/*
	This is the destructor for the Point class. It is used to clean up any resources when the object is destroyed.
	*/
}

double Point::getX() const //returns the current x coordinate of the point.
{
	return x;
}

void Point::setX(double value) // sets the x coordinate of the point to the given value.
{
	x = value;
}

double Point::getY() const //returns the current y coordinate of the point
{
	return y;
}

void Point::setY(double value) //sets the y coordinate of the point to the given value
{
	y = value;
}

bool Point::operator==(const Pose& other) //this operator compares a Point object with a Pose object.
{
	double poseX, poseY, poseTh;
	other.getXYTh(poseX, poseY, poseTh); /* This function call retrieves the x and y coordinates of the Pose object and 
	stores them in the local variables poseX and poseY. 
	The th (angle) is also retrieved but is not used here.*/

	//returns true if both x and y coordinates are equal between the Point and Pose objects, otherwise it returns false
	return (x == poseX && y == poseY); 
}

void Point::getPoint(double& x_, double& y_) const
{ //this method retrieves the coordinates of the point and assigns them to the passed reference variables _x and _y.
	x_ = x;
	y_ = y;
}

void Point::setPoint(double x_, double y_)
{//This method sets both the x and y coordinates of the point to the given values _x and _y.

	x = x_;
	y = y_;
}

double Point::findDistanceTo(Point pos) const
{//this method calculates the Euclidean distance between the current point and another point (pos).
	return sqrt(pow((x - pos.x), 2) + pow((y - pos.y), 2));
}

double Point::findAngleTo(Point pos) const
{/*
 this method calculates the angle from the current point (this) to another point (pos) using the atan2 function
 which returns the arctan of the two given numbers
 */
	double distancex = pos.x - x;
	double distancey = pos.y - y;
	return atan2(distancey, distancex);
}
