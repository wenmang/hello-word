### LeetCode 1021. 删除最外层的括号

#### 题目描述

有效括号字符串为空 `("")、"(" + A + ")" `或 `A + B`，其中 `A` 和 `B` 都是有效的括号字符串，`+` 代表字符串的连接。例如，`""，"()"，"(())()" 和 "(()(()))" ` 都是有效的括号字符串。

如果有效字符串 `S` 非空，且不存在将其拆分为 `S = A+B` 的方法，我们称其为原语（primitive），其中 `A` 和 `B` 都是非空有效括号字符串。

给出一个非空有效字符串 `S`，考虑将其进行原语化分解，使得：`S = P_1 + P_2 + ... + P_k`，其中 `P_i` 是有效括号字符串原语。

对 `S` 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 `S` 。

 

示例 1：

```
输入："(()())(())"
输出："()()()"
解释：
输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
```

示例 2：

```
输入："(()())(())(()(()))"
输出："()()()()(())"
解释：
输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
删除每隔部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
```

示例 3：

```
输入："()()"
输出：""
解释：
输入字符串为 "()()"，原语化分解得到 "()" + "()"，
删除每个部分中的最外层括号后得到 "" + "" = ""。
```

提示：

1. `S.length <= 10000`
2. `S[i]` 为 `"("` 或 `")"`
3. `S` 是一个有效括号字符串

#### 题目解答

**Code1：**

因为本题标签是 `栈` ，所以我就考虑了常规的栈的解法，但是在写代码的时候，发现在剥除外括号的时候有困难，然后用了标记首尾，取中间子串的方式， `java` 代码如下：

```java
class Solution {
    public String removeOuterParentheses(String S) {
        Stack<Character> stack = new Stack<Character>();
        String ret = new String();
        int len = S.length();
        
        int start = 0;
        boolean flag = true;
        for (int i = 0; i < len; i++) {
            if (S.charAt(i) == '(') {
                stack.push('(');
                if (flag) {
                    start = i+1;
                    flag = false;
                }
            } else if (S.charAt(i) == ')') {
                stack.pop();
                if (stack.empty()) {
                    ret += S.substring(start, i);
                    flag = true;
                }
            }
        }
        return ret;
    }
}
```

**Code2:**

之后看了别人的题解，思路就是类似双指针的想法，跳过外括号：

```java
class Solution {
    public String removeOuterParentheses(String S) {
        char[] s = S.toCharArray();
        String ret = new String();
        int len = S.length();
        
        int left = 1, right = 0;
        for (int i = 1; i < len; i++) {
            if (s[i] == '(')    
                left++;
            else
                right++;
            if (left != right)
                ret += s[i];
            else {
                i++;
                left = 1;
                right = 0;
            }
        }
        return ret;
    }
}
```

- `left` 超前 `right` 一个身位，并且循环从一开始，当二者相等之时位置刚好会处于最外层的右括号，即 `)`
- 此时，`i++` 然后，将 `left` 和 `right` 还原，此时就相当于刚开始时候的场景，循环往复。

但是这个方法的提交之后的效率不同寻常地低，不知道是为啥。

**Code3：**

然后我看了 `2ms` 的示例代码，发现其使用了 `StringBuilder` ，于是我看了文档，其上说，此虽然线程不安全，但是速度快。于是我照抄了代码，提交了一遍，`4ms`，果然快：

```java
class Solution {
    public String removeOuterParentheses(String S) {
        StringBuilder sb = new StringBuilder();
        int count = 0;
        
        for (char c : S.toCharArray()) {
            if (c == '(') {
                if (count > 0)
                    sb.append(c);
                count++;
            } else {
                count--;
                if (count > 0)
                    sb.append(c);
            }
        }
        return sb.toString();
    }
}
```

- 这种方法其实和第二种类似，不过将之缩为了一个变量来进行控制，左加右减
- 注意 `count` 加减的时机，一个是在后面，一个是在前面。