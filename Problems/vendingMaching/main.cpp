#include "context/vendingMachine.h"
#include <iostream>
using namespace std;

int main() {
    cout<< "State Design Pattern - Vending Machine Simulation"<<endl;
    vendingMachine vm;
    vm.displayInventory();

    try {
        cout<< "-- Happy Flow 1 --"<<endl;

        vm.beginTransaction();
        vm.chooseProduct("201");
        vm.insertCoin(20);
        vm.dispenseProduct();


        cout<< "-- Happy Flow 2 --"<<endl;

        vm.beginTransaction();
        vm.chooseProduct("302");
        vm.insertCoin(100);
        vm.dispenseProduct();

        cout<< "-- Negative Flow (out of stock) --"<<endl;
        
        vm.beginTransaction();
        vm.chooseProduct("303");
        vm.insertCoin(35);
        vm.dispenseProduct();

        vm.beginTransaction();
        vm.chooseProduct("303");
        vm.insertCoin(35);
        vm.dispenseProduct();

    } catch(exception& e) {
        cout<< "Exception: " << e.what() << endl;
    }

    cout << "Final Inventory Status: " << endl;
    vm.displayInventory();
}