### 17. 电话号码的字母组合（ Letter Combinations of a Phone Number）

#### 中文题目

给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

![img](http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

**示例:**

```
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
```

**说明:**
 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

#### 英文题目

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![img](http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

**Example:**

```
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
```

**Note:**

Although the above answer is in lexicographical order, your answer could be in any order you want.

#### 题目解答

- 首先，此题的标签是`回溯`，而我还未学过此算法，因此特地上网查了一下[回溯算法](https://zh.wikipedia.org/wiki/%E5%9B%9E%E6%BA%AF%E6%B3%95)
- 然后，我仍然没有啥思路，所以我不要脸地直接看了题解

**代码：**

```c
char *map[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
char** result;
int size;

int InitResult(char* digits, int len, int index, char path[]) {
    if (index == len) {
        path[index] = '\0';
        char* temp = (char*)malloc(sizeof(char*)*index);
        strcpy(temp, path);
        result[size++] = temp;
    } else {
        for (int i = 0; i < strlen(map[digits[index] -'2']); ++i) {
            path[index] = map[digits[index] - '2'][i];
            InitResult(digits, len, index+1, path);
        }
    }
    return 1;
}

char** letterCombinations(char* digits, int* returnSize) {  //leetCode17
    int len = strlen(digits);
    result = (char**)malloc(sizeof(char*)*10000);
    size = 0;
    *returnSize = size;
    if (len == 0)
        return result;
    
    char path[10000];
    InitResult(digits, len, 0, path);
    
    *returnSize = size;
    return result;
}
```

**代码分析：**

- 题外话，递归是真的不好想出来，也不是很好写。。。
- `InitResult()`函数中，传入参数对应分别为 数字数组 数字数组的长度 标记 临时数组
- 代码理解很简单，传入之后就开始递归求解，将所有的字母组合保存到`result`数组中
- `letterCombinations()` 函数只做了初始化和简单的处理

**代码理解：**

重点在递归的求解，也就是`InitResult()`函数