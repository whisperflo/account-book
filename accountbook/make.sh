#!/bin/bash

# 日志文件路径
LOG_FILE="./log/program.log"

# 根据传入的参数进行判断
if [ "$1" == ".log" ]; then
    # 清空日志文件
    if [ -f "$LOG_FILE" ]; then
        > "$LOG_FILE"  # 使用 > 重定向来清空文件内容
        echo "日志文件已清空."
    else
        echo "日志文件不存在."
    fi

elif [ "$1" == "build" ]; then
    # 编译项目
    echo "正在编译项目..."
    g++ headFile/account_item.h headFile/common.h headFile/logger.h headFile/logger.cc ImplFile/menus.cc ImplFile/opeartions.cc read_input.cc xiaohuaAccount_item.cc -o main -llog4cpp -lpthread
    if [ $? -eq 0 ]; then
        echo "编译成功."
    else
        echo "编译失败，请检查错误信息."
    fi

else
    # 未知参数
    echo "未知参数，请使用 '.log' 或 'build'."
fi

