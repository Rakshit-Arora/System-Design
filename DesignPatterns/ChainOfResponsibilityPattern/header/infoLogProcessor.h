#pragma once
#include "logProcessor.h"
using namespace std;

class InfoLogProcessor : public LogProcessor{
public:
    InfoLogProcessor(shared_ptr<LogProcessor> nextLogger = NULL) : LogProcessor(nextLogger) {}

    void log(int logLevel, const string& msg) const override {
        if(logLevel == INFO) {
            cout << "INFO: " << msg << endl;
        }
        else {
            LogProcessor::log(logLevel, msg);
        }
    }
};