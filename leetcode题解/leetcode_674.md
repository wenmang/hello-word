### LeetCode 674. 回文子串

#### 题目描述

给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

**示例 1:**

```
输入: "abc"
输出: 3
解释: 三个回文子串: "a", "b", "c".
```

**示例 2:**

```
输入: "aaa"
输出: 6
说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
```

注意:

1. 输入的字符串长度不会超过1000。

#### 题目解答

回文子串相关问题我觉得都可以用中心扩展法来写，虽然可能效率不如马拉车，但是胜在代码简洁好写，`java` 代码如下：

```java
class Solution {
    int count = 0;
    public int countSubstrings(String s) {
        for (int i = 0; i < s.length(); i++) {
            helper(s, i, i);	// 判断奇数回文子串个数
            helper(s, i, i+1);	// 判断偶数回文子串个数
        }
        return count;
    }
    
    private void helper(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left--) == s.charAt(right++))
            count++;
    }
}
```

- 辅助方法，用于判断以`i` 为中心的字符串是不是回文，是便加一，同时向两边扩展。