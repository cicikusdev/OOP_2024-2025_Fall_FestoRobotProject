#include "MAP.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;
//Umay Ece Mantar 152120221127 18.12.2024 - 22.12.2024 - 28.12.2024
//This file is the declaration of the member functions of the MAP class


// constructor to initialize the map with specified dimensions and grid size
MAP::MAP(int nx, int ny, double size): numberX(nx), numberY(ny), gridSize(size)
{
	grid.resize(numberY, vector<int>(numberX, 0));   // initialize the grid with zeros
}

MAP::~MAP()
{// destructor for cleanup
}

void MAP::insertPoint(const Point& point)// inserts a point into the map grid based on its coordinates
{
	int gridX = static_cast<int>(floor(point.getX() / gridSize)); // convert x coordinate to grid index
	int gridY = static_cast<int>(floor(point.getY() / gridSize)); // convert y coordinate to grid index

	if (gridX >= 0 && gridX < numberX && gridY >= 0 && gridY < numberY) { // check if indices are within bounds
		grid[gridY][gridX] = 1; // mark the grid cell as occupied
	}
}

// retrieves the value of a specific grid cell
int MAP::getGrid(int indexX, int indexY) const
{
	if (indexX >= 0 && indexX < numberX && indexY >= 0 && indexY < numberY) { // check if indices are within bounds
		return grid[indexY][indexX]; // return the value of the grid cell
	}
	return -1; // return -1 if indices are out of bounds
}

void MAP::setGrid(int indexX, int indexY, int value) // sets the value of a specific grid cell
{
	 if (indexX >= 0 && indexX < numberX && indexY >= 0 && indexY < numberY) { // check if indices are within bounds
        grid[indexX][indexY] = value; // set the grid cell value
    }
}

// clears the map by resetting all grid cells to 0
void MAP::clearMap()
{
	for (auto& row : grid) {  // iterate over each row in the grid
	fill(row.begin(), row.end(), 0); // reset all elements in the row to 0
	}
}

void MAP::printInfo() const // prints map information, including dimensions and total cells
{
	cout << "Map Information:" << endl;
	cout << "Grid size: " << gridSize << " meters" << endl;
	cout << "Number of grids in X direction: " << numberX << endl;
	cout << "Number of grids in Y direction: " << numberY << endl;
	cout << "Total number of cells: " << numberX * numberY <<endl;
}

// displays the map grid with occupied cells marked as 'x' and empty cells as '.'
void MAP::showMap() const
{
	for (int y = numberY - 1; y >= 0; --y) { // iterate over rows from top to bottom
		for (int x = 0; x < numberX; ++x) { // iterate over columns
			cout << (grid[y][x] == 0 ? "." : "x") << " ";  // display grid cell value
		}
		cout << endl;
	}
}

int MAP::getNumberX() const // returns the number of grid cells in the X direction
{
	return numberX;
}

int MAP::getNumberY() const // returns the number of grid cells in the Y direction
{
	return numberY;
}

double MAP::addGridSize()const // retrieves the grid size
{
	return gridSize;
}

void MAP::setGridSize(double size) // sets a new grid size
{
	gridSize = size;
}


ostream& operator<<(ostream& os, const MAP& map) // overloads the << operator for displaying map information and its grid
{
	os << "MAP Info:" << endl;
	os << "Number of grids in X direction: " << map.getNumberX() << endl;
	os << "Number of grids in Y direction: " << map.getNumberY() << endl;
	os << "Grid size: " << map.addGridSize() << endl;

	os << "Grid map:" << endl;
	
	for (int y = map.getNumberY() - 1; y >= 0; --y) { // iterate over rows from top to bottom
		os << setw(2) << y << " "; // display y-axis label
		for (int x = 0; x < map.getNumberX(); ++x) { // iterate over columns
			os << (map.getGrid(x, y) == 0 ? "." : "x") << " "; // display grid cell value
	}
		os << endl;
	}

	//x axis labels
	os << "   "; // indentation for x-axis labels
	for (int x = 0; x < map.getNumberX(); ++x) {
		os << setw(2) << x << " "; // display x-axis label
	}
	os << endl;

	return os;
}

