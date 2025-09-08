#include "header/debugLogProcessor.h"
#include "header/errorLogProcessor.h"
#include "header/infoLogProcessor.h"

int main() {
    auto errorLogger = make_shared<ErrorLogProcessor>(nullptr);
    auto debugLogger = make_shared<DebugLogProcessor>(errorLogger);
    auto infoLogger = make_shared<InfoLogProcessor>(debugLogger);

    infoLogger->log(LogProcessor::ERROR, "Exception happens");
    infoLogger->log(LogProcessor::DEBUG, "Need to debug this");
    infoLogger->log(LogProcessor::INFO,  "Just for info");

    return 0;
}