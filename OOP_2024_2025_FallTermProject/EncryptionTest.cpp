//#include "Encryption.h"
//#include <iostream>
//#include <stdexcept>
//
//// Ka�an Ba� 152120201083 20.12.2024 - 29.12.2024
//// Encryption Test dosyas�d�r
//using namespace std;
//
//// �ifreleme ve �ifre ��zme i�lemlerini test eden bir yard�mc� fonksiyon
//void testEncryptionDecryption(Encryption& encryption, int number) {
//    try {
//        // �ifreleme
//        int encryptedNumber = encryption.encrypt(number);
//        cout << "Original Number: " << number << endl;
//        cout << "Encrypted Number: " << encryptedNumber << endl;
//
//        // �ifre ��zme
//        int decryptedNumber = encryption.decrypt(encryptedNumber);
//        cout << "Decrypted Number: " << decryptedNumber << endl;
//
//        // Do�rulu�unu kontrol et
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
//    // 1. Normal bir say� test edin
//    cout << "\nTesting with 1234:" << endl;
//    testEncryptionDecryption(encryption, 1234);
//
//    // 2. Minimum de�er i�in test edin
//    cout << "\nTesting with 0 (minimum):" << endl;
//    testEncryptionDecryption(encryption, 0);
//
//    // 3. Maksimum de�er i�in test edin
//    cout << "\nTesting with 9999 (maximum):" << endl;
//    testEncryptionDecryption(encryption, 9999);
//
//    // 4. Ge�ersiz bir de�er i�in test edin (�rne�in negatif say�)
//    cout << "\nTesting with -1234 (invalid):" << endl;
//    testEncryptionDecryption(encryption, -1234);
//
//    // 5. Ge�ersiz bir de�er i�in test edin (�rne�in 5 basamakl� say�)
//    cout << "\nTesting with 12345 (invalid):" << endl;
//    testEncryptionDecryption(encryption, 12345);
//
//    return 0;
//}
