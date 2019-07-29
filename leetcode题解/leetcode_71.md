---
title: leetcode71
data: 2018-12-21 22:18
tag: [leetcode,栈,字符串]
---

### 71. 简化路径（Simplify Path）

#### 中文题目

给定一个文档 (Unix-style) 的完全路径，请进行路径简化。

例如，
**path** = `"/home/"`, => `"/home"`
**path** = `"/a/./b/../../c/"`, => `"/c"`

**边界情况:**

- 你是否考虑了 路径 = `"/../"` 的情况？
  在这种情况下，你需返回 `"/"` 。
- 此外，路径中也可能包含多个斜杠 `'/'` ，如 `"/home//foo/"` 。
  在这种情况下，你可忽略多余的斜杠，返回 `"/home/foo"` 。

---

#### 英文题目

Given an absolute path for a file (Unix-style), simplify it. 

For example,
**path** = `"/home/"`, => `"/home"`
**path** = `"/a/./b/../../c/"`, => `"/c"`
**path** = `"/a/../../b/../c//.//"`, => `"/c"`
**path** = `"/a//b////c/d//././/.."`, => `"/a/b/c"`

In a UNIX-style file system, a period ('.') refers to the current directory, so it can be ignored in a simplified path. Additionally, a double period ("..") moves up a directory, so it cancels out whatever the last directory was. For more information, look here: <https://en.wikipedia.org/wiki/Path_(computing)#Unix_style>

**Corner Cases:**

- Did you consider the case where **path** = `"/../"`?
  In this case, you should return `"/"`.
- Another corner case is the path might contain multiple slashes `'/'`together, such as `"/home//foo/"`.
  In this case, you should ignore redundant slashes and return `"/home/foo"`.

---

#### 题目解答

- 惊了，英文题目竟然比中文的多了一部分和一个链接！！！
- 本题主要是简化路径，利用栈进行字符串的处理，而C语言没有字符串这个概念，所以字符串的处理也便成了本题最大的难点
- 