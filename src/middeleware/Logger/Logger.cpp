#include "Logger.h"
#include <syslog.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

static int convertStreamLeveltoLevelLog(StreamLogLevel level);

    Logger::Logger() {
        openlog(module_name.c_str(), LOG_PID, LOG_USER);
    }

    Logger::~Logger() {
        closelog();
    }

    Logger& Logger::getInstance() {
        static Logger logger;
        return logger;
    }

    std::string Logger::module_name = "";

    void Logger::setModuleName(std::string name) {
        if(module_name.empty())
            module_name = name;
    }

    void Logger::streamLog(StreamLogLevel logLevel, const char * formatMessage, ...) {
        va_list ap;

        va_start(ap, formatMessage);
        vsyslog(convertStreamLeveltoLevelLog(logLevel), formatMessage, ap);
        va_end(ap);
    }

static int convertStreamLeveltoLevelLog(StreamLogLevel level) {

    switch (level) {
        case StreamLogLevel::STREAM_LOG_DEBUG:
            return LOG_DEBUG;

        case StreamLogLevel::STREAM_LOG_INFO:
            return LOG_INFO;

        case StreamLogLevel::STREAM_LOG_NOTICE:
            return LOG_NOTICE;

        case StreamLogLevel::STREAM_LOG_WARNING:
            return LOG_WARNING;

        case StreamLogLevel::STREAM_LOG_ERROR:
            return LOG_ERR;

        default:
            return LOG_ALERT;
    }
    return LOG_ALERT;
}