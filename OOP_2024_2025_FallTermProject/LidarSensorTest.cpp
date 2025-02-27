//
//#include "LidarSensor.h"
//#include <iostream>
//#include <iomanip>
//#include <cassert>
//
//using namespace std;
//
////Kaðan Baþ 152120201083 20.12.2024
//
//// LIDAR verilerini yazdýrmak için yardýmcý fonksiyon
//void printLidarData(const LidarSensor& lidar, int rangeCount) {
//    cout << "\nLIDAR Okumalarý:" << endl;
//    cout << setw(10) << "Ýndeks"
//        << setw(15) << "Mesafe(m)"
//        << setw(15) << "Açý(rad)" << endl;
//    cout << string(40, '-') << endl;
//
//    for (int i = 0; i < rangeCount; ++i) {
//        cout << setw(10) << i
//            << setw(15) << fixed << setprecision(3) << lidar[i]
//            << setw(15) << lidar.getAngle(i) << endl;
//    }
//}
//
//// Minimum ve maksimum deðerleri yazdýrmak için yardýmcý fonksiyon
//void printMinMax(const LidarSensor& lidar) {
//    pair<int, double> min = lidar.getMin();
//    pair<int, double> max = lidar.getMax();
//
//    cout << "\nMin/Max Deðerler:" << endl;
//    cout << "Minimum: " << min.second << " metre, indeks " << min.first << endl;
//    cout << "Maximum: " << max.second << " metre, indeks " << max.first << endl;
//}
//
//// Ana test fonksiyonu
//int main() {
//    try {
//        // Robot oluþtur ve baðlan
//        FestoRobotAPI* robot = new FestoRobotAPI();
//        robot->connect();
//
//        // LidarSensor örneði oluþtur
//        LidarSensor lidar(robot);
//
//        cout << "LidarSensor sýnýfý test ediliyor" << endl;
//
//        // Test 1: Temel Güncelleme ve Okuma
//        cout << "\nTest 1: Temel Güncelleme ve Okuma" << endl;
//        lidar.update();
//        int rangeCount = robot->getLidarRangeNumber();
//        printLidarData(lidar, rangeCount);
//
//        // Test 2: Min/Max Fonksiyonlarý
//        cout << "\nTest 2: Min/Max Fonksiyonlarý" << endl;
//        printMinMax(lidar);
//
//        // Test 3: Açý Hesaplamalarý
//        cout << "\nTest 3: Açý Hesaplamalarý" << endl;
//        cout << "Ýlk açý: " << lidar.getAngle(0) << " radyan" << endl;
//        cout << "Orta açý: " << lidar.getAngle(rangeCount / 2) << " radyan" << endl;
//        cout << "Son açý: " << lidar.getAngle(rangeCount - 1) << " radyan" << endl;
//
//        // Test 4: Ýstisna Yönetimi
//        cout << "\nTest 4: Ýstisna Yönetimi" << endl;
//        try {
//            double invalidRange = lidar.getRange(-1);
//            cout << "Baþarýsýz: Negatif indeks istisna fýrlatmadý" << endl;
//        }
//        catch (const out_of_range& e) {
//            cout << "Baþarýlý: Negatif indeks için istisna yakalandý" << endl;
//        }
//
//        try {
//            double invalidRange = lidar.getRange(rangeCount + 1);
//            cout << "Baþarýsýz: Sýnýr dýþý indeks istisna fýrlatmadý" << endl;
//        }
//        catch (const out_of_range& e) {
//            cout << "Baþarýlý: Sýnýr dýþý indeks için istisna yakalandý" << endl;
//        }
//
//        // Test 5: Operatör[] Kullanýmý
//        cout << "\nTest 5: Operatör[] Kullanýmý" << endl;
//        cout << "Ýlk okuma []: " << lidar[0] << endl;
//        cout << "Son okuma []: " << lidar[rangeCount - 1] << endl;
//
//        // Temizlik iþlemleri
//        robot->disconnect();
//        delete robot;
//
//        cout << "\nTüm testler baþarýyla tamamlandý" << endl;
//
//    }
//    catch (const exception& e) {
//        cerr << "Test sýrasýnda hata oluþtu: " << e.what() << endl;
//        return 1;
//    }
//
//    return 0;
//}
//
