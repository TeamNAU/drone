#pragma once

#include <string>
#include <string.h>

#define STRINGIFY2(arg) #arg
#define STRINGIFY(arg) STRINGIFY2(arg)
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define streamLog_error(format, ...) Logger::getInstance().streamLog(StreamLogLevel::STREAM_LOG_ERROR, "[err]{file: %s, line: %d}  " format, __FILENAME__, __LINE__, ##__VA_ARGS__);

#define streamLog_warning(format, ...) Logger::getInstance().streamLog(StreamLogLevel::STREAM_LOG_WARNING, "[warn]{file: %s, line: %d}  " format, __FILENAME__, __LINE__, ##__VA_ARGS__);

#define streamLog_notice(format, ...) Logger::getInstance().streamLog(StreamLogLevel::STREAM_LOG_NOTICE, "[notice]{file: %s, line: %d}  " format, __FILENAME__, __LINE__, ##__VA_ARGS__);

#define streamLog_info(format, ...) Logger::getInstance().streamLog(StreamLogLevel::STREAM_LOG_INFO, "[info]{file: %s, line: %d}  " format, __FILENAME__, __LINE__, ##__VA_ARGS__);

#define streamLog_debug(format, ...) Logger::getInstance().streamLog(StreamLogLevel::STREAM_LOG_DEBUG, "[debug]{file: %s, line: %d}  " format, __FILENAME__, __LINE__, ##__VA_ARGS__);

enum class StreamLogLevel {
    STREAM_LOG_DEBUG,
    STREAM_LOG_INFO,
    STREAM_LOG_NOTICE,
    STREAM_LOG_WARNING,
    STREAM_LOG_ERROR
};

class Logger {
    public:
        Logger(const Logger& logger) = delete;
        Logger(Logger&& logger) = delete;
        Logger& operator=(const Logger& logger) = delete;
        Logger& operator=(Logger&& logger) = delete;

        static Logger& getInstance();
        static void setModuleName(std::string name);

        void streamLog(StreamLogLevel logLevel, const char * formatMessage, ...);
        ~Logger();

    private:
        Logger();
        static std::string module_name;
};