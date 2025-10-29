// Originator Class - Creates & Restores from mementos

#pragma once
#include <string>
#include <iostream>
#include "configurationMemento.h"

class ApplicationConfiguration {
private:
    std::string theme;
    int fontSize;
    bool notificationsEnabled;
    std::string language;

public:
    // Constructor
    ApplicationConfiguration(const std::string& theme, int fontSize,
                             bool notificationsEnabled, const std::string& language)
        : theme(theme),
          fontSize(fontSize),
          notificationsEnabled(notificationsEnabled),
          language(language) {}

    // Create a memento with current state
    ConfigurationMemento save() const {
        std::cout << "[+] Saving configuration state..." << std::endl;
        return ConfigurationMemento(theme, fontSize, notificationsEnabled, language);
    }

    // Restore state from memento
    void restore(ConfigurationMemento& memento) {
        theme = memento.getTheme();
        fontSize = memento.getFontSize();
        notificationsEnabled = memento.isNotificationEnabled();
        language = memento.getLanguage();
        std::cout << "[+] Restored Previous Configuration State" << std::endl;
    }

    // Setters
    void setTheme(const std::string& newTheme) {
        theme = newTheme;
    }

    void setFontSize(int newFontSize) {
        fontSize = newFontSize;
    }

    void setNotificationsEnabled(bool enabled) {
        notificationsEnabled = enabled;
    }

    void setLanguage(const std::string& newLanguage) {
        language = newLanguage;
    }

    // toString equivalent
    std::string toString() const {
        return "Configuration[Theme=" + theme +
               ", Font Size=" + std::to_string(fontSize) +
               ", Notifications=" + (notificationsEnabled ? "true" : "false") +
               ", Language=" + language + "]";
    }
};
