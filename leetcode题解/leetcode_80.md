---
title: leetcode80
data: 2018-12-25 22:20
tag: [leetcode,数组,双指针]
---

### 80. 删除排序数组中的重复项II（Remove Duplicates  from Sorted Array II）

#### 中文题目

给定一个排序数组，你需要在**原地**删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在**原地修改输入数组**并在使用 O(1) 额外空间的条件下完成。

**示例 1:**

```
给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。
```

**示例 2:**

```
给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。
```

---

#### 英文题目

Given a sorted array *nums*, remove the duplicates [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) such that duplicates appeared at most *twice* and return the new length.

Do not allocate extra space for another array, you must do this by **modifying the input array in-place** with O(1) extra memory.

**Example 1:**

```
Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
```

**Example 2:**

```
Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.
```

---

#### 题目解答

- 想要简化操作，我刚开始并未有想法
- 之后看了别人的思路，写出了代码
- 思路如下，将数组从头开始遍历，将开头两个数字不变，之后将比前面数字大的数字收入数组即可，最多收入两个，代码非常简练

**代码：**

```c
int removeDuplicates(int* nums, int numsSize) {
    int count = 0;
    int tmp = nums[0];
    for (int i = 0; i < numsSize; i++)
        if (count < 2 || nums[i] > nums[count-2])
            nums[count++] = nums[i];
    return count;
}
```

