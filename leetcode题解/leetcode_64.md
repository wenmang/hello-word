---
title: leetcode64
data: 2018-12-19 22:18
tag: [leetcode,数组,动态规划]
---

### 64. 最小路径和（Unique Paths）

#### 中文题目

给定一个包含非负整数的 *m* x *n* 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

**说明：**每次只能向下或者向右移动一步。

**示例:**

```
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
```

#### 英文题目

Given a *m* x *n* grid filled with non-negative numbers, find a path from top left to bottom right which *minimizes* the sum of all numbers along its path.

**Note:** You can only move either down or right at any point in time.

**Example:**

```
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
```

---

#### 题目解答

这道题和`62题`的处理思路完全一致

- 对边缘进行初始化之后，类似贪心的思路，每一步都逐个寻找最短路径
- 也就是`由图中起点开始，到图中的[i][j]位置其路径数，实际上就等于起点到[i-1][j]和[i][j-1]之中较短的哪一条路径`

**代码：**

```c
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    for (int i = 1; i < gridRowSize; i++) 
        grid[i][0] = grid[i][0] + grid[i-1][0];
    for (int i = 1; i < gridColSize; i++) 
        grid[0][i] = grid[0][i] + grid[0][i-1];
    for (int i = 1; i < gridRowSize; i++) {
        for (int j = 1; j < gridColSize; j++) {
            int min = (grid[i][j-1] < grid[i-1][j] ? grid[i][j-1] : grid[i-1][j]);
            grid[i][j] = grid[i][j] + min;
        }
    }
    return grid[gridRowSize-1][gridColSize-1];
}
```

