### 33.  搜索旋转排序数组（Search in Rotated Sorted Array）

#### 中文题目

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 `[0,1,2,4,5,6,7]` 可能变为 `[4,5,6,7,0,1,2]` )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 `-1` 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 *O*(log *n*) 级别。

**示例 1:**

```
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
```

**示例 2:**

```
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
```

---

#### 英文题目

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]`).

You are given a target value to search. If found in the array return its index, otherwise return `-1`.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of *O*(log *n*).

**Example 1:**

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

**Example 2:**

```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

---

#### 题目解答

**感受：**

这道题可以说是真真实实验证了自己是个菜鸡，刚开始死活想不到解法，没有思路；之后有了思路却死活写不出代码。。。

**思路：**

这道题要缩短搜索时长，毫无疑问，采用二分查找是必须的，而**怎样来二分查找**呢？这便是本题的难点，经过好长时间的思考后我想到了循环数组，显然，以循环数组的思想来解决是最简单的

循环数组是一种概念，利用数学知识将数组头尾打通的思想，于此不再赘述

那么如何以代码实现呢？

**代码：**

```c
int search(int* nums, int numsSize, int target) {   // LeetCode33
    int left = 0, right = numsSize - 1, mid, realMid, temp;
    
    while (left < right) {  // Find the 0
        mid = left + (right - left)/2;
        if (nums[mid] < nums[right]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    temp = left;
    left = 0;
    right = numsSize - 1;

    while (left <= right) { // Using Ring array to resolve
        mid = left + (right - left)/2;
        realMid = (mid + temp) % numsSize;
        if (nums[realMid] == target)
            return realMid;
        else if (nums[realMid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
```

**注：**

1. 此代码几乎完全抄了最快示例代码
2. `mid = left + (right - left)/2;`此为防止`left + right`过大，超出`int`范围

**代码分析：**

- 需要采用二分查找，必须先确定已排序数组的中心位置，而经过旋转之后，直接找到的中心位置为假中心
- 确定数组的**真中心**：也就是数组的真0点（该旋转数组中最小值位置）加数组的一半就是真的中心
- 确定**真0点**：肯定还是二分查找，否则就超时了。。。即第一个`while`循环（我在此处卡了好久）
- 确定真中心后直接按照正常的二分查找写代码便是

**提交结果：**

![](F:\LeetCode题解\week1\图片\leetcode33.png)