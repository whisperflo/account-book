#include "common.h"

// 交易结构体
struct AccountItem
{
	string type;		// 交易类型
	double amount;		// 交易金额
	string description; // 交易描述
};

// 针对账目数据进行操作的函数声明

// 加载账目数据
void loadDataFromFile(vector<AccountItem> &items);

// 记账
void accounting(vector<AccountItem> &items);

// 查询
void selectAccounts(const vector<AccountItem> &items);
void selectItems(const vector<AccountItem> &items);
void selectItems(const vector<AccountItem> &items, const string ItemType);

// 支出
void expense(vector<AccountItem> &items);

// 收入
void income(vector<AccountItem> &items);

// 数据写入文件
void insertToFile(const AccountItem item);

// 打印一条账单信息
void printItem(const AccountItem &item);
