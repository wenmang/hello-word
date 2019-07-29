---
title: leetcode54
data: 2018-12-14 22:52
tag: [leetcode,数组]
---

### 54. 螺旋矩阵（Length of Last Word）

#### 中文题目

给定一个包含 *m* x *n* 个元素的矩阵（*m* 行, *n* 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

**示例 1:**

```
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
```

**示例 2:**

```
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
```

---

#### 英文题目

Given a matrix of *m* x *n* elements (*m* rows, *n* columns), return all elements of the matrix in spiral order.

**Example 1:**

```
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
```

**Example 2:**

```
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

---

#### 题目解答

- 本题不算难题吧！想出解法是昨天的事了，但是解决一直拖到今天
- 大体思路就是，设置上下左右四个“墙壁”，循环直到“碰壁”就调转方向
- 我对于本题有两个写不出的点
  - 所有点都被遍历后应该怎样结束循环，也就是最外层循环的结束条件
  - “墙壁”的设置，如何设置“墙壁”以及如何“碰壁”
- 之后参照了讨论里别人写的[代码](https://leetcode.com/problems/spiral-matrix/discuss/175925/Very-easy-C-code-No-need-of-extra-If-statements-easy-to-remember)。。。

**代码：**

```c

```

- 理解代码，可通过画矩阵理解
  - 细节一：采用小于等于，而非将边界值扩大一或者缩小一，防止出现溢出
  - 细节二：关于哪个边界的加减，画图具体分析
- 提交后发现，产生了奇怪的报错，根据多年经验，leetcode奇怪的报错一般都是内存问题引起
- 然后根据错误的数据`[[1, 2, 3, 4, 5, 6, 7, 8, 9]]`, 只有一行，到第二个内循环仍然会进入，所以会引起溢出
- 这时我考虑对特殊情况进行处理，但发现好像也不是太好
- 此时我再次看了别人的代码，迅速理解了其代码中我之前不理解的部分，也就是在内层判定中，条件加上一个`res`数组不满
- 加上之后，便通过了

**代码：**

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int size = matrixRowSize * matrixColSize;
    int* res = (int*)malloc(size*sizeof(int));
    int rUp = 0, rDown = matrixRowSize - 1;
    int cLeft = 0, cRight = matrixColSize - 1;
    int tmp = 0;
    
    while (rUp <= rDown && cLeft <= cRight) {
        for (int i = cLeft; i <= cRight && tmp != size; i++) 
            res[tmp++] = matrix[rUp][i];
        rUp++;
        for (int i = rUp; i <= rDown && tmp != size; i++) 
            res[tmp++] = matrix[i][cRight];
        cRight--;
        for (int i = cRight; i >= cLeft && tmp != size; i--) 
            res[tmp++] = matrix[rDown][i];
        rDown--;
        for (int i = rDown; i >= rUp && tmp != size; i--) 
            res[tmp++] = matrix[i][cLeft];
        cLeft++;
    }
    return res;
}
```

