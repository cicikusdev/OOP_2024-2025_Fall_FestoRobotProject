//#include "Encryption.h"
//#include <iostream>
//#include <stdexcept>
//
//// Kaðan Baþ 152120201083 20.12.2024 - 29.12.2024
//// Encryption Test dosyasýdýr
//using namespace std;
//
//// Þifreleme ve þifre çözme iþlemlerini test eden bir yardýmcý fonksiyon
//void testEncryptionDecryption(Encryption& encryption, int number) {
//    try {
//        // Þifreleme
//        int encryptedNumber = encryption.encrypt(number);
//        cout << "Original Number: " << number << endl;
//        cout << "Encrypted Number: " << encryptedNumber << endl;
//
//        // Þifre çözme
//        int decryptedNumber = encryption.decrypt(encryptedNumber);
//        cout << "Decrypted Number: " << decryptedNumber << endl;
//
//        // Doðruluðunu kontrol et
//        if (decryptedNumber == number) {
//            cout << "Decryption is correct" << endl;
//        }
//        else {
//            cout << "Decryption failed" << endl;
//        }
//    }
//    catch (const invalid_argument& e) {
//        cerr << "Error: " << e.what() << endl;
//    }
//}
//
//int main() {
//    Encryption encryption;
//
//    cout << "=== Encryption and Decryption Test ===" << endl;
//
//    // 1. Normal bir sayý test edin
//    cout << "\nTesting with 1234:" << endl;
//    testEncryptionDecryption(encryption, 1234);
//
//    // 2. Minimum deðer için test edin
//    cout << "\nTesting with 0 (minimum):" << endl;
//    testEncryptionDecryption(encryption, 0);
//
//    // 3. Maksimum deðer için test edin
//    cout << "\nTesting with 9999 (maximum):" << endl;
//    testEncryptionDecryption(encryption, 9999);
//
//    // 4. Geçersiz bir deðer için test edin (örneðin negatif sayý)
//    cout << "\nTesting with -1234 (invalid):" << endl;
//    testEncryptionDecryption(encryption, -1234);
//
//    // 5. Geçersiz bir deðer için test edin (örneðin 5 basamaklý sayý)
//    cout << "\nTesting with 12345 (invalid):" << endl;
//    testEncryptionDecryption(encryption, 12345);
//
//    return 0;
//}
