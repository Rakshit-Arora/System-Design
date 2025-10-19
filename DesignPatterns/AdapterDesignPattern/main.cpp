#include <iostream>
#include "header/existingWeightMachineImpl.h"
#include "header/adapterWeightMachineImpl.h"
using namespace std;

int main() {
    cout << "Adapter Design Pattern Example" << endl;

    double weighingScaleReading = 28.0; // weight in pounds
    ExistingWeightMachine* existingWeightMachine = new ExistingWeightMachineImpl(weighingScaleReading);

    // Adapter to convert
    AdapterWeightMachine* adapter = new AdapterWeightMachineImpl(existingWeightMachine);

    // Result
    cout<<"Weight in Kilograms: " << adapter->getWeightInKg() << " kg" << endl;

    return 0;
}