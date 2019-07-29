---
title: leetcode268
data: 2018-12-11 22:32
tag: [leetcode,数学]
---

### 942. 增减字符串匹配（DI String Match）

#### 中文题目

给定只含 `"I"`（增大）或 `"D"`（减小）的字符串 `S` ，令 `N = S.length`。

返回 `[0, 1, ..., N]` 的任意排列 `A` 使得对于所有 `i = 0, ..., N-1`，都有：

- 如果 `S[i] == "I"`，那么 `A[i] < A[i+1]`
- 如果 `S[i] == "D"`，那么 `A[i] > A[i+1]`

 

**示例 1：**

```
输出："IDID"
输出：[0,4,1,3,2]
```

**示例 2：**

```
输出："III"
输出：[0,1,2,3]
```

**示例 3：**

```
输出："DDI"
输出：[3,2,0,1]
```

 

**提示：**

1. `1 <= S.length <= 1000`
2. `S` 只包含字符 `"I"` 或 `"D"`。

#### 英文题目

Given a string `S` that **only** contains "I" (increase) or "D" (decrease), let `N = S.length`.

Return **any** permutation `A` of `[0, 1, ..., N]` such that for all `i = 0, ..., N-1`:

- If `S[i] == "I"`, then `A[i] < A[i+1]`
- If `S[i] == "D"`, then `A[i] > A[i+1]`

 

**Example 1:**

```
Input: "IDID"
Output: [0,4,1,3,2]
```

**Example 2:**

```
Input: "III"
Output: [0,1,2,3]
```

**Example 3:**

```
Input: "DDI"
Output: [3,2,0,1]
```

 

**Note:**

1. `1 <= S.length <= 10000`
2. `S` only contains characters `"I"` or `"D"`.

#### 题目解答

```
I D I D
0 4 1 3 2
```

- 刚开始我没找出门道，意味这个题很难，后来大概搜了一下，发现是有规律的
- I 由从左到右小到大排列，D从左到右由大到小排列

所以很快地写出了代码：

**代码：**

```c
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* S, int* returnSize) {
    int lenS = strlen(S);
    *returnSize = lenS + 1;
    int i, min = 0, max = lenS;
    int* res = (int*)malloc(sizeof(int)*(lenS+1));
    for (i = 0; i < lenS; i++){
        if (S[i] == 'I')
            res[i] = min++;
        else if (S[i] == 'D')
            res[i] = max--;
    }
    res[i] = min;
    return res;
}
```

- 代码和最快的示例代码差不多，不知道为啥速度达不到，权当评测系统的锅吧