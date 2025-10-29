// Care Taker - manages mementos#pragma once
#include <stack>
#include <iostream>
#include "applicationConfiguration.h"
#include "configurationMemento.h"

class ConfigurationManager {
private:
    std::stack<ConfigurationMemento> history;

public:
    // Save the current state
    void saveState(ApplicationConfiguration& appConfig) {
        ConfigurationMemento configurationMemento = appConfig.save(); // create a memento
        history.push(configurationMemento); // store it
        
        std::cout << "[+] State saved. History size: " << history.size() << std::endl;

        if (history.size() == 1)
            std::cout << "[+] Default State: " << configurationMemento.toString() << std::endl;
        else
            std::cout << "[+] Current State: " << configurationMemento.toString() << std::endl;
    }

    // Undo the last state
    void undo(ApplicationConfiguration& appConfig) {
        if (history.size() > 1) {
            history.pop(); // remove current state
            ConfigurationMemento mementoToBeRestored = history.top(); // get previous
            appConfig.restore(mementoToBeRestored);

            std::cout << "[+] Undo performed. History size: " << history.size() << std::endl;

            if (history.size() == 1)
                std::cout << "[+] Default State: " << mementoToBeRestored.toString() << std::endl;
            else
                std::cout << "[+] Current State: " << mementoToBeRestored.toString() << std::endl;
        } else if (!history.empty()) {
            std::cout << "[+] No more states to undo!" << std::endl;
            std::cout << "[+] Default State: " << history.top().toString() << std::endl;
        } else {
            std::cout << "[!] No states in history yet!" << std::endl;
        }
    }
};
