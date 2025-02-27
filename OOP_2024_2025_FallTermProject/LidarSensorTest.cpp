//
//#include "LidarSensor.h"
//#include <iostream>
//#include <iomanip>
//#include <cassert>
//
//using namespace std;
//
////Ka�an Ba� 152120201083 20.12.2024
//
//// LIDAR verilerini yazd�rmak i�in yard�mc� fonksiyon
//void printLidarData(const LidarSensor& lidar, int rangeCount) {
//    cout << "\nLIDAR Okumalar�:" << endl;
//    cout << setw(10) << "�ndeks"
//        << setw(15) << "Mesafe(m)"
//        << setw(15) << "A��(rad)" << endl;
//    cout << string(40, '-') << endl;
//
//    for (int i = 0; i < rangeCount; ++i) {
//        cout << setw(10) << i
//            << setw(15) << fixed << setprecision(3) << lidar[i]
//            << setw(15) << lidar.getAngle(i) << endl;
//    }
//}
//
//// Minimum ve maksimum de�erleri yazd�rmak i�in yard�mc� fonksiyon
//void printMinMax(const LidarSensor& lidar) {
//    pair<int, double> min = lidar.getMin();
//    pair<int, double> max = lidar.getMax();
//
//    cout << "\nMin/Max De�erler:" << endl;
//    cout << "Minimum: " << min.second << " metre, indeks " << min.first << endl;
//    cout << "Maximum: " << max.second << " metre, indeks " << max.first << endl;
//}
//
//// Ana test fonksiyonu
//int main() {
//    try {
//        // Robot olu�tur ve ba�lan
//        FestoRobotAPI* robot = new FestoRobotAPI();
//        robot->connect();
//
//        // LidarSensor �rne�i olu�tur
//        LidarSensor lidar(robot);
//
//        cout << "LidarSensor s�n�f� test ediliyor" << endl;
//
//        // Test 1: Temel G�ncelleme ve Okuma
//        cout << "\nTest 1: Temel G�ncelleme ve Okuma" << endl;
//        lidar.update();
//        int rangeCount = robot->getLidarRangeNumber();
//        printLidarData(lidar, rangeCount);
//
//        // Test 2: Min/Max Fonksiyonlar�
//        cout << "\nTest 2: Min/Max Fonksiyonlar�" << endl;
//        printMinMax(lidar);
//
//        // Test 3: A�� Hesaplamalar�
//        cout << "\nTest 3: A�� Hesaplamalar�" << endl;
//        cout << "�lk a��: " << lidar.getAngle(0) << " radyan" << endl;
//        cout << "Orta a��: " << lidar.getAngle(rangeCount / 2) << " radyan" << endl;
//        cout << "Son a��: " << lidar.getAngle(rangeCount - 1) << " radyan" << endl;
//
//        // Test 4: �stisna Y�netimi
//        cout << "\nTest 4: �stisna Y�netimi" << endl;
//        try {
//            double invalidRange = lidar.getRange(-1);
//            cout << "Ba�ar�s�z: Negatif indeks istisna f�rlatmad�" << endl;
//        }
//        catch (const out_of_range& e) {
//            cout << "Ba�ar�l�: Negatif indeks i�in istisna yakaland�" << endl;
//        }
//
//        try {
//            double invalidRange = lidar.getRange(rangeCount + 1);
//            cout << "Ba�ar�s�z: S�n�r d��� indeks istisna f�rlatmad�" << endl;
//        }
//        catch (const out_of_range& e) {
//            cout << "Ba�ar�l�: S�n�r d��� indeks i�in istisna yakaland�" << endl;
//        }
//
//        // Test 5: Operat�r[] Kullan�m�
//        cout << "\nTest 5: Operat�r[] Kullan�m�" << endl;
//        cout << "�lk okuma []: " << lidar[0] << endl;
//        cout << "Son okuma []: " << lidar[rangeCount - 1] << endl;
//
//        // Temizlik i�lemleri
//        robot->disconnect();
//        delete robot;
//
//        cout << "\nT�m testler ba�ar�yla tamamland�" << endl;
//
//    }
//    catch (const exception& e) {
//        cerr << "Test s�ras�nda hata olu�tu: " << e.what() << endl;
//        return 1;
//    }
//
//    return 0;
//}
//
