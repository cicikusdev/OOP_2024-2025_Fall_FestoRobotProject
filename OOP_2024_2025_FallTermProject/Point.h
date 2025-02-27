#ifndef POINT_H
#define POINT_H
#include <iostream>
#include "Pose.h"
using namespace std;
//Umay Ece Mantar 152120221127 18.12.2024
//This file is to define the member functions and variables of Point class
class Pose; //forward declaration

class Point
{
	friend class Pose; // pose class is allowed to access private members of Point
private:
	double x; // x-coordinate of the point
	double y; // y-coordinate of the point
public:
	Point(); //default constructor of the Point class.Initializes coordinates to default values.
	Point(double x_, double y_); // parameterized constructor of the Point class. Initializes coordinates with given values.
	~Point(); //deconstructor of the Point class
	double getX() const; // returns the x-coordinate of the point.
	void setX(double value); // sets the x-coordinate of the point to the given value.
	double getY() const; // returns the x-coordinate of the point.
	void setY(double value); // sets the y-coordinate of the point to the given value.
	bool operator==(const Pose& other);  /* Compares the current point with a Pose object.
	Returns true if the coordinates are equal, false otherwise. */
	void getPoint(double& x_, double& y_) const; // retrieves the coordinates of the point. (The values are passed by reference.)
	void setPoint(double x_, double y_);   // sets the coordinates of the point to the given values.
	double findDistanceTo(Point pos) const; // calculates the euclidean distance from the current point to the given point. 
	double findAngleTo(Point pos) const;  // calculates the angle (in radians) from the current point to the given point.
};

#endif POINT_H