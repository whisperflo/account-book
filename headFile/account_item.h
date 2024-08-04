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
void selectAccounts(const vector<AccountItem> items);
