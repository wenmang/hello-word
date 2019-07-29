### 34. 在排序数组中查找元素的第一个和最后一个位置（Find First and Last Position of Element in Sorted Array）

#### 中文题目

给定一个按照升序排列的整数数组 `nums`，和一个目标值 `target`。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 *O*(log *n*) 级别。

如果数组中不存在目标值，返回 `[-1, -1]`。

**示例 1:**

```
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
```

**示例 2:**

```
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
```

---

#### 英文题目

Given an array of integers `nums` sorted in ascending order, find the starting and ending position of a given `target` value.

Your algorithm's runtime complexity must be in the order of *O*(log *n*).

If the target is not found in the array, return `[-1, -1]`.

**Example 1:**

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

**Example 2:**

```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

---

#### 题目解答：

**感受：**

此题我写的代码运行速度出乎意料

**思路：**

利用二分查找首先找到一个数组中的`target`,然后向两边扩展得出范围

**代码：**

```c
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result;
    result = (int*) malloc(sizeof(int*)*2);
    result[0] = -1;
    result[1] = -1;
    *returnSize = 2;
    
    int left, right, mid, count = 0;
    left = 0;
    right = numsSize - 1;
    while (left <= right){
        mid = left + (right-left)/2;
        if (nums[mid] == target) {
            count++;
            int min = mid;
            int max = mid;
            while (nums[--min] == target);
            while (nums[++max] == target);
            result[0] = (min + 1) > 0 ? (min + 1) : 0;
            result[1] = (max - 1) < (numsSize-1) ? (max - 1) : (numsSize-1);
            return result;
        }
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return result;
}
```

**代码分析：**

```c
result[0] = (min + 1) > 0 ? (min + 1) : 0;
result[1] = (max - 1) < (numsSize-1) ? (max - 1) : (numsSize-1);
```

为了防止其值为-1

此代码的速度主要建立在`target`重复次数少的基础上，一旦重复次数过多，速度甚至没有直接遍历来的快

**提交结果：**

我还特意提交了两次，都是如此，估计是钻了数据的空子

![leetcode34](F:\LeetCode题解\week1\图片\leetcode34.png)

