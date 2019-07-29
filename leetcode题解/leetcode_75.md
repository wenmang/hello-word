---
title: leetcode75
data: 2018-12-24 23:20
tag: [leetcode,数组,排序,双指针]
---

### 75. 颜色分类（Short Colors）

#### 中文题目

给定一个包含红色、白色和蓝色，一共 *n* 个元素的数组，**原地**对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

**注意:**
不能使用代码库中的排序函数来解决这道题。

**示例:**

```
输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
```

**进阶：**

- 一个直观的解决方案是使用计数排序的两趟扫描算法。
  首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
- 你能想出一个仅使用常数空间的一趟扫描算法吗？

#### 英文题目

Given an array with *n* objects colored red, white or blue, sort them **in-place** so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

**Note:** You are not suppose to use the library's sort function for this problem.

**Example:**

```
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

**Follow up:**

- A rather straight forward solution is a two-pass algorithm using counting sort.
  First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
- Could you come up with a one-pass algorithm using only constant space?

#### 题目解答

- 基本版的思路很简单，就是统计`1 2 3`的个数，并对原数组进行重新排列即可

**代码：**

```c
void sortColors(int* nums, int numsSize) {
    int numsR = 0, numsW = 0, numsB = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0)
            numsR++;
        else if (nums[i] == 1)
            numsW++;
        else
            numsB++;
    }
    for (int i = 0; i < numsSize; i++) {
        if (numsR != 0) {
            nums[i] = 0;
            numsR--;
        } 
        else if (numsW != 0) {
            nums[i] = 1;
            numsW--;
        }
        else
            nums[i] = 2;
    }
}
```

- 我想是由于测试数据太少的原因，此代码提交速度为`0毫秒`
- 之后进行优化，采用一次遍历来实现，有以下思路
  - 遍历数组，遇到`0`放在数组左边，遇到`2`放在数组右边，同时为了`1`位置也是合理的，我们不对原数组进行重赋值，仅对其进行元素交换

**代码：**

```c
void Swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortColors(int* nums, int numsSize) {
    int i = 0, left = 0, right = numsSize - 1;
    while (i <= right) {
        if (nums[i] == 0)
            Swap(&nums[i++], &nums[left++]);
        else if (nums[i] == 2)
            Swap(&nums[i], &nums[right--]);
        else
            i++;
    }
}
```

- 我第一次写的时候，采用的for循环遍历，卡了一组数据`[1,2,0]` ,后来参考了[别人的思路](https://leetcode.com/problems/sort-colors/discuss/166141/C%2B%2B-O(n)-fast-and-neat!)发现，此种方法实现的精髓就在于**`nums[i] == 2`之时进行交换，交换之后 i 值不能增加**

