#include "./headFile/common.h"
#include "./headFile/account_item.h"
// 读取键盘输入进行合法性校验的函数
char readMenuSelection(int options)
{
    string str;
    while (true)
    {
        // 读取用户的输入，并将这行信息都保存在str中
        getline(cin, str);

        // 进行合法性校验
        if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > options)
        {
            cout << "输入错误，请重新选择";
        }
        else
            break;
    }

    // 输入合法
    return str[0];
}

// 读取确认退出的信息，并返回主菜单
char readQuitConfirm()
{
    string str;
    while (true)
    {
        // 读取用户的一行输入数据，并将这行信息都保存在str中
        getline(cin, str);

        // 进行合法性校验
        if (str.size() != 1 || toupper(str[0]) != 'Y' && toupper(str[0]) != 'N')
        {
            cout << "输入错误，请重新选择(Y/N):";
        }
        else
            break;
    }

    // 输入合法
    return toupper(str[0]);
}

// 读取用户输入的金额
double readAmount()
{
    double amount;
    string str;
    while (true)
    {
        getline(cin, str);

        // 进行合法性校验
        try
        {
            amount = stod(str);
            break;
        }
        catch (invalid_argument e)
        {
            cout << "输入错误，请正确输入数字：";
        }
    }
    return roundToOneDecimalPlace(amount);
}

// 保留小数点后一位
double roundToOneDecimalPlace(double value)
{
    return round(value * 10.0) / 10.0;
}

// 对日期结构体进行赋值
DateTime getDateTime(DateTime date)
{
    // 获取系统当前的时间，拿到年月日时分秒
    std::time_t currentTime = std::time(nullptr);
    // 转换为本地时间
    std::tm *localtime = std::localtime(&currentTime);

    date.year = localtime->tm_year + 1900; // 年份从1900年开始，因此需要加1900
    date.month = localtime->tm_mon + 1;    // tm_mon从0开始，因此要加1
    date.day = localtime->tm_mday;         // 天
    date.hour = localtime->tm_hour;        // 小时
    // 会出现小时和分钟小于10的时候会以单个数字显示而不是以两位数的格式
    date.minute = localtime->tm_min; // 分钟
    date.second = localtime->tm_sec; // 秒
    return date;
}