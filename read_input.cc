#include "./headFile/common.h"

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
        // 读取用户的输入，并将这行信息都保存在str中
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
int readAmount()
{
}