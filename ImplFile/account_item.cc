#include "headFile/account_item.h"
/* //加载账目数据
void loadDataFromFile(vector<AccountItem> &items){
    sqlite3 *db;
    sqlite3_stmt *stmt;

    // 打开数据库
    if (sqlite3_open("transactions.db", &db) != SQLITE_OK) {
        cerr << "无法打开数据库: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }

    // 查询数据
    const char *sql = "SELECT id, date, type, amount, description FROM transactions";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        cerr << "查询失败: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }

    // 读取数据并存入 items 向量
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *dateText = sqlite3_column_text(stmt, 1);
        int type = sqlite3_column_int(stmt, 2);
        double amount = sqlite3_column_double(stmt, 3);
        const unsigned char *descText = sqlite3_column_text(stmt, 4);

        // 解析日期
        string dateStr = dateText ? reinterpret_cast<const char*>(dateText) : "";
        Date date;
        if (sscanf(dateStr.c_str(), "%d-%d-%d", &date.year, &date.month, &date.day) != 3) {
            cerr << "日期格式错误: " << dateStr << endl;
            continue;
        }

        // 枚举类型转换
        TransactionType transType = type == 0 ? INCOME : EXPENSE;

        // 创建 AccountItem 对象并加入 items 向量
        items.emplace_back(AccountItem{date, transType, amount, reinterpret_cast<const char*>(descText)});
    }

    // 清理资源
    sqlite3_finalize(stmt);
    sqlite3_close(db);
} */
