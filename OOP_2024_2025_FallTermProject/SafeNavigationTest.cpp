//
//// @File SafeNavigationTest.cpp
//// @Author Suude Kaynak - 152120211110
//// @Date 18.12.2024
//// @Brief SafeNavigation s�n�f� i�in test dosyas�d�r
////
//
//#include "SafeNavigation.h"
//#include "IRSensor.h"
//#include "RobotControler.h"
//#include <iostream>
//
//// Fake IRSensor implementation for testing
//class FakeIRSensor : public IRSensor {
//public:
//    double range;  // Sim�le edilmi� mesafe
//
//    FakeIRSensor(double initialRange) { range = initialRange; }
//    double getRange()const { return range; }
//};
//
//int main() {
//    // Sim�le edilmi� sensor
//    FakeIRSensor fakeSensor(1.0);  // Ba�lang��ta 1 metre uzakl�k
//    RobotControler controller;   // Ger�ek RobotController kullan�m�
//
//    // SafeNavigation nesnesini olu�tur
//    SafeNavigation safeNav(&fakeSensor, &controller);
//
//    std::cout << "Testing moveForwardSafe():\n";
//    safeNav.moveForwardSafe();
//
//    fakeSensor.range = 0.4;  // Engel mesafesini de�i�tir
//    std::cout << "\nTesting moveBackwardSafe():\n";
//    safeNav.moveBacwardSafe();
//
//    return 0;
//}
