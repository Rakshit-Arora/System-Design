/// Interface should be such, that client should not implement unneccessary functions that they do not need.

// ❌ ISP Violation
#include <iostream>
using namespace std;

class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual ~Worker() {}
};

class HumanWorker : public Worker {
public:
    void work() override {
        cout << "Human working" << endl;
    }
    void eat() override {
        cout << "Human eating" << endl;
    }
};

class RobotWorker : public Worker {
public:
    void work() override {
        cout << "Robot working" << endl;
    }
    void eat() override {
        // Robot does not eat but forced to implement eat()
        cout << "Robot does not eat but forced to implement eat()" << endl;
    }
};

// ✅ ISP Compliant
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() {}
};

class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() {}
};

class HumanWorker_ISP : public Workable, public Eatable {
public:
    void work() override {
        cout << "Human working" << endl;
    }
    void eat() override {
        cout << "Human eating" << endl;
    }
};

class RobotWorker_ISP : public Workable {
public:
    void work() override {
        cout << "Robot working" << endl;
    }
};

int main() {
    cout << "=== ISP Violation Example ===" << endl;
    HumanWorker human;
    RobotWorker robot;
    human.work();
    human.eat();
    robot.work();
    robot.eat();

    cout << "\n=== ISP Compliant Example ===" << endl;
    HumanWorker_ISP human_isp;
    RobotWorker_ISP robot_isp;
    human_isp.work();
    human_isp.eat();
    robot_isp.work();
    // robot_isp does not have eat() method, no dummy implementation needed

    return 0;
}
