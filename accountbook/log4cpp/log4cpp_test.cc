#include "log4cpp/Category.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/PatternLayout.hh"
#include "log4cpp/Priority.hh"

int main()
{
	// 创建文件输出的 Appender，并使用 PatternLayout 设置正常日志格式
	log4cpp::PatternLayout *fileLayout = new log4cpp::PatternLayout();
	fileLayout->setConversionPattern("%d [%p] %c: %m%n"); // 正常格式
	log4cpp::Appender *fileAppender = new log4cpp::FileAppender("file", "program.log");
	fileAppender->setLayout(fileLayout);

	// 设置根日志类别的配置
	log4cpp::Category &root = log4cpp::Category::getRoot();
	root.setPriority(log4cpp::Priority::DEBUG); // 将根类别的优先级设置为 INFO
	root.addAppender(fileAppender);				// 只输出到文件

	// 测试日志输出
	root.info("This is an info message from root category.");
	root.warn("This is a warning message from root category.");
	root.error("This is an error message from root category.");

	// 结束日志系统
	log4cpp::Category::shutdown();

	return 0;
}
