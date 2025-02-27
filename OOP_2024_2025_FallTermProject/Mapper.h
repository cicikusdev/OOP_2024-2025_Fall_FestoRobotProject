#ifndef MAPPER_H
#define MAPPER_H

#include "MAP.h"
#include "Pose.h"
#include "Record.h"
//#include "LidarSensor.h"
#include "RobotControler.h"
#include "Record.h"
#include "SensorInterface.h"
#include <vector>
//Kaðan Baþ 152120201083
//Umay Ece Mantar 152120221127
//Suude Kaynak 152120211110
//22.12.2024
 
//Umay Ece Mantar 152120221127 28.12.2024
class Mapper {
private:
    MAP* map; // pointer to the map object
    RobotControler* controler; // pointer to the robot controller
    SensorInterface* lidar; // pointer to a lidar sensor for mapping
public:
    Mapper(MAP* mapObj = nullptr, RobotControler* controlerObj = nullptr, SensorInterface* sensorObj = nullptr); //constructor with nullptr values from the beginning
    ~Mapper(); //destructor
    
    void updateMap(); // updates the map using sensor data
    void showMap() const; // displays the current map
    bool recordMap() const; // saves the map data

};


#endif  MAPPER_H
