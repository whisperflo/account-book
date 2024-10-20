#ifndef LOGGER_H
#define LOGGER_H

#include "log4cpp/Category.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/PatternLayout.hh"
#include "log4cpp/Priority.hh"
#include <string>

class Logger {
public:
    Logger(const std::string &logDir);
    ~Logger();
    void info(const std::string &message);
    void warn(const std::string &message);
    void debug(const std::string &message);

private:
    log4cpp::Category &root;
};

#endif // LOGGER_H

