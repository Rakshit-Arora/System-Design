#include <iostream>
#include "configurationManager.h"
using namespace std;


int main() {
    cout << "\n###### Memento Design Pattern ######" << endl;

    // Create Originator Object
    ApplicationConfiguration appConfig("Light", 12, true, "English");

    // Create Caretaker Object
    ConfigurationManager configurationManager;

    // ===> State 1
    cout << "\n===> State 1: " <<endl;
    configurationManager.saveState(appConfig); // Default State

    // ===> State 2
    appConfig.setTheme("Dark");
    appConfig.setFontSize(14);
    cout << "\n===> State 2: " <<endl;
    configurationManager.saveState(appConfig); // Creates and stores new memento

    // ===> State 3
    appConfig.setTheme("Midnight Blue");
    appConfig.setFontSize(16);
    appConfig.setLanguage("Spanish");
    cout << "\n===> State 3: " <<endl;
    configurationManager.saveState(appConfig); // Creates and stores new memento

    // ===> Undo 1
    cout << "\n===> Undo 1: " <<endl;
    configurationManager.undo(appConfig); // Restores to previous

    // ===> Undo 2
    cout << "\n===> Undo 2: " <<endl;
    configurationManager.undo(appConfig); // Restores to previous

    // ===> Undo 3
    cout << "\n===> Undo 3: " <<endl;
    configurationManager.undo(appConfig); // Default state

    return 0;
}
