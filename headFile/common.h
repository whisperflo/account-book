#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <cmath> //用于处理保存小数点后一位的函数
// #include "../headFile/account_item.h"

#define FILEPATH "/home/hjx/AccountBook/databases/AccountBook.txt"
#define INCOME "收入"
#define EXPENSE "支出"
using namespace std;

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
