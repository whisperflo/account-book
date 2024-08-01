#include "common.h"

// 日期结构体
struct Date
{
	int year;
	int month;
	int day;
};

// 交易枚举类型
enum TransactionType
{
	INCOME,
	EXPENSE
};

// 交易结构体
struct AccountItem
{
	Date date;			  // 交易日期
	TransactionType type; // 交易类型
	double amount;		  // 交易金额
	string description;	  // 交易描述
};

// 针对账目数据进行操作的函数声明

// 加载账目数据
void loadDataFromFile(vector<AccountItem> &items);

// 记账
void accounting(vector<AccountItem> &items);

// 查询
void selectAccounts(const vector<AccountItem> items);
