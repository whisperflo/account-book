#include "headFile/account_item.h"
#include "headFile/common.h"
#include "headFile/logger.h"

int main()
{
	// 创建 Logger 实例
	Logger &logger = Logger::getInstance("./log");

	// 1.加载文件中的账目数据
	vector<AccountItem> items;
	loadDataFromFile(items);
	logger.debug(std::string("AccountItem.size: ") + std::to_string(items.size()));
	// logger.info("Loaded account data from file.");

	bool quit = false;
	while (!quit)
	{
		// 2.显示主菜单
		showMainMenu();
		// logger.debug("Displayed main menu.");

		// 3.读取键盘选择，进行合法性校验
		char key = readMenuSelection(3);
		// logger.debug(std::string("User selected option: ") + key);

		switch (key)
		{
		case '1': // 1-记账
			showAccountMenu();
			accounting(items);
			// logger.info("Performed accounting operation.");
			break;

		case '2': // 2-查询
			showQueryMenu();
			selectAccounts(items);
			// logger.info("Performed query operation.");
			break;

		case '3': // 3-退出
			cout << "\n确认退出？ (Y/N):";
			if (readQuitConfirm() == 'Y')
			{
				quit = true;
				// logger.info("User confirmed exit.");
			}
			break;

		default:
			// logger.warn("Invalid menu selection.");
			break;
		}
	}

	// logger.info("Program terminated.");

	return 0;
}
