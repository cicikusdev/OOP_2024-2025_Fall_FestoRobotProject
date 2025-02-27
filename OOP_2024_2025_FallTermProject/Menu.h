
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
//        char userChoice; // Kullan�c� se�ene�i i�in de�i�ken
//        while (true) {
//            std::cout << "Connection Menu" << std::endl; // Men� ba�l���
//            std::cout << "1. Connect Robot" << std::endl; // Robot ba�lama se�ene�i
//            std::cout << "2. Disconnect Robot" << std::endl; // Robot ba�lant�s�n� kesme se�ene�i
//            std::cout << "3. Back" << std::endl; // Bir �nceki men�ye d�nme se�ene�i
//            std::cout << "Choose one: "; // Kullan�c�dan giri� al
//            std::cin >> userChoice; 
//
//            // Kullan�c� giri�ine g�re i�lemler
//            if (userChoice == CONNECT) { // E�er "Connect Robot" se�ildiyse
//                if (robotControl->connectRobot()) { // Robotu ba�lama giri�imi
//                    std::cout << "Robot is connected..." << std::endl; // Ba�ar�l� ba�lant� mesaj�
//                    isRobotConnected = true; // Ba�lant� durumu g�ncelleniyor
//                }
//            }
//            else if (userChoice == DISCONNECT) {
//                if (robotControl->disconnectRobot()) { // Robot ba�lant�s�n� kesme giri�imi 
//                    std::cout << "Robot is disconnected..." << std::endl; // Ba�ar�l� ba�lant� kesme mesaj�
//                    isRobotConnected = false; // Ba�lant� durumu g�ncelleniyor
//                }
//            }
//            else if (userChoice == BACK) { // E�er "Back" se�ildiyse
//                break; // D�ng�den ��k ve bir �nceki men�ye d�n
//            }
//            else { // Ge�ersiz bir se�enek girildiyse
//                std::cout << "Undefined option. Try again" << std::endl; // Hata mesaj�
//            }
//        }
//    }
//};
//
///*
// * @Class: MotionMenu
// * @Description: Robotun hareket kontrol�n� sa�layan bir men� s�n�f�. D�z hareket, d�n�� ve mesafeli hareket gibi i�lemleri ger�ekle�tirir.
// */
//class MotionMenu {
//private:
//    RobotControler* robotControl; // Robot hareketlerini kontrol eden s�n�fa i�aret�i
//    SafeNavigation* safeNav;     // G�venli hareket i�in kullan�lan s�n�fa i�aret�i
//    const char MOVE = '1';       // Robotu hareket ettirme se�ene�i
//    const char SAFE_MOVE = '2';  // G�venli hareket se�ene�i
//    const char TURN_LEFT = '3';  // Robotu sola d�nd�rme se�ene�i
//    const char TURN_RIGHT = '4'; // Robotu sa�a d�nd�rme se�ene�i
//    const char FORWARD = '5';    // Robotu ileri hareket ettirme se�ene�i
//    const char MOVE_DISTANCE = '6'; // Belirli mesafeye hareket se�ene�i
//    const char CLOSE_WALL = '7';    // Duvara yakla�ma se�ene�i
//    const char QUIT = '8';      // ��k�� yapma se�ene�i
//
//public:
//
//    /*
//  * Constructor: MotionMenu
//  * @param robotC: RobotControler i�aret�isi
//  * @param sNav: SafeNavigation i�aret�isi
//  * @brief: Robot hareket ve g�venli navigasyon i�levlerini ba�lat�r.
//  */
//    MotionMenu(RobotControler* robotC, SafeNavigation* sNav) 
//        : robotControl(robotC), safeNav(sNav) {}
//
//    void show() { //MotionMenu'yu g�r�nt�ler ve kullan�c� giri�lerini i�leyerek robot hareketlerini ger�ekle�tirir.
//        char userChoice;
//        while (true) {
//            std::cout << "Motion Menu" << std::endl; // Men� ba�l���
//            std::cout << "1. Move robot" << std::endl; // Robotu hareket ettirme se�ene�i
//            std::cout << "2. Safe Move Robot" << std::endl; // G�venli hareket se�ene�i
//            std::cout << "3. Turn left" << std::endl; // Sola d�n�� se�ene�i
//            std::cout << "4. Turn Right" << std::endl; // Sa�a d�n�� se�ene�i
//            std::cout << "5. Forward" << std::endl; // �leri hareket se�ene�i
//            std::cout << "6. Move distance" << std::endl; // Belirli mesafeye hareket
//            std::cout << "7. Close Wall" << std::endl; // Duvara yakla�ma hareketi
//            std::cout << "8. Quit" << std::endl; // ��k�� se�ene�i
//            std::cout << "Choose one: ";
//            std::cin >> userChoice; // Kullan�c�dan se�im al
//
//            switch (userChoice) { // Kullan�c� se�imine g�re i�lem
//            case '1':
//                robotControl->moveForward(); // Robotu ileri hareket ettir
//                Sleep(2000); // Hareketin 2 saniye s�rmesi i�in duraklama
//                robotControl->stop(); // Robotu durdur
//                break;
//            case '2':
//                safeNav->moveForwardSafe(); // G�venli bir �ekilde ileri hareket ettir
//                break;
//            case '3':
//                robotControl->turnLeft(); // Robotu sola d�nd�r
//                Sleep(2000); // 2 saniye boyunca d�n��
//                robotControl->stop(); // Robotu durdur
//                break;
//            case '4':
//                robotControl->turnRight(); // Robotu sa�a d�nd�r
//                Sleep(2000); // 2 saniye boyunca d�n��
//                robotControl->stop(); // Robotu durdur
//                break;
//            case '5':
//                robotControl->moveForward(); // Robotu d�z ileri g�t�r
//                Sleep(2000); // 2 saniye boyunca hareket
//                robotControl->stop(); // Robotu durdur
//                break;
//            case '6':
//                // Belirli bir mesafe i�in hareket komutunun uygulanmas�
//                // Implementation for move distance
//                break;
//            case '7':
//                // Duvara yakla�ma i�lemi uygulan�r
//                // Implementation for close wall
//                break;
//            case '8':
//                return; // Men�den ��k�� yap
//            default:
//                std::cout << "Undefined option. Try again" << std::endl;// Ge�ersiz giri� mesaj�
//            }
//            }
//        }
//};
//
//
//class SensorMenu { //Sensor menu
//private:
//    IRSensor* irSensor;        // IR sens�r nesnesi i�in pointer
//    LidarSensor* lidarSensor;  // Lidar sens�r nesnesi i�in pointer
//    const char IR_SENSOR = '1';      // IR sens�r men� se�ene�i
//    const char LIDAR_SENSOR = '2';   // Lidar sens�r men� se�ene�i
//    const char BACK = '3';           // Geri d�n�� men� se�ene�i
//
//public:
//    // Constructor - IR ve Lidar sens�rlerini initialize eder
//    SensorMenu(IRSensor* ir, LidarSensor* lidar)
//        : irSensor(ir), lidarSensor(lidar) {}
//
//    void show() {  // Men�y� g�sterip kullan�c� etkile�imini y�neten metot
//        char userChoice;       // Kullan�c� se�imini tutacak de�i�ken
//        while (true) {         // Sonsuz d�ng� - kullan�c� ��k�� yapana kadar devam eder
//            // Men� se�eneklerini ekrana yazd�r
//            std::cout << "Sensor Menu" << std::endl;
//            std::cout << "1. IR Sensor" << std::endl;
//            std::cout << "2. Lidar Sensor" << std::endl;
//            std::cout << "3. Back" << std::endl;
//            std::cout << "Choose one: ";
//            std::cin >> userChoice;// Kullan�c� se�imini al
//
//            if (userChoice == IR_SENSOR) {     // IR sens�r se�ene�i
//                irSensor->update();            // Sens�r verilerini g�ncelle
//                // IR sens�r okumalar�n� g�ster
//                for (int i = 0; i < 9; i++) {  // 9 IR sens�r�n her biri i�in d�ng�
//                    std::cout << "IR Sensor " << i << ": " << irSensor->getRange(i) << "m" << std::endl;
//                }
//            }
//            else if (userChoice == LIDAR_SENSOR) {  // Lidar sens�r se�ene�i
//                lidarSensor->update();              // Lidar verilerini g�ncelle
//
//                // Minimum menzili al
//                std::pair<int, double> minPair = lidarSensor->getMin();
//                int minIndex = minPair.first;       // Minimum de�erin indeksi
//                double minRange = minPair.second;   // Minimum menzil de�eri
//
//                // Maksimum menzili al
//                std::pair<int, double> maxPair = lidarSensor->getMax();
//                int maxIndex = maxPair.first;       // Maksimum de�erin indeksi
//                double maxRange = maxPair.second;   // Maksimum menzil de�eri
//
//                // Minimum ve maksimum de�erleri ekrana yazd�r
//                std::cout << "Minimum range: " << minRange << "m at index " << minIndex << std::endl;
//                std::cout << "Maximum range: " << maxRange << "m at index " << maxIndex << std::endl;
//            }
//            else if (userChoice == BACK) { // Geri d�n�� se�ene�i
//                break;
//            }
//            else { // Ge�ersiz se�enek durumu
//                std::cout << "Undefined option. Try again" << std::endl;
//            }
//        }
//    }
//};
//
//class MainMenu {
//private:
//    RobotControler* robotControl;    // Robot kontrolc�s� i�in pointer
//    SafeNavigation* safeNav;         // G�venli navigasyon i�in pointer
//    IRSensor* irSensor;              // IR sens�r i�in pointer
//    LidarSensor* lidarSensor;        // Lidar sens�r i�in pointer
//
//    ConnectionMenu connectionMenu;    // Ba�lant� men�s� nesnesi
//    MotionMenu motionMenu;           // Hareket men�s� nesnesi
//    SensorMenu sensorMenu;           // Sens�r men�s� nesnesi
//
//    // Men� se�enekleri i�in sabit de�erler
//    const char CONNECTION = '1';      // Ba�lant� men�s� se�ene�i
//    const char MOTION = '2';          // Hareket men�s� se�ene�i
//    const char SENSOR = '3';          // Sens�r men�s� se�ene�i
//    const char QUIT = '4';            // ��k�� se�ene�i
//
//public:
//    // Constructor - t�m alt sistemleri initialize eder
//    MainMenu(FestoRobotAPI* robotAPI) 
//        : robotControl(new RobotControler()),
//          irSensor(new IRSensor(robotAPI)),
//          lidarSensor(new LidarSensor(robotAPI)),
//          safeNav(new SafeNavigation(irSensor, robotControl)),
//          connectionMenu(robotControl),
//          motionMenu(robotControl, safeNav),
//          sensorMenu(irSensor, lidarSensor)
//    {}
//    // Destructor - dinamik olarak olu�turulan nesneleri temizler
//    ~MainMenu() {
//        delete robotControl;     // Robot kontrolc�s�n� sil
//        delete safeNav;         // G�venli navigasyonu sil
//        delete irSensor;        // IR sens�r� sil
//        delete lidarSensor;     // Lidar sens�r� sil
//    }
//
//    void show() { // Ana men�y� g�sterip kullan�c� etkile�imini y�neten metot
//        char userChoice; // Kullan�c� se�imini tutacak de�i�ken
//        while (true) {// Sonsuz d�ng� - kullan�c� ��k�� yapana kadar devam eder
//            // Men� se�eneklerini ekrana yazd�r
//            std::cout << "Main Menu" << std::endl;
//            std::cout << "1. Connection" << std::endl;
//            std::cout << "2. Motion" << std::endl;
//            std::cout << "3. Sensor" << std::endl;
//            std::cout << "4. Quit" << std::endl;
//            std::cout << "Choose one: ";
//            std::cin >> userChoice;// Kullan�c� se�imini al
//
//            if (userChoice == CONNECTION) {         // Ba�lant� men�s� se�ene�i
//                connectionMenu.show();              // Ba�lant� men�s�n� g�ster
//            }
//            else if (userChoice == MOTION) {        // Hareket men�s� se�ene�i
//                if (connectionMenu.isRobotConnected) {  // Robot ba�l� m� kontrol et
//                    motionMenu.show();                 // Hareket men�s�n� g�ster
//                }
//                else {                                 // Robot ba�l� de�ilse uyar� ver
//                    std::cout << "Robot is not connected. Please connect first." << std::endl;
//                    Sleep(2000);                      // 2 saniye bekle
//                }
//            }
//            else if (userChoice == SENSOR) {          // Sens�r men�s� se�ene�i
//                if (connectionMenu.isRobotConnected) {  // Robot ba�l� m� kontrol et
//                    sensorMenu.show();                 // Sens�r men�s�n� g�ster
//                }
//                else {                                 // Robot ba�l� de�ilse uyar� ver
//                    std::cout << "Robot is not connected. Please connect first." << std::endl;
//                    Sleep(2000);                      // 2 saniye bekle
//                }
//            }
//            else if (userChoice == QUIT) { // ��k�� se�ene�i
//                break;
//            }
//            else {// Ge�ersiz se�enek durumu
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
        char userChoice;// Kullan�c� se�ene�i i�in de�i�ken
        while (true) {
            cout << "\nConnection Menu" << std::endl;// Men� ba�l���
            cout << "1. Connect Robot" << std::endl;// Robot ba�lama se�ene�i
            cout << "2. Disconnect Robot" << std::endl;// Robot ba�lant�s�n� kesme se�ene�i
            cout << "3. Back" << std::endl;// Bir �nceki men�ye d�nme se�ene�i
            cout << "Choose one: ";
            cin >> userChoice;// Kullan�c�dan giri� al
            // Kullan�c� giri�ine g�re i�lemler
            if (userChoice == CONNECT) {// E�er "Connect Robot" se�ildiyse
                if (robotControl->connectRobot()) {// Robotu ba�lama giri�imi
                    std::cout << "Robot is connected..." << std::endl;// Ba�ar�l� ba�lant� mesaj�
                    isRobotConnected = true;// Ba�lant� durumu g�ncelleniyor
                }
            }
            else if (userChoice == DISCONNECT) {
                if (robotControl->disconnectRobot()) {// Robot ba�lant�s�n� kesme giri�imi
                    std::cout << "Robot is disconnected..." << std::endl;// Ba�ar�l� ba�lant� kesme mesaj�
                    isRobotConnected = false;// Ba�lant� durumu g�ncelleniyor
                }
            }
            else if (userChoice == BACK) {// E�er "Back" se�ildiyse
                break;// D�ng�den ��k ve bir �nceki men�ye d�n
            }
            else {// Ge�ersiz bir se�enek girildiyse
                std::cout << "Undefined option. Try again" << std::endl;// Hata mesaj�
            }
        }
    }
};
/*
 * @Class: MotionMenu
 * @Description: Robotun hareket kontrol�n� sa�layan bir men� s�n�f�. D�z hareket, d�n�� ve mesafeli hareket gibi i�lemleri ger�ekle�tirir.
 */
class MotionMenu {
private:
    RobotControler* robotControl; // Robot hareketlerini kontrol eden s�n�fa i�aret�i
    SafeNavigation* safeNav;     // G�venli hareket i�in kullan�lan s�n�fa i�aret�i
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
  * @param robotC: RobotControler i�aret�isi
  * @param sNav: SafeNavigation i�aret�isi
  * @brief: Robot hareket ve g�venli navigasyon i�levlerini ba�lat�r.
  */
    MotionMenu(RobotControler* robotC, SafeNavigation* sNav) 
        : robotControl(robotC), safeNav(sNav) {}

    /*
    * show: MotionMenu'yu g�r�nt�ler ve kullan�c� giri�lerini i�leyerek robot hareketlerini ger�ekle�tirir.
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
            cin >> userChoice; // Kullan�c�dan se�im al

            switch (userChoice) {// Kullan�c� se�imine g�re i�lem
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
                    std::cout << "Undefined option. Try again" << std::endl;// Ge�ersiz giri� mesaj�
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
    // Constructor - IR ve Lidar sens�rlerini initialize eder
    SensorMenu(RobotControler* robotC, IRSensor* ir, LidarSensor* lidar)
        : robotControl(robotC), irSensor(ir), lidarSensor(lidar) {
        // Add sensors to the robot controller
        robotControl->addSensor(ir);
        robotControl->addSensor(lidar);
    }

    void show() {  // Men�y� g�sterip kullan�c� etkile�imini y�neten metot
        char userChoice;       // Kullan�c� se�imini tutacak de�i�ken
        while (true) {         // Sonsuz d�ng� - kullan�c� ��k�� yapana kadar devam eder
            // Men� se�eneklerini ekrana yazd�r
            cout << "\nSensor Menu" << endl;
            cout << "1. Update All Sensors" << endl;
            cout << "2. View IR Sensor Data" << endl;
            cout << "3. View Lidar Data" << endl;
            cout << "4. Back" << endl;
            cout << "Choose one: ";
            cin >> userChoice;// Kullan�c� se�imini al

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
            else {  // Ge�ersiz se�enek durumu
                std::cout << "Undefined option. Try again" << std::endl;
            }
        }
    }
};

class MainMenu {// Ana men� s�n�f�
private:
    RobotControler* robotControl;    // Robot kontrolc�s� i�in pointer
    SafeNavigation* safeNav;         // G�venli navigasyon i�in pointer
    IRSensor* irSensor;              // IR sens�r i�in pointer
    LidarSensor* lidarSensor;        // Lidar sens�r i�in pointer
    FestoRobotInterface* robotInterface;
    RobotOperator* robotOperator = new RobotOperator("Default", "Operator", "1111");

    ConnectionMenu connectionMenu;    // Ba�lant� men�s� nesnesi
    MotionMenu* motionMenu;           // Hareket men�s� nesnesi
    SensorMenu sensorMenu;           // Sens�r men�s� nesnesi
    AccessMenu accessMenu;          //Access men�s� nesnesi

    // Men� se�enekleri i�in sabit de�erler
    const char ACCESS_CONTROL = '1';
    const char CONNECTION = '2';      // Ba�lant� men�s� se�ene�i
    const char MOTION = '3';          // Hareket men�s� se�ene�i
    const char SENSOR = '4';          // Sens�r men�s� se�ene�i
    const char QUIT = '5';            // ��k�� se�ene�i

public:
    // Constructor - t�m alt sistemleri initialize eder
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


    // Destructor - dinamik olarak olu�turulan nesneleri temizler
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

    void show() { // Ana men�y� g�sterip kullan�c� etkile�imini y�neten metot
        char userChoice; // Kullan�c� se�imini tutacak de�i�ken
        while (true) {// Sonsuz d�ng� - kullan�c� ��k�� yapana kadar devam eder
            // Men� se�eneklerini ekrana yazd�r
            cout << "\nMain Menu" << endl;
            cout << "1. Access Control" << endl;
            cout << "2. Connection" << endl;
            cout << "3. Motion" << endl;
            cout << "4. Sensor" << endl;
            cout << "5. Quit" << endl;
            cout << "Choose one: ";
            cin >> userChoice;// Kullan�c� se�imini al

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
            else { // Ge�ersiz se�enek durumu
                cout << "Undefined option. Try again" << endl;
            }
        }
    }
};
#endif // !MENU_H 



