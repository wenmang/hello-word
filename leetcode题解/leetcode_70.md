---
title: leetcode70
data: 2018-12-20 22:18
tag: [leetcode,动态规划]
---

### 70. 爬楼梯（Climbing Stairs）

#### 中文题目

假设你正在爬楼梯。需要 *n* 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

**注意：**给定 *n* 是一个正整数。

**示例 1：**

```
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
```

**示例 2：**

```
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
```

#### 英文题目

You are climbing a stair case. It takes *n* steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

**Note:** Given *n* will be a positive integer.

**Example 1:**

```
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

**Example 2:**

```
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

#### 题目解答

- 本题类似于数学题，数学题由于强大的数学家们的缘故，总是会有神奇的解法，我想此题应该可以找到规律
- 然后就。。。失败了。。。
- 搜索发现是一个 斐波那契数列。。。好吧！斐波那契数列真的很常见，于是，就写出了熟悉的代码

**代码：**

```c
int climbStairs(int n) {
    int res[200];
    res[0] = 1;
    res[1] = 2;
    for (int i = 2; i < n; i++)
        res[i] = res[i-1] + res[i-2];
    return res[n-1];
}
```

- 就不解释了，挺简单的，最简单的运用动规的算法吧应该是

