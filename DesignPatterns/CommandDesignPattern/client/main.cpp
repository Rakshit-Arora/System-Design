#include <iostream>
#include <memory>
#include "../Receiver/airConditioner.h"
#include "../Invoker/remoteController.h"
#include "../Command/turnAcOff.h"
#include "../Command/turnAcOn.h"
#include "../Command/setTemperature.h"
using namespace std;

int main() {
    cout << "----- Command Desing Pattern Demo -----" << endl;

    auto airConditioner = make_shared<AirConditioner>();
    RemoteController remoteObj;

    remoteObj.setCommand(make_shared<TurnAcOn>(airConditioner));
    remoteObj.pressButton();

    remoteObj.setCommand(make_shared<SetTemperature>(airConditioner, 25));
    remoteObj.pressButton();

    remoteObj.setCommand(make_shared<SetTemperature>(airConditioner, 18));
    remoteObj.pressButton();

    remoteObj.setCommand(make_shared<TurnAcOff>(airConditioner));
    remoteObj.pressButton();

    remoteObj.undo(); // Undo Turn Off
    remoteObj.undo(); // Undo Set Temp: 18
    remoteObj.undo(); // Undo Set Temp: 25
    remoteObj.undo(); // Undo Turn On

    return 0;
}