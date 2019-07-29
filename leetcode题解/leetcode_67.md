---
title: leetcode67
data: 2018-12-4 21:46
tag: [leetcode,数学]
---

### 67. 二进制求和（Add Binary）

#### 中文题目

给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为**非空**字符串且只包含数字 `1` 和 `0`。

**示例 1:**

```
输入: a = "11", b = "1"
输出: "100"
```

**示例 2:**

```
输入: a = "1010", b = "1011"
输出: "10101"
```

------

#### 英文题目

Given two binary strings, return their sum (also a binary string).

The input strings are both **non-empty** and contains only characters `1` or `0`.

**Example 1:**

```
Input: a = "11", b = "1"
Output: "100"
```

**Example 2:**

```c
Input: a = "1010", b = "1011"
Output: "10101"
```

---

####  题目解答：

- 此题的解决方式应该是比较常规的，也就是模拟加法运算的步骤
- 本体的重点和所有加法问题的重点相同，就是进位的处理
- 本体对于C语言而言还有一个重点就是字符数组内存空间的开辟

**代码：**

```c
char* addBinary(char* a, char* b) {
    int tmp = 0;
    int lena = strlen(a);
    int lenb = strlen(b);
    int len = lena > lenb ? lena : lenb;
    char* c = malloc((len + 2)*sizeof(char*));
    c[len+1] = '\0';
    while(lena != 0 || lenb != 0) {
        if (lena != 0 && lenb != 0) {
            if ((a[lena-1] - '0') + (b[lenb-1] - '0') + tmp == 3) {
                c[len] = '1';
                tmp = 1;
            }
            else if ((a[lena-1] - '0') + (b[lenb-1] - '0') + tmp == 2) {
                c[len] = '0';
                tmp = 1;
            } else {
                c[len] = (a[lena-1] - '0') + (b[lenb-1] - '0') + tmp + '0';
                tmp = 0;
            }
            lena--, lenb--, len--;
        }
        else if (lena != 0) {
            if ((a[lena-1] - '0') + tmp == 2) {
                c[len] = '0';
                tmp = 1;
            } else {
                c[len] = (a[lena-1] - '0') + tmp + '0';
                tmp = 0;
            }
            lena--, len--;
        }
        else if (lenb != 0) {
            if ((b[lenb-1] - '0') + tmp == 2) {
                c[len] = '0';
                tmp = 1;
            } else {
                c[len] = (b[lenb-1] - '0') + tmp + '0';
                tmp = 0;
            }
            lenb--, len--;
        }
    }
    if (tmp == 1){
        c[len] = '1';
        return c;
    } else {
        return c+1;
    }
}
```

- 申请空间开辟 —— 注意考虑加入`\0`
- 加法模拟：从末位相加，`tmp` 为进位，初始化为0
  - 需要说明的是在三个数相加的时候，`(a[lena-1] - '0') + (b[lenb-1] - '0') + tmp`最大可能会产生`3`,我第一次提交之时未考虑到，未作处理
  - 之后两个数相加就不存在`3` 的情况了，所以不再处理
- 刚开始下午刚睡醒后花了很长事件没搞出来，晚上回来后不久就写出来了，效率真的重要！！！