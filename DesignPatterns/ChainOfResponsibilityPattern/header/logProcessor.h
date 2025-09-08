#pragma once
#include <string>
#include <memory>
#include <iostream>
using namespace std;

class LogProcessor {
protected:
    shared_ptr<LogProcessor> nextLoggerProcessor;

public:
    static const int INFO = 1;
    static const int DEBUG = 2;
    static const int ERROR = 3;

    LogProcessor(shared_ptr<LogProcessor> nextLogger = NULL) : nextLoggerProcessor(nextLogger) {}

    virtual ~LogProcessor() = default;

    virtual void log(int logLevel, const string& msg) const {
        if(nextLoggerProcessor) {
            nextLoggerProcessor -> log(logLevel, msg);
        }
    }
};