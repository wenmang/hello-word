---
title: leetcode58
data: 2018-12-12 22:58
tag: [leetcode,字符串]
---

### 58. 最后一个单词的长度（Length of Last Word）

#### 中文题目

给定一个仅包含大小写字母和空格 `' '` 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

**说明：**一个单词是指由字母组成，但不包含任何空格的字符串。

**示例:**

```
输入: "Hello World"
输出: 5
```

---

#### 英文题目

Given a string *s* consists of upper/lower-case alphabets and empty space characters `' '`, return the length of last word in the string.

If the last word does not exist, return 0.

**Note:** A word is defined as a character sequence consists of non-space characters only.

**Example:**

```
Input: "Hello World"
Output: 5
```

---

#### 题目解答

- 简单题，但是正确率极低，所以应该不同寻常
- 开始写之后，发现本题的坑点在于多个空格的情况，以及多个空格后有没有字符

我的代码如下：

**代码：**

```c
int lengthOfLastWord(char* s) {
    int count = 0, flag = 0, i = 0;
    while (s[i] != '\0') {
        if (s[i] == ' '){
            flag = 1;
            i++;
            continue;
        }
        if (flag == 1) {
            count = 1;
            flag = 0;
        }
        else if (s[i] != ' ')
            count++;
        i++;
    }
    return count;
}
```

- 本来之前是没有`flag`的，后来提交失败后，添加了`flag`来处理多空格情况
- 也就是主要思路为跳过所有多余的空格，如果是字符，`count`归`0`,否则返回上个字符串的长度

我提交了两次，一次最快，一次不是，最快的示例代码写的比我的优雅

**代码：**

```c
int lengthOfLastWord(char* s) {
    int i=0, j=0;
    int len = strlen(s);
    
    for(i=len-1,j=0; i>=0; i--) {
        if(s[i] != ' '){
            while(s[i] != ' ' && i>=0){
                j++;
                i--;
            }
            break;
        }
    }
    return j;
}
```

- 从后往前数，而且代码也写得很优雅，缩短了无用的遍历