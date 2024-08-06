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
    item.amount = readAmount();
    cout << "\n备注：";
    getline(cin, item.description);
    // 将新建的收入保存在列表中
    items.push_back(item);

    // 同时写入文件，做持久化处理
    insertToFile(item);

    // 显示成功添加
    cout << "\n--------------------------记账成功！---------------------------\n"
         << endl;
    cout << "请按回车键Enter返回主菜单" << endl;
    string line;
    getline(cin, line);
}

// 记录支出
void expense(vector<AccountItem> &items)
{
    // 新构建一个AccountItem对象
    AccountItem item;
    item.type = EXPENSE; // 类型已提前确认

    // 记录用户输入的金额和描述
    cout << "\n本次支出的金额：";
    item.amount = -readAmount();

    cout << "\n备注：";
    getline(cin, item.description);
    // 将新建的收入保存在列表中
    items.push_back(item);

    // 同时写入文件，做持久化处理
    insertToFile(item);

    // 显示成功添加
    cout << "\n--------------------------记账成功！---------------------------\n"
         << endl;
    cout << "请按回车键Enter返回主菜单" << endl;
    string line;
    getline(cin, line);
}
// 查询
void selectAccounts(const vector<AccountItem> items)
{
}

// 将账目写入到文件中
void insertToFile(const AccountItem item)
{
    // 创建一个文件输出流对象,以追加方式进行写入
    /* ios::out：表示以输出（写入）模式打开文件。如果文件不存在，则创建新文件。如果文件存在，则截断文件长度为零。
       ios::app：表示以追加模式打开文件。所有写入操作都在文件末尾进行，不会覆盖现有内容 */
    ofstream os(FILEPATH, ios::out | ios::app); // 需要添加到之前的文件末尾而不是直接覆盖掉
    os << item.type << "\t" << item.amount << "\t\t" << item.description << endl;
    os.close();
}