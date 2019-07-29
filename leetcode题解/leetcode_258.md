---
title: leetcode728
data: 2018-12-2 22:51
tag: [leetcode,数学]
---

### 258. 各位相加（Add Digits）

#### 中文题目

给定一个非负整数 `num`，反复将各个位上的数字相加，直到结果为一位数。

**示例:**

```
输入: 38
输出: 2 
解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
```

**进阶:**
你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？

#### 英文题目

Given a non-negative integer `num`, repeatedly add all its digits until the result has only one digit.

**Example:**

```
Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
```

**Follow up:**
Could you do it without any loop/recursion in O(1) runtime?

#### 题目解答

- 题目很简单，直接按照题目说的做就行，所以我写出了代码

**代码：**

```c
int addDigits(int num) {
    int res, tmp = num;
    
    while (tmp > 9) {
        res = 0;
        while (num != 0) {
            res += num % 10;
            num /= 10;
        }
        tmp = res;
        num = res;
    }
    if (res == 0)
        res = num;
    return res;
}
```

因为代码之中采用了二重循环，所以肯定不是很快，提交之后便验证了我的想法

- 我看了提交最快的示例代码，然后发现了这好像是一个我不知道的数学问题
- 听说了**`此题各位相加的结果，等于此数和九的模`**
  - `num = a * 1000 + b * 100 + c * 10 + d`
  - `num = a * 999 + b * 99 + c * 9 + (a + b + c + d)`
  - 所以`num % 9`就相当于`各位之和`，如果取模结果为`0`，说明各位之和为`9`
- 所以就有了如下代码：

**代码：**

```c
int addDigits(int num) {
    if (num == 0) return 0;
    int i = num % 9;
    return i == 0 ? 9:i;
}
```

结论就是，真的很强，数学真的很重要......