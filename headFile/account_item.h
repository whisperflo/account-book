#include<iostream>
#include<string>

using namespace std;

//日期结构体
struct Date{
	int year;
	int month;
	int day;
};

//交易枚举类型
enum TransactionType{
	INCOME,
	EXPENSE
};

//交易结构体
struct AccountItem{
	Date date; //交易日期
	TransactionType type; //交易类型
	double amount;  //交易金额
	string description; //交易描述
};
