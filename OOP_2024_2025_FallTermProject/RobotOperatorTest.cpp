//
//
//#include "RobotOperator.h"
//#include <iostream>
//
//using namespace std;
////Kaðan Baþ 152120201083 20.12.2024
////RobotOperator Test dosyasýdýr
//
//int main() {
//    try {
//        Encryption* enc;
//        // RobotOperator nesnesini oluþtur
//        RobotOperator operator1("John", "Doe", 1234, enc );
//
//        // Eriþim kodunu kontrol et
//        cout << "Checking access code 1234: "
//            << (operator1.checkAccessCode(1234) ? "Access Granted" : "Access Denied")
//            << endl;
//
//        // Yanlýþ bir kodla eriþimi kontrol et
//        cout << "Checking access code 5678: "
//            << (operator1.checkAccessCode(5678) ? "Access Granted" : "Access Denied")
//            << endl;
//
//        // Operatör bilgilerini yazdýr
//        operator1.print();
//
//    }
//    catch (const invalid_argument& e) {
//        cerr << "Error: " << e.what() << endl;
//    }
//
//    return 0;
//}
//
