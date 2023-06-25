#include <iostream>
using namespace std;

// Abstract interface representing a notification mechanism
class Notification {
public:
    virtual void sendNotification() = 0;
};

// Concrete implementation of email notification
class EmailNotification : public Notification {
public:
    void sendNotification() override {
        cout << "Sending email notification..." << endl;
        // Implementation specific to email notification
    }

    void sayHello() {
        cout << "Hello from EmailNotification!" << endl;
    }
};

// Concrete implementation of SMS notification
class SMSNotification : public Notification {
public:
    void sendNotification() override {
        cout << "Sending SMS notification..." << endl;
        // Implementation specific to SMS notification
    }
};

// High-level class that depends on the abstract interface (Dependency Inversion)
class NotificationService {
private:
    Notification* notification;

public:
    NotificationService(Notification* notification) {
        this->notification = notification;
    }

    void sendNotification() {
        notification->sendNotification();
        
        if (EmailNotification* emailNotification = dynamic_cast<EmailNotification*>(notification)) {
            emailNotification->sayHello(); // Call the sayHello() function
        }
    }
};

int main() {
    // Dependency injection
    EmailNotification emailNotification;
    NotificationService emailService(&emailNotification);
    emailService.sendNotification();

    SMSNotification smsNotification;
    NotificationService smsService(&smsNotification);
    smsService.sendNotification();

    return 0;
}
