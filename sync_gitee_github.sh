#!/bin/bash

# 设置要提交的消息，使用参数或默认消息
commit_message=${1:-"更新：同步提交到 Gitee 和 GitHub"}

# 提交代码到 Gitee 和 GitHub
git add .
git commit -m "$commit_message"

# 推送到 Gitee
echo "正在推送到 Gitee..."
git push origin main  # 或者你的 Gitee 分支名称

# 推送到 GitHub
echo "正在推送到 GitHub..."
git push github main  # 或者你的 GitHub 分支名称

echo "同步推送到 Gitee 和 GitHub 完成！"
