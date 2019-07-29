---
title: leetcode81
data: 2018-12-26 22:26
tag: [leetcode,数组,二分查找]
---

### 81. 搜索旋转排序数组II（Search in Rotated Sorted Array II）

#### 中文题目

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 `[0,0,1,2,2,5,6]` 可能变为 `[2,5,6,0,0,1,2]` )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 `true`，否则返回 `false`。

**示例 1:**

```
输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
```

**示例 2:**

```
输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
```

**进阶:**

- 这是 [搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/) 的延伸题目，本题中的 `nums`  可能包含重复元素。
- 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

#### 英文题目

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `[0,0,1,2,2,5,6]` might become `[2,5,6,0,0,1,2]`).

You are given a target value to search. If found in the array return `true`, otherwise return `false`.

**Example 1:**

```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

**Example 2:**

```
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

**Follow up:**

- This is a follow up problem to [Search in Rotated Sorted Array](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/), where `nums` may contain duplicates.
- Would this affect the run-time complexity? How and why?

#### 题目解答

- 很皮的我尝试了一下直接遍历，也就是直接查找，发现速度还不赖，可能也有数据集太少的缘故吧

**代码：**

```c
bool search(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++)
        if (nums[i] == target)
            return true;
    return false;
}
```

- 发现最快示例代码是。。。直接查找

- 之后学了一波二分查找的写法
- 旋转之后，数组应当是一个梯形结构，所以会对其进行特殊的二分查找，通过判断中间数字小于左边还是大于左边将其分为两部分进行处理
- 如果中间数字大于左边，则说明此时左边是完全有序的，所以，将中间值和目标值作比较
  - 如果大于目标值并且左边数小于等于目标值，则就在此范围内查找，将右边界移到`mid-1`
  - 否则说明数不在此范围，于是跳出此范围，将左边界移动到`mid+1`
- 同理，如果中间数字不大于左边，于是说明右边是完全有序的
  - 判断，如果中间值小于目标值，并且右边界值大于等于目标值，将左边界移动到`mid+1`
  - 否则，说明不在此范围，将右边界移动到`mid-1`
- 利用此思路之后，对于重复数字，是会影响查找的效果的，所以将重复数字跳过
- 其余处理同二分查找

**代码：**

```c
bool search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    
    while (left <= right) {
        int mid = left + (right-left)/2;
        if (nums[mid] == target)
            return true;
        if (nums[mid] == nums[left])
            left++;
        else if (nums[mid] > nums[left]) {
            if (nums[mid] > target && nums[left] <= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        else {
            if (nums[mid] < target && nums[right] >= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}
```

- 但是提交时间与直接查找差不多。。。