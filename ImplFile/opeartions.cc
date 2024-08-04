#include "../headFile/account_item.h"
#include "../headFile/common.h"

// 读取文件中的账目数据
void loadDataFromFile(vector<AccountItem> &items)
{
    ifstream os(FILEPATH);

    // 逐行读取每一条账目，并将其包装成AccountItem
    AccountItem item;
    string word;
    while (os >> item.type >> item.amount >> item.description)
    {
        items.push_back(item);
    }
    os.close();
}

// 记账
void accounting(vector<AccountItem> &items)
{
    // 读取键盘选择，进行合法性校验
    char key = readMenuSelection(3);
    switch (key)
    {
    case '1': // 1-收入
        income(items);
        break;
    case '2': // 2-支出
        expense(items);
        break;
    case '3': // 3-返回主菜单
        break;
    }
}

// 记录收入
void income(vector<AccountItem> &items)
{
    // 新构建一个AccountItem对象
    AccountItem item;
    item.type = INCOME; // 类型已提前确认

    // 记录用户输入的金额和描述
    cout << "\n本次收入的金额：";
    readAmount();
}

// 记录支出
void expense(vector<AccountItem> &items)
{
}
// 查询
void selectAccounts(const vector<AccountItem> items)
{
}