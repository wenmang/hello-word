---
title: leetcode55
data: 2018-12-15 13:59
tag: [leetcode,贪心,数组]
---

### 55. 跳跃游戏（Jump Game）

#### 中文题目

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

**示例 1:**

```
输入: [2,3,1,1,4]
输出: true
解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
```

**示例 2:**

```
输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
```

---

#### 英文题目

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

**Example 1:**

```
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
```

------

#### 题目解答

- 看到题目标签有贪心时，我就想跑，因为没学，但是发现这题用我的笨办法也能写
- 首先知道，在数组中所有元素均不为0时，绝对不会出现跳不出的情况
- 有元素为0时，0元素左边的元素如果取最大值都跳不过0，一定会到0这个元素，那么就跳不出去了
- 处理特殊情况，首位为0的数组

**代码：**

```c
bool canJump(int* nums, int numsSize) {
    if (nums[0] == 0) {
        if (numsSize == 1)
            return true;
        else
            return false;
    }
    int a[100], count = 0;
    memset(a, -1, sizeof(a));
    for (int i = 0; i < numsSize-1; i++)
        if (nums[i] == 0)
            a[count++] = i;
    if (a[0] == -1)
        return true;
    else
        for (int i = 0; a[i] != -1; i++) {
            int tmp = 0;
            while (tmp < a[i] && nums[tmp] + tmp <= a[i]) {
                if (tmp == a[i]-1)
                    return false;
                else
                    tmp++;
            }
        }
    return true;
}
```

提交之后果然速度奇慢。。。

