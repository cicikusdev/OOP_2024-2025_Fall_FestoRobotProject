#include "LidarSensor.h"
#include <algorithm>
#include <stdexcept> // out_of_range ve runtime_error için gerekli
#include <cstring>

//Kaðan Baþ 152120201083 20.12.2024
//Umay Ece Mantar 152120221127 22.12.2024 (Hatalarýn Düzeltilmesi)

//Umay Ece Mantar 27.12.2024

using namespace std; // Standart namespace kullanýmý

//1. Aþama Kodlarý:

//// Constructor
//LidarSensor::LidarSensor(FestoRobotAPI* robotAPI) : roboAPI(robotAPI), rangeNumber(0) {}
//
//// Güncel lidar mesafelerini ranges dizisine yükler
//void LidarSensor::update() {
//    // LIDAR ölçüm sayýsýný al
//    rangeNumber = roboAPI->getLidarRangeNumber();
//
//    // Depolama vektörümüzün boyutunu yeniden ayarla
//    ranges.resize(rangeNumber);
//
//    // LIDAR verisi için geçici bir tampon oluþtur
//    float* lidarData = new float[rangeNumber];
//
//    // API aracýlýðýyla LIDAR verisini al
//    roboAPI->getLidarRange(lidarData);
//
//    // Verileri vektörümüze kopyala ve dönüþtür
//    for (int i = 0; i < rangeNumber; ++i) {
//        ranges[i] = static_cast<double>(lidarData[i]);
//    }
//
//    // Temizleme iþlemi
//    delete[] lidarData;
//}
//
//// i. indeksindeki lidar verisini döndürür
//double LidarSensor::getRange(int i) const {
//    if (i < 0 || i >= rangeNumber)
//        throw out_of_range("Index out of range");
//    return ranges[i];
//}
//
//// En küçük uzaklýk ve indeksini döndürür
//pair<int, double> LidarSensor::getMin() const {
//    if (ranges.empty())
//        throw runtime_error("No lidar data available");
//    auto minIt = min_element(ranges.begin(), ranges.end());
//    return { static_cast<int>(distance(ranges.begin(), minIt)), *minIt };
//}
//
//// En büyük uzaklýk ve indeksini döndürür
//pair<int, double> LidarSensor::getMax() const {
//    if (ranges.empty())
//        throw runtime_error("No lidar data available");
//    auto maxIt = max_element(ranges.begin(), ranges.end());
//    return { static_cast<int>(distance(ranges.begin(), maxIt)), *maxIt };
//}
//
//// [] operatörü: getRange ile ayný iþlev
//double LidarSensor::operator[](int i) const {
//    return getRange(i);
//}
//
//// i. indeksteki lidar verisinin robota göre açýsýný döndürür
//double LidarSensor::getAngle(int i) const {
//    if (i < 0 || i >= rangeNumber)
//        throw out_of_range("Index out of range");
//    // 120 derece (-4PI/6 ile 4PI/6) arasýnda lineer daðýlým
//    return -2.0 * M_PI / 3.0 + i * (4.0 * M_PI / 3.0) / rangeNumber;
//}


//2. Aþama Kodlarý: Umay Ece Mantar 152120221127 28.12.2024

LidarSensor::LidarSensor(FestoRobotAPI* api): FestoRobotSensorInterface(api) 
{
	rangeNumber = robotAPI->getLidarRangeNumber();  // initialize the range number and allocate memory for ranges array
	ranges = new double[rangeNumber];

	for (int i = 0; i < rangeNumber; i++) { // initialize all range values to 0.0
		ranges[i] = 0.0;
	}
}

LidarSensor::LidarSensor(const LidarSensor& other): FestoRobotSensorInterface(other.robotAPI)
{ // copy constructor: copy range number and clone the ranges array
	rangeNumber = other.rangeNumber;
	ranges = new double[rangeNumber];
	memcpy(ranges, other.ranges, rangeNumber * sizeof(double));
}

LidarSensor::~LidarSensor()
{// free memory allocated for ranges
	delete[] ranges;
}

void LidarSensor::update()  // update the sensor data from the robot API
{
	float* tempR = new float[rangeNumber]; // temporary array to store range data
	robotAPI->getLidarRange(tempR);

	for (int i = 0; i < rangeNumber; i++) { // convert float data to double and store it in ranges array
		ranges[i] = static_cast<double>(tempR[i]);
	}
	delete[] tempR;  // free temporary array
}

string LidarSensor::getSensorType() 
{
	return "Lidar Sensor";  // return the type of sensor
}

double LidarSensor::getSensorValue(int index) 
{
	// validate index and return the corresponding range value
	if (!isValidIndex(index, rangeNumber)) {
		throw out_of_range("Lidar sensor index is out of range");
	}
	return ranges[index];
}

double LidarSensor::operator[](int index) const
{
	// overload operator[] for read-only access to ranges
	if (!isValidIndex(index, rangeNumber)) {
		throw out_of_range("Lidar sensor index is out of range");
	}
	return ranges[index];
}

double& LidarSensor::operator[](int index)
{
	// overload operator[] for writable (non const) access to ranges
	if (!isValidIndex(index, rangeNumber)) {
		throw out_of_range("Lidar sensor index is out of range");
	}
	return ranges[index];
}

double LidarSensor::getRange(int index) const
{
	// return the range value for the given index
	if (index < 0 || index >= rangeNumber) {
		throw out_of_range("Index out of range");
		return ranges[index];
	}
}

double LidarSensor::getMax(int& index) const
{ // find the maximum range value and its index
	if (!ranges || rangeNumber <= 0) {
		throw runtime_error("No sensor data");
	}

	double maxValue = ranges[0];
	index = 0;
	for (int i = 1; i < rangeNumber; i++) {
		if (ranges[i] > maxValue) {
			maxValue = ranges[i];
			index = i;
		}
	}
	return maxValue;
}

double LidarSensor::getMin(int& index) const
{ // find the minimum range value and its index
	if (!ranges || rangeNumber <= 0) {
		throw runtime_error("No sensor data");
	}

	double minValue = ranges[0];
	index = 0;

	for (int i = 1; i < rangeNumber; i++) {
		if (ranges[i] < minValue) {
			minValue = ranges[i];
			index = i;
		}
	}
	return minValue;
}

double LidarSensor::getAngle(int i) const
{
	if (!ranges || i < 0 || i >= rangeNumber) { // return the angle corresponding to the given index
		throw out_of_range("Index out of range");
		// calculate and return angle in the range of -180 to +180 degrees
		return (i * 360.0 / rangeNumber) - 180.0;
	}
}