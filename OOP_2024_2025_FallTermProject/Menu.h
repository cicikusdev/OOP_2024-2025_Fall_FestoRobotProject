
//#ifndef MENU_H
//#define MENU_H
//#include "RobotControler.h"
//#include "SafeNavigation.h"
//#include "IRSensor.h"
//#include "LidarSensor.h"
//#include <iostream>
///*
// * @File: Menu.h
// * @Authors: Umay Ece Mantar (152120221127), Suude Kaynak (152120211110)
// * @Date: 22.12.2024
// * @Brief: Header file defining the menu classes used in the robot control application.
// */
//
//
// /*
//   * @Class: ConnectionMenu
//   * @Description: This class provides a menu for managing the connection and disconnection of the robot.
//   */
//class ConnectionMenu {
//private:
//    RobotControler* robotControl;// Pointer to RobotControler object to manage robot connection
//    const char CONNECT = '1'; // Option to connect the robot
//    const char DISCONNECT = '2';  // Option to disconnect the robot
//    const char BACK = '3';  // Option to go back to the previous menu
//
//public:
//    bool isRobotConnected = false; // Flag to track the connection status of the robot
//
//    ConnectionMenu(RobotControler* robotC) : robotControl(robotC) {} //Constructor initializes the ConnectionMenu with a given RobotControler.
//
//    void show() { //Displays the connection menu and handles user choices for connecting or disconnecting the robot.
//        char userChoice; // Kullanýcý seçeneði için deðiþken
//        while (true) {
//            std::cout << "Connection Menu" << std::endl; // Menü baþlýðý
//            std::cout << "1. Connect Robot" << std::endl; // Robot baðlama seçeneði
//            std::cout << "2. Disconnect Robot" << std::endl; // Robot baðlantýsýný kesme seçeneði
//            std::cout << "3. Back" << std::endl; // Bir önceki menüye dönme seçeneði
//            std::cout << "Choose one: "; // Kullanýcýdan giriþ al
//            std::cin >> userChoice; 
//
//            // Kullanýcý giriþine göre iþlemler
//            if (userChoice == CONNECT) { // Eðer "Connect Robot" seçildiyse
//                if (robotControl->connectRobot()) { // Robotu baðlama giriþimi
//                    std::cout << "Robot is connected..." << std::endl; // Baþarýlý baðlantý mesajý
//                    isRobotConnected = true; // Baðlantý durumu güncelleniyor
//                }
//            }
//            else if (userChoice == DISCONNECT) {
//                if (robotControl->disconnectRobot()) { // Robot baðlantýsýný kesme giriþimi 
//                    std::cout << "Robot is disconnected..." << std::endl; // Baþarýlý baðlantý kesme mesajý
//                    isRobotConnected = false; // Baðlantý durumu güncelleniyor
//                }
//            }
//            else if (userChoice == BACK) { // Eðer "Back" seçildiyse
//                break; // Döngüden çýk ve bir önceki menüye dön
//            }
//            else { // Geçersiz bir seçenek girildiyse
//                std::cout << "Undefined option. Try again" << std::endl; // Hata mesajý
//            }
//        }
//    }
//};
//
///*
// * @Class: MotionMenu
// * @Description: Robotun hareket kontrolünü saðlayan bir menü sýnýfý. Düz hareket, dönüþ ve mesafeli hareket gibi iþlemleri gerçekleþtirir.
// */
//class MotionMenu {
//private:
//    RobotControler* robotControl; // Robot hareketlerini kontrol eden sýnýfa iþaretçi
//    SafeNavigation* safeNav;     // Güvenli hareket için kullanýlan sýnýfa iþaretçi
//    const char MOVE = '1';       // Robotu hareket ettirme seçeneði
//    const char SAFE_MOVE = '2';  // Güvenli hareket seçeneði
//    const char TURN_LEFT = '3';  // Robotu sola döndürme seçeneði
//    const char TURN_RIGHT = '4'; // Robotu saða döndürme seçeneði
//    const char FORWARD = '5';    // Robotu ileri hareket ettirme seçeneði
//    const char MOVE_DISTANCE = '6'; // Belirli mesafeye hareket seçeneði
//    const char CLOSE_WALL = '7';    // Duvara yaklaþma seçeneði
//    const char QUIT = '8';      // Çýkýþ yapma seçeneði
//
//public:
//
//    /*
//  * Constructor: MotionMenu
//  * @param robotC: RobotControler iþaretçisi
//  * @param sNav: SafeNavigation iþaretçisi
//  * @brief: Robot hareket ve güvenli navigasyon iþlevlerini baþlatýr.
//  */
//    MotionMenu(RobotControler* robotC, SafeNavigation* sNav) 
//        : robotControl(robotC), safeNav(sNav) {}
//
//    void show() { //MotionMenu'yu görüntüler ve kullanýcý giriþlerini iþleyerek robot hareketlerini gerçekleþtirir.
//        char userChoice;
//        while (true) {
//            std::cout << "Motion Menu" << std::endl; // Menü baþlýðý
//            std::cout << "1. Move robot" << std::endl; // Robotu hareket ettirme seçeneði
//            std::cout << "2. Safe Move Robot" << std::endl; // Güvenli hareket seçeneði
//            std::cout << "3. Turn left" << std::endl; // Sola dönüþ seçeneði
//            std::cout << "4. Turn Right" << std::endl; // Saða dönüþ seçeneði
//            std::cout << "5. Forward" << std::endl; // Ýleri hareket seçeneði
//            std::cout << "6. Move distance" << std::endl; // Belirli mesafeye hareket
//            std::cout << "7. Close Wall" << std::endl; // Duvara yaklaþma hareketi
//            std::cout << "8. Quit" << std::endl; // Çýkýþ seçeneði
//            std::cout << "Choose one: ";
//            std::cin >> userChoice; // Kullanýcýdan seçim al
//
//            switch (userChoice) { // Kullanýcý seçimine göre iþlem
//            case '1':
//                robotControl->moveForward(); // Robotu ileri hareket ettir
//                Sleep(2000); // Hareketin 2 saniye sürmesi için duraklama
//                robotControl->stop(); // Robotu durdur
//                break;
//            case '2':
//                safeNav->moveForwardSafe(); // Güvenli bir þekilde ileri hareket ettir
//                break;
//            case '3':
//                robotControl->turnLeft(); // Robotu sola döndür
//                Sleep(2000); // 2 saniye boyunca dönüþ
//                robotControl->stop(); // Robotu durdur
//                break;
//            case '4':
//                robotControl->turnRight(); // Robotu saða döndür
//                Sleep(2000); // 2 saniye boyunca dönüþ
//                robotControl->stop(); // Robotu durdur
//                break;
//            case '5':
//                robotControl->moveForward(); // Robotu düz ileri götür
//                Sleep(2000); // 2 saniye boyunca hareket
//                robotControl->stop(); // Robotu durdur
//                break;
//            case '6':
//                // Belirli bir mesafe için hareket komutunun uygulanmasý
//                // Implementation for move distance
//                break;
//            case '7':
//                // Duvara yaklaþma iþlemi uygulanýr
//                // Implementation for close wall
//                break;
//            case '8':
//                return; // Menüden çýkýþ yap
//            default:
//                std::cout << "Undefined option. Try again" << std::endl;// Geçersiz giriþ mesajý
//            }
//            }
//        }
//};
//
//
//class SensorMenu { //Sensor menu
//private:
//    IRSensor* irSensor;        // IR sensör nesnesi için pointer
//    LidarSensor* lidarSensor;  // Lidar sensör nesnesi için pointer
//    const char IR_SENSOR = '1';      // IR sensör menü seçeneði
//    const char LIDAR_SENSOR = '2';   // Lidar sensör menü seçeneði
//    const char BACK = '3';           // Geri dönüþ menü seçeneði
//
//public:
//    // Constructor - IR ve Lidar sensörlerini initialize eder
//    SensorMenu(IRSensor* ir, LidarSensor* lidar)
//        : irSensor(ir), lidarSensor(lidar) {}
//
//    void show() {  // Menüyü gösterip kullanýcý etkileþimini yöneten metot
//        char userChoice;       // Kullanýcý seçimini tutacak deðiþken
//        while (true) {         // Sonsuz döngü - kullanýcý çýkýþ yapana kadar devam eder
//            // Menü seçeneklerini ekrana yazdýr
//            std::cout << "Sensor Menu" << std::endl;
//            std::cout << "1. IR Sensor" << std::endl;
//            std::cout << "2. Lidar Sensor" << std::endl;
//            std::cout << "3. Back" << std::endl;
//            std::cout << "Choose one: ";
//            std::cin >> userChoice;// Kullanýcý seçimini al
//
//            if (userChoice == IR_SENSOR) {     // IR sensör seçeneði
//                irSensor->update();            // Sensör verilerini güncelle
//                // IR sensör okumalarýný göster
//                for (int i = 0; i < 9; i++) {  // 9 IR sensörün her biri için döngü
//                    std::cout << "IR Sensor " << i << ": " << irSensor->getRange(i) << "m" << std::endl;
//                }
//            }
//            else if (userChoice == LIDAR_SENSOR) {  // Lidar sensör seçeneði
//                lidarSensor->update();              // Lidar verilerini güncelle
//
//                // Minimum menzili al
//                std::pair<int, double> minPair = lidarSensor->getMin();
//                int minIndex = minPair.first;       // Minimum deðerin indeksi
//                double minRange = minPair.second;   // Minimum menzil deðeri
//
//                // Maksimum menzili al
//                std::pair<int, double> maxPair = lidarSensor->getMax();
//                int maxIndex = maxPair.first;       // Maksimum deðerin indeksi
//                double maxRange = maxPair.second;   // Maksimum menzil deðeri
//
//                // Minimum ve maksimum deðerleri ekrana yazdýr
//                std::cout << "Minimum range: " << minRange << "m at index " << minIndex << std::endl;
//                std::cout << "Maximum range: " << maxRange << "m at index " << maxIndex << std::endl;
//            }
//            else if (userChoice == BACK) { // Geri dönüþ seçeneði
//                break;
//            }
//            else { // Geçersiz seçenek durumu
//                std::cout << "Undefined option. Try again" << std::endl;
//            }
//        }
//    }
//};
//
//class MainMenu {
//private:
//    RobotControler* robotControl;    // Robot kontrolcüsü için pointer
//    SafeNavigation* safeNav;         // Güvenli navigasyon için pointer
//    IRSensor* irSensor;              // IR sensör için pointer
//    LidarSensor* lidarSensor;        // Lidar sensör için pointer
//
//    ConnectionMenu connectionMenu;    // Baðlantý menüsü nesnesi
//    MotionMenu motionMenu;           // Hareket menüsü nesnesi
//    SensorMenu sensorMenu;           // Sensör menüsü nesnesi
//
//    // Menü seçenekleri için sabit deðerler
//    const char CONNECTION = '1';      // Baðlantý menüsü seçeneði
//    const char MOTION = '2';          // Hareket menüsü seçeneði
//    const char SENSOR = '3';          // Sensör menüsü seçeneði
//    const char QUIT = '4';            // Çýkýþ seçeneði
//
//public:
//    // Constructor - tüm alt sistemleri initialize eder
//    MainMenu(FestoRobotAPI* robotAPI) 
//        : robotControl(new RobotControler()),
//          irSensor(new IRSensor(robotAPI)),
//          lidarSensor(new LidarSensor(robotAPI)),
//          safeNav(new SafeNavigation(irSensor, robotControl)),
//          connectionMenu(robotControl),
//          motionMenu(robotControl, safeNav),
//          sensorMenu(irSensor, lidarSensor)
//    {}
//    // Destructor - dinamik olarak oluþturulan nesneleri temizler
//    ~MainMenu() {
//        delete robotControl;     // Robot kontrolcüsünü sil
//        delete safeNav;         // Güvenli navigasyonu sil
//        delete irSensor;        // IR sensörü sil
//        delete lidarSensor;     // Lidar sensörü sil
//    }
//
//    void show() { // Ana menüyü gösterip kullanýcý etkileþimini yöneten metot
//        char userChoice; // Kullanýcý seçimini tutacak deðiþken
//        while (true) {// Sonsuz döngü - kullanýcý çýkýþ yapana kadar devam eder
//            // Menü seçeneklerini ekrana yazdýr
//            std::cout << "Main Menu" << std::endl;
//            std::cout << "1. Connection" << std::endl;
//            std::cout << "2. Motion" << std::endl;
//            std::cout << "3. Sensor" << std::endl;
//            std::cout << "4. Quit" << std::endl;
//            std::cout << "Choose one: ";
//            std::cin >> userChoice;// Kullanýcý seçimini al
//
//            if (userChoice == CONNECTION) {         // Baðlantý menüsü seçeneði
//                connectionMenu.show();              // Baðlantý menüsünü göster
//            }
//            else if (userChoice == MOTION) {        // Hareket menüsü seçeneði
//                if (connectionMenu.isRobotConnected) {  // Robot baðlý mý kontrol et
//                    motionMenu.show();                 // Hareket menüsünü göster
//                }
//                else {                                 // Robot baðlý deðilse uyarý ver
//                    std::cout << "Robot is not connected. Please connect first." << std::endl;
//                    Sleep(2000);                      // 2 saniye bekle
//                }
//            }
//            else if (userChoice == SENSOR) {          // Sensör menüsü seçeneði
//                if (connectionMenu.isRobotConnected) {  // Robot baðlý mý kontrol et
//                    sensorMenu.show();                 // Sensör menüsünü göster
//                }
//                else {                                 // Robot baðlý deðilse uyarý ver
//                    std::cout << "Robot is not connected. Please connect first." << std::endl;
//                    Sleep(2000);                      // 2 saniye bekle
//                }
//            }
//            else if (userChoice == QUIT) { // Çýkýþ seçeneði
//                break;
//            }
//            else {// Geçersiz seçenek durumu
//                std::cout << "Undefined option. Try again" << std::endl;
//            }
//        }
//    }
//};
//#endif // !MENU_H

#ifndef MENU_H
#define MENU_H

#include "RobotControler.h"
#include "SafeNavigation.h"
#include "IRSensor.h"
#include "LidarSensor.h"
#include "FestoRobotInterface.h"
#include <iostream>
/*
 * @File: Menu.h
 * @Authors: Umay Ece Mantar (152120221127), Suude Kaynak (152120211110)
 * @Date: 22.12.2024
 * @Brief: Header file defining the menu classes used in the robot control application.
 */

 /*
  * @Class: ConnectionMenu
  * @Description: This class provides a menu for managing the connection and disconnection of the robot.
  */
class AccessMenu {
private:
    RobotControler* robotControl;
    const char OPEN_ACCESS = '1';
    const char CLOSE_ACCESS = '2';
    const char BACK = '3';

public:
    AccessMenu(RobotControler* robotC) : robotControl(robotC) {}

    void show() {
        char choice;
        while (true) {
            cout << "\nAccess Control Menu" << endl;
            cout << "1. Open Access" << endl;
            cout << "2. Close Access" << endl;
            cout << "3. Back" << endl;
            cout << "Choose one: ";
            cin >> choice;

            if (choice == OPEN_ACCESS) {
                int code;
                cout << "Enter access code: ";
                cin >> code;
                robotControl->openAccess(code);
                
            }
            else if (choice == CLOSE_ACCESS) {
                int code;
                cout << "Enter access code: ";
                cin >> code;
                robotControl->closeAccess(code);
                
            }
            else if (choice == BACK) {
                break;
            }
            else {
                cout << "Invalid option. Try again." << endl;
            }
        }
    }
};

class ConnectionMenu {
private:
    RobotControler* robotControl;// Pointer to RobotControler object to manage robot connection
   
    const char CONNECT = '1';    // Option to connect the robot
    const char DISCONNECT = '2'; // Option to disconnect the robot
    const char BACK = '3';       // Option to go back to the previous menu

public:
    bool isRobotConnected;// Flag to track the connection status of the robot
    /*
    * Constructor initializes the ConnectionMenu with a given RobotControler.
    */
    ConnectionMenu(RobotControler* robotC) : robotControl(robotC), isRobotConnected(false) {

    }
    /*
     * Displays the connection menu and handles user choices for connecting or disconnecting the robot.
     */
    void show() {
        char userChoice;// Kullanýcý seçeneði için deðiþken
        while (true) {
            cout << "\nConnection Menu" << std::endl;// Menü baþlýðý
            cout << "1. Connect Robot" << std::endl;// Robot baðlama seçeneði
            cout << "2. Disconnect Robot" << std::endl;// Robot baðlantýsýný kesme seçeneði
            cout << "3. Back" << std::endl;// Bir önceki menüye dönme seçeneði
            cout << "Choose one: ";
            cin >> userChoice;// Kullanýcýdan giriþ al
            // Kullanýcý giriþine göre iþlemler
            if (userChoice == CONNECT) {// Eðer "Connect Robot" seçildiyse
                if (robotControl->connectRobot()) {// Robotu baðlama giriþimi
                    std::cout << "Robot is connected..." << std::endl;// Baþarýlý baðlantý mesajý
                    isRobotConnected = true;// Baðlantý durumu güncelleniyor
                }
            }
            else if (userChoice == DISCONNECT) {
                if (robotControl->disconnectRobot()) {// Robot baðlantýsýný kesme giriþimi
                    std::cout << "Robot is disconnected..." << std::endl;// Baþarýlý baðlantý kesme mesajý
                    isRobotConnected = false;// Baðlantý durumu güncelleniyor
                }
            }
            else if (userChoice == BACK) {// Eðer "Back" seçildiyse
                break;// Döngüden çýk ve bir önceki menüye dön
            }
            else {// Geçersiz bir seçenek girildiyse
                std::cout << "Undefined option. Try again" << std::endl;// Hata mesajý
            }
        }
    }
};
/*
 * @Class: MotionMenu
 * @Description: Robotun hareket kontrolünü saðlayan bir menü sýnýfý. Düz hareket, dönüþ ve mesafeli hareket gibi iþlemleri gerçekleþtirir.
 */
class MotionMenu {
private:
    RobotControler* robotControl; // Robot hareketlerini kontrol eden sýnýfa iþaretçi
    SafeNavigation* safeNav;     // Güvenli hareket için kullanýlan sýnýfa iþaretçi
    const char MOVE_FORWARD = '1';
    const char MOVE_BACKWARD = '2';
    const char MOVE_LEFT = '3';
    const char MOVE_RIGHT = '4';
    const char TURN_LEFT = '5';
    const char TURN_RIGHT = '6';
    const char SAFE_MOVE = '7';
    const char STOP = '8';
    const char BACK = '9';

public:
    /*
  * Constructor: MotionMenu
  * @param robotC: RobotControler iþaretçisi
  * @param sNav: SafeNavigation iþaretçisi
  * @brief: Robot hareket ve güvenli navigasyon iþlevlerini baþlatýr.
  */
    MotionMenu(RobotControler* robotC, SafeNavigation* sNav) 
        : robotControl(robotC), safeNav(sNav) {}

    /*
    * show: MotionMenu'yu görüntüler ve kullanýcý giriþlerini iþleyerek robot hareketlerini gerçekleþtirir.
    */
    void show() {
        int userChoice;
        while (true) {
            cout << "\nMotion Menu" << endl;
            cout << "1. Move Forward" << endl;
            cout << "2. Move Backward" << endl;
            cout << "3. Move Left" << endl;
            cout << "4. Move Right" << endl;
            cout << "5. Turn Left" << endl;
            cout << "6. Turn Right" << endl;
            cout << "7. Safe Move Forward" << endl;
            cout << "8. Safe Move Backward" << endl;
            cout << "9. Stop" << endl;
            cout << "10. Back" << endl;
            cout << "Choose one: ";
            cin >> userChoice; // Kullanýcýdan seçim al

            switch (userChoice) {// Kullanýcý seçimine göre iþlem
            case 1:
                robotControl->moveForward();
                break;
            case 2:
                robotControl->moveBackward();
                break;
            case 3:
                robotControl->moveLeft();
                break;
            case 4:
                robotControl->moveRight();
                break;
            case 5:
                robotControl->turnLeft();
                break;
            case 6:
                robotControl->turnRight();
                break;
            case 7:
                safeNav->moveForwardSafe();
                break;
            case 8:
                safeNav->moveBacwardSafe();
                break;
            case 9:
                robotControl->stop();
                break;
            case 10:
                return;
                default:
                    std::cout << "Undefined option. Try again" << std::endl;// Geçersiz giriþ mesajý
            }
            robotControl->print();
        }
    }
};

class SensorMenu { //Sensor menu
private:
    RobotControler* robotControl;
    IRSensor* irSensor;
    LidarSensor* lidarSensor;
    const char UPDATE_SENSORS = '1';
    const char VIEW_IR_SENSOR = '2';
    const char VIEW_LIDAR_SENSOR = '3';
    const char BACK = '4';


public:
    // Constructor - IR ve Lidar sensörlerini initialize eder
    SensorMenu(RobotControler* robotC, IRSensor* ir, LidarSensor* lidar)
        : robotControl(robotC), irSensor(ir), lidarSensor(lidar) {
        // Add sensors to the robot controller
        robotControl->addSensor(ir);
        robotControl->addSensor(lidar);
    }

    void show() {  // Menüyü gösterip kullanýcý etkileþimini yöneten metot
        char userChoice;       // Kullanýcý seçimini tutacak deðiþken
        while (true) {         // Sonsuz döngü - kullanýcý çýkýþ yapana kadar devam eder
            // Menü seçeneklerini ekrana yazdýr
            cout << "\nSensor Menu" << endl;
            cout << "1. Update All Sensors" << endl;
            cout << "2. View IR Sensor Data" << endl;
            cout << "3. View Lidar Data" << endl;
            cout << "4. Back" << endl;
            cout << "Choose one: ";
            cin >> userChoice;// Kullanýcý seçimini al

            if (userChoice == UPDATE_SENSORS) {
                robotControl->updateSensors();
                std::cout << "Sensors updated" << std::endl;
            }
            else if (userChoice == VIEW_IR_SENSOR) {
                std::cout << "IR Sensor Type: " << irSensor->getSensorType() << std::endl;
                for (int i = 0; i < 9; i++) {
                    std::cout << "IR Sensor " << i << ": " << irSensor->getSensorValue(i) << "m" << std::endl;
                }
            }
            else if (userChoice == VIEW_LIDAR_SENSOR) {
                std::cout << "Lidar Sensor Type: " << lidarSensor->getSensorType() << std::endl;

                try {
                    int minIndex;
                    double minValue = lidarSensor->getMin(minIndex);

                    int maxIndex;
                    double maxValue = lidarSensor->getMax(maxIndex);

                    std::cout << "Minimum range: " << minValue << "m at index " << minIndex << std::endl;
                    std::cout << "Maximum range: " << maxValue << "m at index " << maxIndex << std::endl;
                }
                catch (const std::runtime_error& e) {
                    std::cout << "Error reading Lidar data: " << e.what() << std::endl;
                }
            }

            else if (userChoice == BACK) {
                break;
            }
            else {  // Geçersiz seçenek durumu
                std::cout << "Undefined option. Try again" << std::endl;
            }
        }
    }
};

class MainMenu {// Ana menü sýnýfý
private:
    RobotControler* robotControl;    // Robot kontrolcüsü için pointer
    SafeNavigation* safeNav;         // Güvenli navigasyon için pointer
    IRSensor* irSensor;              // IR sensör için pointer
    LidarSensor* lidarSensor;        // Lidar sensör için pointer
    FestoRobotInterface* robotInterface;
    RobotOperator* robotOperator = new RobotOperator("Default", "Operator", "1111");

    ConnectionMenu connectionMenu;    // Baðlantý menüsü nesnesi
    MotionMenu* motionMenu;           // Hareket menüsü nesnesi
    SensorMenu sensorMenu;           // Sensör menüsü nesnesi
    AccessMenu accessMenu;          //Access menüsü nesnesi

    // Menü seçenekleri için sabit deðerler
    const char ACCESS_CONTROL = '1';
    const char CONNECTION = '2';      // Baðlantý menüsü seçeneði
    const char MOTION = '3';          // Hareket menüsü seçeneði
    const char SENSOR = '4';          // Sensör menüsü seçeneði
    const char QUIT = '5';            // Çýkýþ seçeneði

public:
    // Constructor - tüm alt sistemleri initialize eder
    MainMenu(FestoRobotAPI* robotAPI)
        : irSensor(new IRSensor(robotAPI)),
        lidarSensor(new LidarSensor(robotAPI)),
        robotInterface(new FestoRobotInterface(robotAPI)),
        robotOperator(new RobotOperator("Default", "Operator", "1111")),
        robotControl(new RobotControler(robotInterface, robotOperator)),
        accessMenu(robotControl),
        connectionMenu(robotControl),
        
        sensorMenu(robotControl, irSensor, lidarSensor)
    {
        safeNav = new SafeNavigation(irSensor, robotControl);
        motionMenu = new MotionMenu(robotControl, safeNav);
        
    }


    // Destructor - dinamik olarak oluþturulan nesneleri temizler
    ~MainMenu() {
        delete robotControl;
        robotControl = nullptr;
        delete robotInterface;
        robotInterface = nullptr;
        delete robotOperator;
        robotOperator = nullptr;
        delete safeNav;
        safeNav = nullptr;
        delete irSensor;
        irSensor = nullptr;
        delete lidarSensor;
        lidarSensor = nullptr;
    }

    void show() { // Ana menüyü gösterip kullanýcý etkileþimini yöneten metot
        char userChoice; // Kullanýcý seçimini tutacak deðiþken
        while (true) {// Sonsuz döngü - kullanýcý çýkýþ yapana kadar devam eder
            // Menü seçeneklerini ekrana yazdýr
            cout << "\nMain Menu" << endl;
            cout << "1. Access Control" << endl;
            cout << "2. Connection" << endl;
            cout << "3. Motion" << endl;
            cout << "4. Sensor" << endl;
            cout << "5. Quit" << endl;
            cout << "Choose one: ";
            cin >> userChoice;// Kullanýcý seçimini al

            if (userChoice == ACCESS_CONTROL) {
                accessMenu.show();
            }
            else if (userChoice == CONNECTION) {
                connectionMenu.show();
            }
            else if (userChoice == MOTION) {
                if (!connectionMenu.isRobotConnected) {
                    cout << "Robot is not connected. Please connect first." << endl;
                    continue;
                }
                motionMenu->show();
            }
            else if (userChoice == SENSOR) {
                if (!connectionMenu.isRobotConnected) {
                    cout << "Robot is not connected. Please connect first." << endl;
                    continue;
                }
                sensorMenu.show();
            }
            else if (userChoice == QUIT) {
                cout << "Exiting program..." << endl;
                break;
            }
            else { // Geçersiz seçenek durumu
                cout << "Undefined option. Try again" << endl;
            }
        }
    }
};
#endif // !MENU_H 



