/// If class B is a subclass of class A, then we should be able to replace A with B without breaking the behaviour of the program.
/// Subclass should extend the capability of Parent class not narrow it down.
/// This is the Liskov Substitution Principle (LSP) in action.

///LSP Violation Example:

#include <iostream>
using namespace std;

class Bird{
    public: 
    virtual void fly() {
        cout << "Bird is flying." << endl;
    }
    virtual ~Bird() = default; // Virtual destructor for proper cleanup
};

class Sparrow : public Bird {
    public:
    void fly() override {
        cout << "Sparrow is flying." << endl;
    }
};

class Penguin : public Bird {
    public:
    void fly() override {
        cout << "Penguin cannot fly." << endl; // This violates LSP
    }
};

void makeBirdFly(Bird* bird) {
    bird -> fly(); // This will cause issues if a penguin is passed
}


///LSP Compliant Example:

class Bird_LSP {
    public:
    virtual void eat() {
        cout << "Bird is eating." << endl;
    }
    virtual ~Bird_LSP() = default; // Virtual destructor for proper cleanup
};

class FlyingBird : public Bird_LSP {
    public:
    virtual void fly() {
        cout << "Flying bird is flying." << endl;
    }
};

class Sparrow_LSP : public FlyingBird {
    public:
    void fly() override {
        cout << "Sparrow is flying." << endl;
    }
};

class Penguin_LSP : public Bird_LSP {
    public:
    void eat() override {
        cout << "Penguin is eating." << endl;
    }
};

void makeFlyingBirdFly(FlyingBird* bird) {
    bird -> fly(); // This will work correctly for all flying birds
}

/// Calling both the examples

int main() {
    cout<< "LSP Violation Example:" << endl;
    Bird* bird1 = new Sparrow();
    Bird* bird2 = new Penguin();

    cout<<"Calling makeBirdFly with Sparrow:" << endl;
    makeBirdFly(bird1); // Works fine
    cout<<"Calling makeBirdFly with Penguin:" << endl;
    makeBirdFly(bird2); // This will cause issues

    delete bird1;
    delete bird2;

    cout<< "\nLSP Compliant Example:" << endl;

    FlyingBird* flyingBird = new Sparrow_LSP();
    cout<<"Calling makeFlyingBirdFly with Sparrow_LSP:" << endl;
    makeFlyingBirdFly(flyingBird); // Works fine
    
    Bird_LSP* penguin = new Penguin_LSP();
    cout<<"Calling makeFlyingBirdFly with Penguin_LSP:" << endl;
    penguin->eat(); // Works fine, penguin does not fly 

    delete flyingBird;
    delete penguin;

    return 0;
}