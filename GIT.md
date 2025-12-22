# 🧰 Git 使用指南（C++ 项目）

本文档记录本项目中 Git 的标准使用流程，包括初始化、提交、推送、拉取及常见问题处理。

---

## 🔧 1. 初始化本地仓库（仅首次）

```bash
git init
git add .
git commit -m "feat: initial project structure"
✅ 确保 .gitignore 已配置（见下文），避免提交 bin/ 等临时文件。

🌐 2. 关联远程仓库（仅首次）
Bash
编辑
git remote add origin https://github.com/HENGDENG/DataStructure.git
或（推荐）使用 SSH 地址：

Bash
编辑
git remote add origin git@github.com:HENGDENG/DataStructure.git
💡 查看当前远程地址：git remote -v

📤 3. 推送代码到 GitHub（首次）
Bash
编辑
git push -u origin main
⚠️ 若提示 rejected (non-fast-forward) 或 unrelated histories，说明远程已有提交（如 README），需先拉取合并（见第 5 节）。

🔄 4. 日常开发流程
修改 → 提交 → 同步 → 推送
Bash
编辑
# 1. 查看更改
git status

# 2. 添加文件
git add src/your_file.cpp

# 3. 提交（写清晰信息）
git commit -m "fix: correct binary tree traversal logic"

# 4. 拉取远程最新更改（关键！避免冲突）
git pull origin main

# 5. 推送到 GitHub
git push
✅ 每次推送前务必先 pull，保持历史同步。

🛠️ 5. 常见问题与解决
❌ 问题 1：! [rejected] main -> main (non-fast-forward)
原因：本地分支落后于远程（如在 GitHub 网页上修改了文件）。

解决：

Bash
编辑
git pull --allow-unrelated-histories --no-rebase origin main
# 若有冲突，手动解决后：
git add .
git commit -m "resolve merge conflict"
git push
❌ 问题 2：fatal: Need to specify how to reconcile divergent branches
原因：Git 版本 ≥2.9，要求显式指定合并策略。

解决：使用完整命令（见上）或设置默认行为：

Bash
编辑
git config --global pull.rebase false
❌ 问题 3：HTTPS 推送卡住 / 要密码
原因：GitHub 已禁用账号密码登录，必须使用 Personal Access Token 或 SSH。

推荐方案：切换到 SSH（免密、稳定、速度快）：

Bash
编辑
# 1. 生成 SSH 密钥（若无）
ssh-keygen -t ed25519 -C "you@example.com"

# 2. 复制公钥内容
cat ~/.ssh/id_ed25519.pub

# 3. 将公钥添加到 GitHub → Settings → SSH and GPG keys

# 4. 修改远程地址为 SSH
git remote set-url origin git@github.com:HENGDENG/DataStructure.git
🗑️ 6. .gitignore 规则（必须提交）
确保项目根目录包含 .gitignore，内容如下：

Gitignore
编辑
# 编译输出
bin/
*.exe
*.out
a.out

# 调试符号
*.dSYM/

# IDE 配置（可选不提交）
.vscode/tasks.json
.vscode/launch.json

# 系统文件
.DS_Store
✅ .gitignore 本身需要被提交：git add .gitignore && git commit -m "add .gitignore"

💡 7. 实用技巧
操作	命令
查看简洁提交历史	git log --oneline -10
撤销工作区修改	git restore <file>
撤销暂存区文件	git restore --staged <file>
设置 VSCode 为默认编辑器	git config --global core.editor "code --wait"
查看本地 vs 远程差异	git branch -vv
📝 维护人：HENGDENG

最后更新：2025-12-22

仓库地址：https://github.com/HENGDENG/DataStructure.git