#include "Mapper.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;
//Kaðan Baþ 152120201083
//Umay Ece Mantar 152120221127
//Suude Kaynak 152120211110
//22.12.2024

//Umay Ece Mantar 28.12.2024

Mapper::Mapper(MAP* mapObj, RobotControler* controlerObj, SensorInterface* sensorObj): map(mapObj), controler(controlerObj), lidar(sensorObj)
{
	// constructor for initializing Mapper class with a map object, robot controller, and sensor interface
}

Mapper::~Mapper()
{
	// destructor; pointers are managed externally 
}

void Mapper::updateMap()// updates the map by retrieving the robot's current pose and lidar sensor readings
{
	if (!map || !controler || !lidar) { // ensure map, controller, and lidar objects are valid
		return;
	}
	Pose* currentpose = controler->getPose(); // get the robot's current pose from the controller
	if (!currentpose) { // check if the pose is valid
		return;
	}

	double rX, rY, rTh;
	currentpose->getXYTh(rX, rY, rTh); // extract x, y, and theta values from the pose
	
	for (int i = 0; i < 360; ++i) { // loop through 360 degrees to update the map
		double distance = lidar->getSensorValue(i); // get the distance from the lidar sensor for the current angle
		if (distance > 0) {  // only process valid distances

			double angle = (i * 3, 14 / 180) + rTh; // convert degrees to radians and add the robot's orientation
			double newX = rX + distance * cos(angle); // calculate new x-coordinate
			double newY = rY + distance * sin(angle); // calculate new y-coordinate

			Point point; // create a Point object to store the calculated coordinates
			point.setX(newX); 
			point.setY(newY);
			map->insertPoint(point); // insert the point into the map
		}
	}
}

// displays the current state of the map
void Mapper::showMap() const
{
	if (!map) { // check if the map object is valid
		return;
	}
	map->showMap(); // call the map's showMap function
}

// records the current map to a file
bool Mapper::recordMap() const
{
	if (!map) {
		return false;
	}
	Record record("recorded_map_from_mapper.txt"); // create a Record object to handle file writing

	if (!record.openFile()) { // check if the file was opened successfully
		return false;
	}

	stringstream ss;
	ss << "Map Size X: " << map->getNumberX() << endl; // add map dimensions to the stream
	ss << "Map Size Y: " << map->getNumberY() << endl;
	ss << "Grid: " << map->addGridSize() << endl;
	record.writeLine(ss.str()); // write the map information to the file

	for (int y = 0; y < map->getNumberY(); ++y) { // loop through the map grid to write its contents
		string line;
		for (int x = 0; x < map->getNumberX(); ++x) {
			line += (map->getGrid(x, y) == 0 ? "." : "x"); // represent empty cells with '.' and occupied cells with 'x'
		}
		record.writeLine(line); // write each row of the grid to the file
	}
	record.closeFile(); // close the file after writing
	return true;
}

