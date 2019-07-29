---
title: leetcode74
data: 2018-12-23 23:20
tag: [leetcode,数组,二分查找]
---

### 74. 搜索二维矩阵（Search a 2D Matrix）

#### 中文题目

编写一个高效的算法来判断 *m* x *n* 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

- 每行中的整数从左到右按升序排列。
- 每行的第一个整数大于前一行的最后一个整数。

**示例 1:**

```
输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
```

**示例 2:**

```
输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false
```

#### 英文题目

Write an efficient algorithm that searches for a value in an *m* x *n* matrix. This matrix has the following properties:

- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

**Example 1:**

```
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
```

**Example 2:**

```
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
```

#### 题目解答

- 一开始我是将其当成是二维数组处理的，先确定行再确定列
- 后来将之作为特殊的一维数组进行处理
- 第一次提交，我的代码是这样的

**代码：**

```c
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int min = 0, max = matrixRowSize * matrixColSize - 1;
    
    while (min <= max) {
        int mid = min + (max-min)/2;
        if (*((*matrix)+mid) > target)
            max = mid - 1;
        else if (*((*matrix)+mid) < target)
            min = mid + 1;
        else
            return true;
    }
    return false;
}
```

- 结果发生了错误，之后我进行了调试，发现在此系统中，样例数组在传进`searchMatrix()`函数后，采用`*((*matrix)+i)`的方式对数组元素进行逐个打印，输出的结果是这样的 `1 3 5 7 0 0 33 0 10 11 16 20 0 0 33 0 23 30 34 50`

- 每一行之间的地址实质上是不连续的，所以，这种写法会挂掉

- 关于为何不连续，我稍微查了下，发现是由于传参方式的原因

- 之后我看了主站上的[讨论文章](https://leetcode.com/problems/search-a-2d-matrix/discuss/26220/Don't-treat-it-as-a-2D-matrix-just-treat-it-as-a-sorted-list)，将我的代码做了相应的改进

```c
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int min = 0, max = matrixRowSize * matrixColSize - 1;
    
    while (min <= max) {
        int mid = min + (max-min)/2;
        
        if (matrix[mid/matrixColSize][mid%matrixColSize] > target)
            max = mid - 1;
        else if (matrix[mid/matrixColSize][mid%matrixColSize] < target)
            min = mid + 1;
        else
            return true;
    }
    return false;
}
```

- 提交成功，4ms