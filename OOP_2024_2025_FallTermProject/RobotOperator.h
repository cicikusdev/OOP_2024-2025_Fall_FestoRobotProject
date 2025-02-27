#ifndef ROBOTOPERATOR_H
#define ROBOTOPERATOR_H

#include "Encryption.h"
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

class RobotOperator {
private:
    string name;
    string surname;
    unsigned int accessCode;
    bool accessState;
    Encryption encryption;

    int encryptCode(int code);
    int decryptCode(int encryptedCode);
    bool isNumeric(const string& str);

public:
    // Constructor with name, surname, and default code
    RobotOperator(const string& name = "Default",
        const string& surname = "Operator",
        const string& defaultCode = "1111")
        : name(name)
        , surname(surname)
        , accessState(false)
    {
        if (defaultCode.length() != 4 || !isNumeric(defaultCode)) {
            throw invalid_argument("Access code must be a 4-digit integer");
        }
        this->accessCode = encryptCode(stoi(defaultCode));
    }

    // Getter methods
    const string& getName() const { return name; }
    const string& getSurname() const { return surname; }
    bool getAccessState() const { return accessState; }

    // Setter methods
    void setName(const string& newName) { name = newName; }
    void setSurname(const string& newSurname) { surname = newSurname; }

    bool checkAccessCode(int code);
    void print() const;
};

#endif // ROBOTOPERATOR_H