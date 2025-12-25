# 🧰 Git 使用指南（C++ 项目）

本文档记录本项目中 Git 的标准使用流程，包括初始化、提交、推送、拉取、分支合并、冲突解决及常见问题处理。

---

## 🔧 1. 初始化本地仓库（仅首次）

```bash
git init
git add .
git commit -m "feat: initial project structure"
```

✅ **确保 `.gitignore` 已配置**（见第 6 节），避免提交 `bin/`、`.exe` 等临时文件。

---

## 🌐 2. 关联远程仓库（仅首次）

```bash
# HTTPS（不推荐，需 Token）
git remote add origin https://github.com/HENGDENG/DataStructure.git

# 或（推荐）使用 SSH 地址（免密、稳定）：
git remote add origin git@github.com:HENGDENG/DataStructure.git
```

💡 查看当前远程地址：  
```bash
git remote -v
```

---

## 📤 3. 推送代码到 GitHub（首次）

```bash
git push -u origin main
```

⚠️ 若提示 `! [rejected] ... (non-fast-forward)` 或 `unrelated histories`，说明远程已有提交（如 README），需先拉取合并（见第 5 节）。

---

## 🔄 4. 日常开发流程  
**修改 → 提交 → 同步 → 推送**

```bash
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
```

✅ **每次推送前务必先 `pull`，保持历史同步。**

> 💡 建议设置默认拉取策略（避免 divergent 分支错误）：
> ```bash
> git config --global pull.rebase true   # 推荐：线性历史
> # 或
> git config --global pull.rebase false  # 传统 merge 方式
> ```

---

## 🛠️ 5. 常见问题与解决

### ❌ 问题 1：`! [rejected] main -> main (non-fast-forward)`

**原因**：本地分支落后于远程（例如你在 GitHub 网页上编辑了文件，或执行过 `git reset --hard` 回退）。

**解决**（安全方式，保留远程更改）：
```bash
git fetch origin
git pull --rebase origin main    # 推荐：线性整合
# 若有冲突，解决后：
#   git add <file>
#   git rebase --continue
git push
```

> ⚠️ **不要轻易使用 `--force`**，除非你确定要覆盖远程历史：
> ```bash
> git push --force-with-lease origin main
> ```

---

### ❌ 问题 2：`fatal: Need to specify how to reconcile divergent branches`

**原因**：Git ≥2.9 要求显式指定合并策略（因本地与远程已分叉）。

**解决**：
```bash
# 显式指定策略（二选一）
git pull --rebase origin main        # 推荐：rebase
git pull --no-rebase origin main     # 传统：merge
```

或设置全局默认行为（推荐）：
```bash
git config --global pull.rebase true
```

---

### ❌ 问题 3：合并时提示 `Your local changes would be overwritten`

**原因**：工作区有未提交的修改，而合并会覆盖这些文件。

**解决**（三选一）：

#### ✅ 方案 A：暂存修改（推荐）
```bash
git stash                # 临时保存修改
git merge origin/master  # 或 git pull
git stash pop            # 恢复修改（可能需解决冲突）
```

#### ✅ 方案 B：先提交
```bash
git add .
git commit -m "WIP: save local changes"
git merge origin/master
```

#### ✅ 方案 C：丢弃修改（谨慎！）
```bash
git checkout -- src/Sorting.cpp   # 丢弃单个文件
# 或
git reset --hard                  # 丢弃所有未提交更改
```

---

### ❌ 问题 4：合并冲突（`CONFLICT (content)`）

**现象**：文件中出现 `<<<<<<< HEAD`, `=======`, `>>>>>>> origin/master` 标记。

**解决步骤**：
1. 用编辑器（如 `vim`、`code`）打开冲突文件
2. **保留需要的代码，删除三行标记**
3. 标记解决并提交：
   ```bash
   git add src/Sorting.cpp
   git commit   # 完成合并
   ```

> 💡 Vim 快速操作：
> - 复制多行：`5yy`
> - 删除多行：`3dd`
> - 进入行选择模式：`V` → 移动 → `d`（删）或 `y`（复制）

---

### ❌ 问题 5：误操作后找不到原分支或提交

**原因**：执行 `git reset --hard` 后，分支指针移动，原提交变“悬空”。

**恢复方法**：
```bash
# 1. 查看 HEAD 历史
git reflog

# 2. 找到原提交 ID（如 eafeacb）
# 3. 恢复
git reset --hard eafeacb
```

✅ **预防措施**：重置前先建备份分支：
```bash
git checkout -b backup-before-reset
```

---

### ❌ 问题 6：HTTPS 推送卡住 / 要密码

**原因**：GitHub 已禁用账号密码登录。

**推荐方案：切换到 SSH**
```bash
# 1. 生成 SSH 密钥（若无）
ssh-keygen -t ed25519 -C "you@example.com"

# 2. 复制公钥
cat ~/.ssh/id_ed25519.pub

# 3. 添加到 GitHub → Settings → SSH and GPG keys

# 4. 修改远程地址
git remote set-url origin git@github.com:HENGDENG/DataStructure.git
```

---

## 🗑️ 6. `.gitignore` 规则（必须提交）

确保项目根目录包含 `.gitignore`，内容如下：

```gitignore
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
```

✅ **`.gitignore` 本身需要被提交**：
```bash
git add .gitignore
git commit -m "add .gitignore"
```

---

## 💡 7. 实用技巧

| 操作 | 命令 |
|------|------|
| 查看简洁提交历史 | `git log --oneline -10` |
| 撤销工作区修改 | `git restore <file>` |
| 撤销暂存区文件 | `git restore --staged <file>` |
| 设置 VSCode 为默认编辑器 | `git config --global core.editor "code --wait"` |
| 查看本地 vs 远程差异 | `git branch -vv` |
| 查找包含 `main` 函数的文件 | `git grep "int main"` |
| 查看远程分支内容（不切换） | `git show origin/master:src/Sorting.cpp` |

---

📝 **维护人**：HENGDENG  
📅 **最后更新**：2025-12-25  
🔗 **仓库地址**：https://github.com/HENGDENG/DataStructure.git

--- 

> 本指南将持续更新。遇到新问题？请先 `git status` + `git log` + `git reflog`，再查阅本文档！