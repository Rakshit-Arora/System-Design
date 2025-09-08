#pragma once
#include "logProcessor.h"
using namespace std;

class DebugLogProcessor : public LogProcessor{
public:
    DebugLogProcessor(shared_ptr<LogProcessor> nextLogger = NULL) : LogProcessor(nextLogger) {}

    void log(int logLevel, const string& msg) const override {
        if(logLevel == DEBUG) {
            cout << "DEBUG: " << msg << endl;
        }
        else {
            LogProcessor::log(logLevel, msg);
        }
    }
};