#include "../headFile/account_item.h"
#include "../headFile/common.h"
#include "../headFile/logger.h"

// 读取文件中的账目数据
void loadDataFromFile(vector<AccountItem> &items)
{
    Logger &logger = Logger::getInstance("./log"); // 获取单例 Logger 实例

    ifstream os(FILEPATH);

    // 检查文件是否成功打开
    if (!os.is_open())
    {
        logger.debug("Fail to open the file:" + std::string(FILEPATH));
        return;
    }

    string line;
    while (getline(os, line))
    {
        stringstream ss(line);
        AccountItem item;
        char hyphen, colon;

        ss >> item.type >> item.amount >> std::ws;
        getline(ss, item.description, '\t');
        ss >> item.date.year >> hyphen >> item.date.month >> hyphen >> item.date.day >> item.date.hour >> colon >> item.date.minute >> colon >> item.date.second;
        items.push_back(item);
    }

    os.close();
    logger.debug("loadDataFromFile items.size:" + std::to_string(items.size()));
    if (items.empty())
    {
        logger.warn("Fail to loadItemsData!!!");
    }
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
    item.date = getDateTime(DateTime());
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

    item.date = getDateTime(DateTime());
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

// 将账目写入到文件中
void insertToFile(const AccountItem item)
{
    // 创建一个文件输出流对象,以追加方式进行写入
    /* ios::out：表示以输出（写入）模式打开文件。如果文件不存在，则创建新文件。如果文件存在，则截断文件长度为零。
       ios::app：表示以追加模式打开文件。所有写入操作都在文件末尾进行，不会覆盖现有内容 */
    ofstream os(FILEPATH, ios::out | ios::app); // 需要添加到之前的文件末尾而不是直接覆盖掉
    if (!os.is_open())
    {
        cout << "无法打开文件: " << FILEPATH << endl;
        return;
    }
    os << item.type << "\t" << item.amount << "\t\t" << item.description << "\t\t" << item.date.year << "-"
       << std::setw(2) << std::setfill('0') << item.date.month << "-"
       << std::setw(2) << std::setfill('0') << item.date.day << " "
       << std::setw(2) << std::setfill('0') << item.date.hour << ":"
       << std::setw(2) << std::setfill('0') << item.date.minute << ":"
       << std::setw(2) << std::setfill('0') << item.date.second << endl;
    os.close();
}
// 查询
void selectAccounts(const vector<AccountItem> &items)
{
    // 读取键盘选择，进行合法性校验
    char key = readMenuSelection(4);
    switch (key)
    {
    case '1': // 1- 查询所有账单，并统计总收支
        selectItems(items);
        break;
    case '2': // 2- 查询所有账单，并统计总收入
        selectItems(items, INCOME);
        break;
    case '3': // 3- 查询所有账单，并统计总支出
        selectItems(items, EXPENSE);
        break;
    default:
        break;
    }
}

// 查询账单功能函数
void selectItems(const vector<AccountItem> &items)
{
    cout << "-------------------查询结果-------------------" << endl;
    cout << "\n类型\t\t金额\t\t备注\t\t时间\n"
         << endl;

    // 遍历所有账目，统计总收支
    double total = 0;
    for (auto item : items)
    {
        printItem(item);
        total += item.amount;
    }

    // 输出信息
    cout << "========================================\n"
         << endl;
    cout << "总收支：" << total << endl;
    cout << "请按回车键Enter返回主菜单" << endl;
    string line;
    getline(cin, line);
}

// 查询所有账单，并统计总收入
// 实现方式：函数重载
void selectItems(const vector<AccountItem> &items, const string ItemType)
{
    cout << "-----------查询结果-----------" << endl;
    cout << "\n类型\t\t金额\t\t备注\t时间\n"
         << endl;
    if (items.size() == 0)
    {
        cout << "查询数组为空" << endl;
        // return;
    }
    // 遍历所有账目，统计总收支
    double total = 0;
    for (auto item : items)
    {
        if (item.type == ItemType)
        {
            printItem(item);
            total += item.amount;
        }
    }
    // 输出信息
    cout << "========================================\n"
         << endl;
    cout << ((ItemType == INCOME) ? "总收支：" : "总支出") << total << endl;
    cout << "请按回车键Enter返回主菜单" << endl;
    string line;
    getline(cin, line);
}

// 打印一条账单信息
void printItem(const AccountItem &item)
{
    cout << item.type << "\t\t" << item.amount << "\t\t" << item.description << "\t\t" << item.date.year << "-"
         << std::setw(2) << std::setfill('0') << item.date.month << "-"
         << std::setw(2) << std::setfill('0') << item.date.day << " "
         << std::setw(2) << std::setfill('0') << item.date.hour << ":"
         << std::setw(2) << std::setfill('0') << item.date.minute << ":"
         << std::setw(2) << std::setfill('0') << item.date.second
         << std::endl;
}