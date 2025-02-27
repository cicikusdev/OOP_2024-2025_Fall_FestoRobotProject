///**
// * @file PoseTest.cpp
// * @Author Suude Kaynak - 152120211110
// * @date 16.12.2024
// * @brief Pose class fonksiyonlar�n�n test edildi�i dosya.
// */
//
//
//#include "RobotControler.h"
//#include "FestoRobotAPI.h"
//#include "Pose.h"
//#include <iostream>
//#include <cmath> // sqrt ve atan2 kullan�m� i�in
//#include <vector>
//vector<string> commands;
//using namespace std;
//
//int main() {
//    RobotControler* Festo;
//    Festo = new RobotControler;
//
//    // Pose nesneleri olu�tur
//    Pose p;                 // Default constructor
//    Pose p1(2, 3, 5);       // Parametreli constructor
//    Pose p2(4, 5, 7);
//
//    double x, y, th;
//
//    // getXYTh fonksiyonu testi
//    p1.getXYTh(x, y, th);
//    cout << "p1.getXYTh() �al��t�: x = " << x << ", y = " << y << ", th = " << th << endl;
//
//    p2.getXYTh(x, y, th);
//    cout << "p2.getXYTh() �al��t�: x = " << x << ", y = " << y << ", th = " << th << endl;
//
//    // setXYTh fonksiyonu testi
//    p.setXYTh(1, 2, 3);
//    p.getXYTh(x, y, th);
//    cout << "p.setXYTh() �al��t�: x = " << x << ", y = " << y << ", th = " << th << endl;
//
//    // == operat�r� testi
//    if (p1 == p2) {
//        cout << "== operatoru �al��t�: p1 ve p2 e�it." << endl;
//    }
//    else {
//        cout << "== operatoru �al��t�: p1 ve p2 e�it de�il." << endl;
//    }
//
//    // < operat�r� testi
//    if (p1 < p2) {
//        cout << "< operatoru �al��t�: p1, p2'den k���k." << endl;
//    }
//    else {
//        cout << "< operatoru �al��t�: p1, p2'den k���k de�il." << endl;
//    }
//
//    // + operator testi
//    Pose p3 = p1 + p2;
//    p3.getXYTh(x, y, th);
//    cout << "+ operatoru �al��t�: x = " << x << ", y = " << y << endl;
//
//    // - operator testi
//    Pose p4 = p1 - p2;
//    p4.getXYTh(x, y, th);
//    cout << "- operatoru �al��t�: x = " << x << ", y = " << y << endl;
//
//    // += operator testi
//    p1 += p2;
//    p1.getXYTh(x, y, th);
//    cout << "+= operatoru �al��t�: x = " << x << ", y = " << y << endl;
//
//    // -= operator testi
//    p1 -= p2;
//    p1.getXYTh(x, y, th);
//    cout << "-= operatoru �al��t�: x = " << x << ", y = " << y << endl;
//
//    // Mesafe hesaplama testi
//    double distance = p1.findDistanceTo(p2);
//    cout << "findDistanceTo() �al��t�: Mesafe = " << distance << endl;
//
//    // A�� hesaplama testi
//    double angle = p1.findAngleTo(p2);
//    cout << "findAngleTo() �al��t�: A�� = " << angle << " derece" << endl;
//
//    Festo->disconnectRobot();
//    delete Festo;
//
//    return 0;
//}
//
