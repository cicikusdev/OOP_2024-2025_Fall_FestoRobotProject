#include "RobotOperator.h"
#include <iostream>
using namespace std;

int RobotOperator::encryptCode(int code) {
    return encryption.encrypt(code);
}

int RobotOperator::decryptCode(int encryptedCode) {
    return encryption.decrypt(encryptedCode);
}

bool RobotOperator::isNumeric(const std::string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool RobotOperator::checkAccessCode(int code) {
    if (code < 1000 || code > 9999) {
        throw invalid_argument("Code must be a 4-digit integer");
    }
    int decryptedCode = decryptCode(accessCode);
    accessState = (decryptedCode == code);
    return accessState;
}

void RobotOperator::print() const {
    cout << "Name: " << name << std::endl;
    cout << "Surname: " << surname << std::endl;
    cout << "Access State: " << (accessState ? "Granted" : "Denied") << std::endl;
}