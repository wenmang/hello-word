---
title: leetcode268
data: 2018-12-11 22:32
tag: [leetcode,数学]
---

### 268. 缺失数字（Missing Number）

#### 中文题目


给定一个包含 `0, 1, 2, ..., n` 中 *n* 个数的序列，找出 0 .. *n* 中没有出现在序列中的那个数。

**示例 1:**

```
输入: [3,0,1]
输出: 2
```

**示例 2:**

```
输入: [9,6,4,2,3,5,7,0,1]
输出: 8
```

**说明:**
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

#### 英文题目

Given an array containing *n* distinct numbers taken from `0, 1, 2, ..., n`, find the one that is missing from the array.

**Example 1:**

```
Input: [3,0,1]
Output: 2
```

**Example 2:**

```
Input: [9,6,4,2,3,5,7,0,1]
Output: 8
```

**Note**:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

#### 题目解答

- 求数组中一楼的方法，最暴力的方法当然是，二重循环查找了

**代码：**

```c
int missingNumber(int* nums, int numsSize) {
    int i, count = -1;
    for (i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (i == nums[j])
                count = i;
        }
        if (count == -1)
            return i;
        count = -1;
    }
    return i;
}
```

`432毫秒` 慢的让人吃惊

- 之后发现此题显而易见是一个利用标记数组的典型例子

**代码：**

```c
int missingNumber(int* nums, int numsSize) {
    int i;
    bool* flag = malloc(sizeof(int)*(numsSize+1));
    memset(flag, 0, numsSize);
    for (i = 0; i < numsSize; i++)
        flag[nums[i]] = 1;
    for (i = 0; i < numsSize; i++)
        if (flag[i] == 0)
            return i;
    return i;
}
```

运行了好多遍，竟然都是`8ms`，不是最快的，让人很烦

- 于是看了下最快的代码

**代码：**

```c
int missingNumber(int* nums, int numsSize) {
    int *flag=(int*)calloc(numsSize,sizeof(int));  
    for(int i = 0; i<=numsSize-1;i++) {
        if(nums[i]<numsSize)
             flag[nums[i]]=1;   
    }
    for(int k =0;k<=numsSize-1;k++){   
        if(flag[k]!=1)        
            return k;
    }
    return numsSize;
}
```

思路一致，但没有`memset()`,难道是`memset()`拖累了我的代码？

不过我觉得还是`memset()`一下更为保险