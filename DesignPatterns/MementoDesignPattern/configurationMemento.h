// Memento Class - Stores the state
#pragma once
#include <string>
using namespace std;

class ConfigurationMemento {
private:
    string theme;
    int fontSize;
    bool notificationEnabled;
    string langugae;

public:
    ConfigurationMemento(string theme, int fontSize, bool notificationEnabled, string language) :
        theme(theme), fontSize(fontSize), notificationEnabled(notificationEnabled), langugae(language) {}

    string getTheme() {
        return theme;
    }

    int getFontSize() {
        return fontSize;
    }

    bool isNotificationEnabled() {
        return notificationEnabled;
    }

    string getLanguage() {
        return langugae;
    }

    string toString() const {
        return "ConfigurationMemento[Theme=" + theme +
           ", Font Size=" + std::to_string(fontSize) +
           ", Notifications=" + (notificationEnabled ? "true" : "false") +
           ", Language=" + langugae + "]";
    }
};