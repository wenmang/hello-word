---
title: leetcode69
data: 2018-12-1 22:54
tag: leetcode
---

### 69. x 的平方根（ Sqrt(x) ）

#### 中文题目

实现 `int sqrt(int x)` 函数。

计算并返回 *x* 的平方根，其中 *x* 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

**示例 1:**

```
输入: 4
输出: 2
```

**示例 2:**

```
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
```

#### 英文题目

Implement `int sqrt(int x)`.

Compute and return the square root of *x*, where *x* is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

**Example 1:**

```
Input: 4
Output: 2
```

**Example 2:**

```
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
```

#### 题目解答

- 我的思路是直接暴力寻找，但是过程中发现在数据比较大的时候就会超时，所以又加了个判断，防止由于数据溢出带来的死循环

**代码：**

```c
int mySqrt(int x) {
    if (x >= 2147395600)
        return 46340;
    int i = 1;
    for (; i*i < x; i++);
    return i*i == x ? i:i-1;
}
```

提交之后不出所料，效率极低，又看了其他更优秀的解答

- 用时排名第一的是个直接调用库函数的解。。。服气
- 第二位的解答，为了溢出产生的错误采取了和我相同的方法，但是寻找解的过程，只能说二分法运用的很是熟练

**代码：**

```c
#define AnsMaxValue 46340
#define AnsMinValue 0

int mySqrt(int x) {
    int nowh, nowl, nown;
    if(x >= 2147395600)
        return 46340;
    if(x < 1)
        return 0;
    nowh = AnsMaxValue;
    nown = 23170;
    nowl = AnsMinValue;
    while(nowh-nowl > 1) {
        if(nown*nown > x)
            nowh = nown;
        else
            nowl = nown;
        nown = nowh + nowl;
        nown = nown>>1;
    }
    return nowl;
}
```

- 既然已知了`int`类型的数字开方所能到达的最大数字为`46340`，所以最大设`46340`,最小设`0`
- 然后利用类似二分查找的方式开始寻找底
- 其余没啥说的，佩服！