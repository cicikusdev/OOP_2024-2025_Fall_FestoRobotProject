//
//
//#include "RobotOperator.h"
//#include <iostream>
//
//using namespace std;
////Ka�an Ba� 152120201083 20.12.2024
////RobotOperator Test dosyas�d�r
//
//int main() {
//    try {
//        Encryption* enc;
//        // RobotOperator nesnesini olu�tur
//        RobotOperator operator1("John", "Doe", 1234, enc );
//
//        // Eri�im kodunu kontrol et
//        cout << "Checking access code 1234: "
//            << (operator1.checkAccessCode(1234) ? "Access Granted" : "Access Denied")
//            << endl;
//
//        // Yanl�� bir kodla eri�imi kontrol et
//        cout << "Checking access code 5678: "
//            << (operator1.checkAccessCode(5678) ? "Access Granted" : "Access Denied")
//            << endl;
//
//        // Operat�r bilgilerini yazd�r
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
