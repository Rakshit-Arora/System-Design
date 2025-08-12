/// High-level modules should not depend on low-level modules. Both should depend on abstractions.
/// Abstractions should not depend on details. Details should depend on abstractions.

// Imagine a TV remote (high-level module) and a TV brand (low-level module).
// ❌ Without DIP:
// The remote is made only for Sony TVs — if you buy a Samsung, you must change the remote’s design.
// ✅ With DIP:
// The remote follows a standard interface (like HDMI or IR code). Any TV that follows the same interface can work with it — no redesign needed.


/// DIP Violation Example:

#include <iostream>
#include <string>
using namespace std;

class EmailService {
public:
    void sendEmail(const string& message) {
        cout << "Sending Email: " << message << endl;
    }
};

class UserService {
    EmailService emailService; // Direct dependency
public:
    void registerUser(const string& username) {
        cout << "Registering user: " << username << endl;
        emailService.sendEmail("Welcome " + username + "!");
    }
};

int main() {
    UserService userService;
    userService.registerUser("Alice");
}

/// DIP Compliant Example:

#include <iostream>
#include <string>
using namespace std;

class Notifier {
public:
    virtual ~Notifier() = default;
    virtual void send(const string& message) = 0;
};

class EmailService_DIP : public Notifier {
public:
    void send(const string& message) override {
        cout << "Sending Email: " << message << endl;
    }
};

class SMSService_DIP : public Notifier {
public:
    void send(const string& message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

class UserService_DIP {
    Notifier& notifier;
public:
    UserService_DIP(Notifier& n): notifier(n) {
        // Dependency injection through constructor
    }

    void registerUser(const string& username) {
        cout << "Registering user: " << username << endl;
        notifier.send("Welcome " + username + "!");
    }
};

int main() {
    EmailService_DIP email;
    SMSService_DIP sms;

    UserService_DIP userService1(email);
    UserService_DIP userService2(sms);

    userService1.registerUser("Bob");  // Sends Email
    userService2.registerUser("Eve");  // Sends SMS
}