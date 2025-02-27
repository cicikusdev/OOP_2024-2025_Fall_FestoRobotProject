#include "Menu.h"
#include "Menu.h"
using namespace std;
//Umay Ece Mantar 152120221127 - Suude Kaynak 152120211110 22.12.2024 
//Main menu için cpp dosyasýdýr
int main() {
    try {
        // Create FestoRobotAPI instance
        FestoRobotAPI robotAPI;

        // Create MainMenu instance which will handle all the submenus and components
        MainMenu mainMenu(&robotAPI);

        // Show the main menu and handle all user interactions
        mainMenu.show();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}




