#pragma once
#include <string>
#include <stdexcept>
using namespace std;

// Forward declaration of vendingMachine to avoid circular dependency
class vendingMachine;

class vendingMachineState {
public:
    virtual ~vendingMachineState() = default;

    virtual void beginTransaction(vendingMachine& machine) {
        throw runtime_error("Operation not allowed in current state");
    }

    virtual void insertCoin(vendingMachine& machine, double amount) {
        throw runtime_error("Operation not allowed in current state");
    }

    virtual void chooseProduct(vendingMachine& machine, const string& productCode) {
        throw runtime_error("Operation not allowed in current state");
    }

    virtual void dispenseProduct(vendingMachine& machine) {
        throw runtime_error("Operation not allowed in current state");
    }
};