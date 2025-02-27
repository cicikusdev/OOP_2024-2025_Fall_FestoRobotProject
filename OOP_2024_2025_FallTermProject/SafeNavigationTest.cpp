//
//// @File SafeNavigationTest.cpp
//// @Author Suude Kaynak - 152120211110
//// @Date 18.12.2024
//// @Brief SafeNavigation sýnýfý için test dosyasýdýr
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
//    double range;  // Simüle edilmiþ mesafe
//
//    FakeIRSensor(double initialRange) { range = initialRange; }
//    double getRange()const { return range; }
//};
//
//int main() {
//    // Simüle edilmiþ sensor
//    FakeIRSensor fakeSensor(1.0);  // Baþlangýçta 1 metre uzaklýk
//    RobotControler controller;   // Gerçek RobotController kullanýmý
//
//    // SafeNavigation nesnesini oluþtur
//    SafeNavigation safeNav(&fakeSensor, &controller);
//
//    std::cout << "Testing moveForwardSafe():\n";
//    safeNav.moveForwardSafe();
//
//    fakeSensor.range = 0.4;  // Engel mesafesini deðiþtir
//    std::cout << "\nTesting moveBackwardSafe():\n";
//    safeNav.moveBacwardSafe();
//
//    return 0;
//}
