#include "logger.h"
#include <sys/stat.h> // 引入头文件用于检查目录是否存在
#include <iostream>

bool checkAndCreateLogDir(const std::string &dir)
{
    struct stat info;
    // 检查目录是否存在
    if (stat(dir.c_str(), &info) != 0)
    {
        // 目录不存在，创建目录
        if (mkdir(dir.c_str(), 0777) != 0)
        {
            return false; // 创建失败
        }
    }
    else if (!(info.st_mode & S_IFDIR))
    {
        // 存在但不是目录
        return false;
    }
    return true; // 目录存在或已成功创建
}

Logger::Logger(const std::string &logDir) : root(log4cpp::Category::getRoot())
{
    if (!checkAndCreateLogDir(logDir))
    {
        std::cerr << "Failed to create or access log directory: " << logDir << std::endl;
        throw std::runtime_error("Log directory error");
    }

    log4cpp::PatternLayout *fileLayout = new log4cpp::PatternLayout();
    fileLayout->setConversionPattern("%d [%p] %c: %m%n"); // 正常格式
    log4cpp::Appender *fileAppender = new log4cpp::FileAppender("file", logDir + "/program.log");
    fileAppender->setLayout(fileLayout);

    root.setPriority(log4cpp::Priority::DEBUG); // 设置根类别的优先级为 DEBUG
    root.addAppender(fileAppender);             // 只输出到文件
}

Logger::~Logger()
{
    log4cpp::Category::shutdown(); // 结束日志系统
}

void Logger::info(const std::string &message)
{
    root.info(message);
}

void Logger::warn(const std::string &message)
{
    root.warn(message);
}

void Logger::debug(const std::string &message)
{
    root.debug(message);
}
