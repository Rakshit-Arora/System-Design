#pragma once
#include <stack>
#include <memory>
#include "../Command/iCommand.h"
using namespace std;

class RemoteController {
private:
    shared_ptr<ICommand> command;
    stack<shared_ptr<ICommand>> commandHistory;

public:
    void setCommand(shared_ptr<ICommand> cmd) {
        command = cmd;
    }

    void pressButton() {
        command -> execute();
        commandHistory.push(command);
    }

    void undo() {
        if(!commandHistory.empty()) {
            shared_ptr<ICommand> prevCommand = commandHistory.top();
            commandHistory.pop();
            prevCommand -> undo();
        }
    }
};