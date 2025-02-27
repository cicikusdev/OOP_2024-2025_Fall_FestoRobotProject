#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <vector>
#include <sstream>
#include "Point.h"
using namespace std;
//Umay Ece Mantar 152120221127 18.12.2024
//This file is the definition of the elements of the MAP class

class MAP
{
private:
	vector<vector<int>> grid; //2D array
	int numberX; //definition of the number X
	int numberY; //definition of the number Y
	double gridSize; //definition of the gridSize
public:
	MAP(int nx = 10, int ny = 10, double size = 1.0); /*default constructor of the MAP class, holding the point object
	from the Point class as a parameter. nx Number of grids in X direction, ny Number of grids in Y direction
	and size Size of each grid cell */
	~MAP(); //deconstructor of the MAP class
	void insertPoint(const Point& point); //to set the value of the grid that point object is settled on
	int getGrid(int indexX, int indexY) const; //return the value of the grid at the specified indice
	void setGrid(int indexX, int indexY, int value); //set the values of the grid at the specified indice
	void clearMap(); // set all the grids to 0
	void printInfo() const; // print the MAP info
	friend ostream& operator<<(ostream& os, const MAP& map); //friend operator of the MAP class to use the << operator with the objects
	void showMap() const; //print the grid info. "." if empty, "x" if not empty
	int getNumberX() const; //return the grid count on the X-axis
	int getNumberY() const; //return the grid count on the Y-axis
	double addGridSize()const; //return the size of the grids
	void setGridSize(double size); //set the size of the grids
	
};

#endif MAP_H