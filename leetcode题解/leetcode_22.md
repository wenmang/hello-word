### 22. 括号生成（Generate Parentheses）

#### 中文题目

给出 *n* 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且**有效的**括号组合。

例如，给出 *n* = 3，生成结果为：

```
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

------

#### 英文题目

 Given *n* pairs of parentheses, write a function to generate all combinations of well-formed parentheses. 

 For example, given *n* = 3, a solution set is: 

```
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

------

#### 题目解答

- 寻找所有的合理的括号匹配，也就是回溯的思想
- 此题是在借鉴写出17题之后作为进阶练习准备自己写的，但是，自己写的还是很有问题，所以又抄袭了[代码](https://blog.csdn.net/hahachenchen789/article/details/78021687)

**代码：**

```c
char** result;
void InitResult1(int** res, int* size, int l, int r, char* temp, int index){
    if (l == 0 && r == 0){
        temp[index] = 0;
        res[*size] = (char*)malloc(sizeof(char*)*index);
        strcpy(result[*size], temp);
        (*size)++;
        return;
    }
    if (l > 0) {
        temp[index] = '(';
        InitResult1(res, size, l-1, r, temp, index+1);
    }
    if (r > 0 && l < r) {
        temp[index] = ')';
        InitResult1(res, size, l, r-1, temp, index+1);
    }
}

char** generateParenthesis(int n, int* returnSize) {    // leetcode22
    result = (char**)malloc(sizeof(char*)*10000);
    *returnSize = 0;
    char path[1000] = "";
    if (n == 0)
        return result;

    InitResult1(result, returnSize, n, n, path, 0);

    return result;
}
```

**代码分析：**

- 首先括号分为左右括号，什么时候放左括号是合理的呢？

  `l > 0` 也就是只要还有左括号就能放。。。

- 什么时候放右括号是合理的呢？

  `r > 0 && l < r` 也就是只要放的左括号比右括号少并且还有右括号未放之时

- `l == 0 && r == 0` 也就是左右括号都放完之时，将已完成的括号序列收进 result 数组

- 采用递归方式实现回溯算法，实现题意

- 主函数起到初始化作用