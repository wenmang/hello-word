---
title: leetcode59
data: 2018-12-16 13:36
tag: [leetcode,数组]
---

### 59. 螺旋矩阵 II（Spiral Matrix II）

#### 中文题目

给定一个正整数 *n*，生成一个包含 1 到 *n*2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

**示例:**

```
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```

---

#### 英文题目

Given a positive integer *n*, generate a square matrix filled with elements from 1 to *n*2 in spiral order.

**Example:**

```
Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
```

---

#### 题目解答

- 与螺旋矩阵I处理思路一致，只不过把输出改成了建立

**代码：**

```c
/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int** res = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
        res[i] = (int*)malloc(n*sizeof(int));

    int rUp = 0, rDown = n - 1;
    int cLeft = 0, cRight = n - 1;
    int tmp = 1;
    
    while (rUp <= rDown && cLeft <= cRight) {
        for (int i = cLeft; i <= cRight; i++) 
            res[rUp][i] = tmp++;
        rUp++;
        for (int i = rUp; i <= rDown; i++) 
            res[i][cRight] = tmp++;
        cRight--;
        for (int i = cRight; i >= cLeft; i--) 
            res[rDown][i] = tmp++;
        rDown--;
        for (int i = rDown; i >= rUp; i--) 
            res[i][cLeft] = tmp++;
        cLeft++;
    }
    return res;
}
```

- 与`I`不同的是，无需处理特殊情况