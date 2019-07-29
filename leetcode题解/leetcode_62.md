---
title: leetcode62
data: 2018-12-17 22:18
tag: [leetcode,数组,动态规划]
---

### 62. 不同路径（Unique Paths）

#### 中文题目

一个机器人位于一个 *m x n* 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/robot_maze.png)

例如，上图是一个7 x 3 的网格。有多少可能的路径？

**说明：***m* 和 *n* 的值均不超过 100。

**示例 1:**

```
输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
```

**示例 2:**

```
输入: m = 7, n = 3
输出: 28
```

---

#### 英文题目

A robot is located at the top-left corner of a *m* x *n* grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

![img](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)
Above is a 7 x 3 grid. How many possible unique paths are there?

**Note:** *m* and *n* will be at most 100.

**Example 1:**

```
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
```

**Example 2:**

```
Input: m = 7, n = 3
Output: 28
```

---

#### 题目解答

- 这周主要刷了一些动态规划的题，感觉还是没手感，自己在实际中碰到之后不一定能写出来代码
- 本题在拿到之后我本能地想到的是搜索，但是发现写不出来，代码能力真令人捉急啊。。。
- 后来看了别人的思路，发现实现非常简单，而且也是采用的动态规划思想
- 整体解释来说，由于只能向右和向下移动，所以`由图中起点开始，到图中的[i][j]位置其路径数，实际上就等于起点到[i-1][j]和[i][j-1]的路径数之和`，于是采用`自底向上`的设计方法，就可写出代码

**代码：**

```c
int uniquePaths(int m, int n) {
    int res[m][n];
    for (int i = 0; i < m; i++)
        res[i][0] = 1;
    for (int i = 0; i < n; i++)
        res[0][i] = 1;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            res[i][j] = res[i-1][j] + res[i][j-1];
    
    return res[m-1][n-1];
}
```

- 代码整体无坑向数据，所以无有特殊数据处理
- 首先对边缘情况进行初始化，因为所有靠边的方块均只有一种走法，也就是所有靠边方块只有一条路径
- 对其余方块逐个处理