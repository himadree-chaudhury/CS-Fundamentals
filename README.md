# 🤖 CS-Foundation

This repository represents the basic and fundamentals to advanced concepts of CS. It covers a wide range of topics including programming languages, data structures, algorithms, databases, networking, operating systems, software development methodologies, and more. The goal is to provide a solid foundation for anyone looking to build a career in computer science or enhance their existing knowledge in the field.

# 📇 Index

- [List of Project Branches](#list-of-project-branches)
- [Managing Multiple Project Folders in a Single Git Repository (One Branch per Folder using Worktrees)](#managing-multiple-project-folders-in-a-single-git-repository-one-branch-per-folder-using-worktrees)

# List of Project Branches

### 1. [Introduction To C Programming](https://github.com/himadree-chaudhury/CS-Fundamentals/tree/intro-to-c)

This branch contains resources and code examples for learning C programming. It covers fundamental C programming concepts, libraries commonly used in C, and practical implementations of C algorithms.

# Managing Multiple Project Folders in a Single Git Repository (One Branch per Folder using Worktrees)

This repository contains multiple independent project folders.
Each folder is tied to its **own Git branch**, using [Git Worktrees](https://git-scm.com/docs/git-worktree). This keeps the remote branches clean while letting you organize your local machine with separate folders.

### 📁 Structure Example

```
AI-ML/                                    ← Main repo
│
├─ Introduction To C Programming/         ← Local folder for 'intro-to-c' branch
├─ Introduction to C++ For DSA/           ← Local folder for 'intro-to-cpp' branch
└─ README.md                              ← Lives only in the main branch
```

On GitHub:

- The `intro-to-c` branch only contains the contents of `Introduction To C Programming/`
- The `intro-to-cpp` branch only contains the contents of `Introduction to C++ For DSA/`
- The `main` branch does **not** contain these folders (they're in `.gitignore` locally)

---

### 🧭 Why Worktrees?

Normally, you’d have to **checkout different branches in the same folder** to work on multiple projects — messy and slow.
Worktrees let you check out **multiple branches at once** into separate folders, while all staying in the same repo.

---

### 🛠 How to Add a New Project Folder

Suppose you want to add a new project called `Introduction to C Programming` in its own folder and branch:

1. **Create a new branch**

   ```bash
   git branch intro-to-c
   ```

2. **Add a worktree** linked to that branch

   ```bash
   git worktree add "./Introduction To C Programming" intro-to-c
   ```

3. **Go inside the new folder** and work as usual

   ```bash
   cd "./Introduction To C Programming"
   # Add files, initialize code, etc.
   git add .
   git commit -m "Initialize Introduction To C Programming project"
   git push origin intro-to-c
   ```

4. **Ignore the folder on the main branch** so it doesn’t pollute main:
   Edit `.gitignore` on `main`:

   ```
   /Introduction To C Programming
   ```

   Then commit and push:

   ```bash
   git add .gitignore
   git commit -m "Ignore Introduction To C Programming folder in main"
   git push origin main
   ```

---

### 🌿 Adding More Worktrees

Repeat the above for every new project folder:

```bash
git branch new-project
git worktree add "./New-Project" new-project
```

---

### 🌿 Committing From main Branch and Remove Worktree Gitlink For The Folder

1. Add the folder to .gitignore on main(if not done already)

   Open .gitignore in the root of your repo (on the main branch) and add:

   ```bash
   /Introduction To C Programming
   ```

   Save it, then commit:

   ```bash
   git add .gitignore
   git commit -m "Ignore 'Python For ML' folder on main"
   git push origin main
   ```

2. Remove the accidentally tracked folder reference(if already committed)

   The “→” icon you saw on GitHub main means the folder got committed as a gitlink. To remove that cleanly:

   ```bash
   git rm -r --cached "Introduction To C Programming"
   ```

   Notice the quotes - they’re essential because of the spaces.

   Then commit and push:

   ```bash
   git commit -m "Remove worktree gitlink for 'Introduction To C Programming' from main"
   git push origin main
   ```

3. Verify

   You can check locally:

   ```bash
   git ls-tree main
   ```

   The entry for `Introduction To C Programming` should be gone.

   And on GitHub, refresh the main branch - that folder with the right arrow should disappear. Only your actual root files (e.g., README.md) should remain.

---

### 📋 Useful Commands

List all worktrees:

```bash
git worktree list
```

Remove a worktree:

```bash
git worktree remove "./Introduction To C++ For DSA"
```

Detach a worktree(force remove if necessary):

```bash
git worktree remove --force "./Introduction To C++ For DSA"
```

To undo the commit and keep file changes(Local):

```bash
git reset --soft HEAD^
```

To undo the commit and discard all changes(Local):

```bash
git reset --hard HEAD^
```

To undo a commit that has already been pushed to a remote repository:

```bash
git revert HEAD
```

To delete a local branch(switch to another branch first):

```bash
git branch -d <branch-name>
```

for force use `-D` instead of `-d`.

To delete a remote branch:

```bash
git push <remote-name> --delete <branch-name>
```

Typically, the `<remote-name>` is `origin`.

---

### 📝 Notes

- Each folder is **independent**. Commits inside one don’t affect the others.
- Push and pull inside each project folder as if it were its own repo.
- The root `README.md` stays in `main` and can document the overall structure.

This approach is ideal if you want **one repo** but **clean, isolated project branches**, without juggling multiple local clones.

---
