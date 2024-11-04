#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <cmath> //用于处理保存小数点后一位的函数
#include <iomanip>

#define FILEPATH "/home/hjx/AccountBook/accountbook/databases/AccountBook.txt"
#define INCOME "收入"
#define EXPENSE "支出"

using namespace std;

// 前向声明 DateTime 结构体，告知编译器稍后定义
struct DateTime;

// 通用功能性函数声明

// 绘制菜单的函数
void showMainMenu();
void showAccountMenu();
void showQueryMenu(); // 显示查询菜单

// 读取键盘输入进行合法性校验的函数
char readMenuSelection(int options);
char readQuitConfirm();
double readAmount();

// 保留小数点后一位小数
double roundToOneDecimalPlace(double value);

// 对日期结构体进行赋值
DateTime getDateTime(DateTime date);

#endif // COMMON_H
