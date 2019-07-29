---
title: leetcode728
data: 2018-12-2 22:51
tag: [leetcode,数学]
---

### 728. 自除数（Self Dividing Numbers）

####  中文题目

*自除数* 是指可以被它包含的每一位数除尽的数。

例如，128 是一个自除数，因为 `128 % 1 == 0`，`128 % 2 == 0`，`128 % 8 == 0`。

还有，自除数不允许包含 0 。

给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。

**示例 1：**

```
输入： 
上边界left = 1, 下边界right = 22
输出： [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
```

**注意：**

- 每个输入参数的边界满足 `1 <= left <= right <= 10000`。

#### 英文题目

 A *self-dividing number* is a number that is divisible by every digit it contains. 

 For example, 128 is a self-dividing number because `128 % 1 == 0`, `128 % 2 == 0`, and `128 % 8 == 0`. 

 Also, a self-dividing number is not allowed to contain the digit zero. 

 Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible. 

**Example 1:**

```
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
```



**Note:** 

The boundaries of each input argument are `1 <= left <= right <= 10000`.

#### 题目解答

- 此题的特点就是需要的变量比较多。。。
- 我的思路是直接暴力判断，因为数量并不很大，从`left` 到`right`之间的数字依次进行判断其是否属于自除数
- 在此过程中的难点也是需要注意的点在于 判断是否能够整除之时不让`0`做除数

**代码：**

```c
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int j = 0, count = 0;
    int* res;
    res = (int*)malloc(sizeof(int*)*(right - left));
    for (int i = left; i <= right; i++) {
        int tmp = i, flag = 1;
        int k = i, l = k;
        while(k != 0) {
            l = k % 10;
            if (l != 0) {
                if (tmp % l != 0) {
                    flag = 0;
                    break;
                }
            } else {
                flag = 0;
                break;
            }
            k /= 10;
        }
        if (flag == 1) {
            res[j++] = tmp;
            count++;
        }
    }
    *returnSize = count;
    return res;
}
```

- 代码如上，既让其在循环之时即时跳出循环，也不进行漏判

提交之后，由于是打败了`100%`，我只点了对应的示例代码，发现其比我还长，因此我并未细看