#include "Encryption.h"
#include <stdexcept>

using namespace std;

int Encryption::encrypt(int number) {
    if (number < 0 || number > 9999)
        throw invalid_argument("Invalid Number");

    // 1. Basamaklara ay�r
    int digits[4];
    int temp = number;
    for (int i = 3; i >= 0; i--) {
        digits[i] = temp % 10;
        temp /= 10;
    }

    // 2. Her basama�a 7 ekle ve mod 10 al
    for (int i = 0; i < 4; i++) {
        digits[i] = (digits[i] + 7) % 10;
    }

    // 3. 1. ve 3., 2. ve 4. basamaklar� de�i�tir
    temp = digits[0];
    digits[0] = digits[2];
    digits[2] = temp;

    temp = digits[1];
    digits[1] = digits[3];
    digits[3] = temp;

    // 4. Basamaklar� birle�tir
    int result = 0;
    for (int i = 0; i < 4; i++) {
        result = result * 10 + digits[i];
    }

    return result;
}

int Encryption::decrypt(int number) {
    if (number < 0 || number > 9999)
        throw invalid_argument("Invalid Number");

    // 1. Basamaklara ay�r
    int digits[4];
    int temp = number;
    for (int i = 3; i >= 0; i--) {
        digits[i] = temp % 10;
        temp /= 10;
    }

    // 2. 1. ve 3., 2. ve 4. basamaklar� de�i�tir
    temp = digits[0];
    digits[0] = digits[2];
    digits[2] = temp;

    temp = digits[1];
    digits[1] = digits[3];
    digits[3] = temp;

    // 3. Her basamak i�in ters i�lem (7 ��karman�n mod�ler aritmetikteki kar��l���)
    for (int i = 0; i < 4; i++) {
        digits[i] = (digits[i] + 3) % 10;  // +3 yapmak, -7 yapmakla ayn� sonucu verir (mod 10'da)
    }

    // 4. Basamaklar� birle�tir
    int result = 0;
    for (int i = 0; i < 4; i++) {
        result = result * 10 + digits[i];
    }

    return result;
}