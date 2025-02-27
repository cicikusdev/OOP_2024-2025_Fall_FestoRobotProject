///**
// * @file PoseTest.cpp
// * @Author Suude Kaynak - 152120211110
// * @date 16.12.2024
// * @brief Pose class fonksiyonlarýnýn test edildiði dosya.
// */
//
//
//#include "RobotControler.h"
//#include "FestoRobotAPI.h"
//#include "Pose.h"
//#include <iostream>
//#include <cmath> // sqrt ve atan2 kullanýmý için
//#include <vector>
//vector<string> commands;
//using namespace std;
//
//int main() {
//    RobotControler* Festo;
//    Festo = new RobotControler;
//
//    // Pose nesneleri oluþtur
//    Pose p;                 // Default constructor
//    Pose p1(2, 3, 5);       // Parametreli constructor
//    Pose p2(4, 5, 7);
//
//    double x, y, th;
//
//    // getXYTh fonksiyonu testi
//    p1.getXYTh(x, y, th);
//    cout << "p1.getXYTh() çalýþtý: x = " << x << ", y = " << y << ", th = " << th << endl;
//
//    p2.getXYTh(x, y, th);
//    cout << "p2.getXYTh() çalýþtý: x = " << x << ", y = " << y << ", th = " << th << endl;
//
//    // setXYTh fonksiyonu testi
//    p.setXYTh(1, 2, 3);
//    p.getXYTh(x, y, th);
//    cout << "p.setXYTh() çalýþtý: x = " << x << ", y = " << y << ", th = " << th << endl;
//
//    // == operatörü testi
//    if (p1 == p2) {
//        cout << "== operatoru çalýþtý: p1 ve p2 eþit." << endl;
//    }
//    else {
//        cout << "== operatoru çalýþtý: p1 ve p2 eþit deðil." << endl;
//    }
//
//    // < operatörü testi
//    if (p1 < p2) {
//        cout << "< operatoru çalýþtý: p1, p2'den küçük." << endl;
//    }
//    else {
//        cout << "< operatoru çalýþtý: p1, p2'den küçük deðil." << endl;
//    }
//
//    // + operator testi
//    Pose p3 = p1 + p2;
//    p3.getXYTh(x, y, th);
//    cout << "+ operatoru çalýþtý: x = " << x << ", y = " << y << endl;
//
//    // - operator testi
//    Pose p4 = p1 - p2;
//    p4.getXYTh(x, y, th);
//    cout << "- operatoru çalýþtý: x = " << x << ", y = " << y << endl;
//
//    // += operator testi
//    p1 += p2;
//    p1.getXYTh(x, y, th);
//    cout << "+= operatoru çalýþtý: x = " << x << ", y = " << y << endl;
//
//    // -= operator testi
//    p1 -= p2;
//    p1.getXYTh(x, y, th);
//    cout << "-= operatoru çalýþtý: x = " << x << ", y = " << y << endl;
//
//    // Mesafe hesaplama testi
//    double distance = p1.findDistanceTo(p2);
//    cout << "findDistanceTo() çalýþtý: Mesafe = " << distance << endl;
//
//    // Açý hesaplama testi
//    double angle = p1.findAngleTo(p2);
//    cout << "findAngleTo() çalýþtý: Açý = " << angle << " derece" << endl;
//
//    Festo->disconnectRobot();
//    delete Festo;
//
//    return 0;
//}
//
