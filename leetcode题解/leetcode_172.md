### 172. 阶乘后的零（Factorial Trailing Zeroes）

#### 中文题目

给定一个整数 *n*，返回 *n*! 结果尾数中零的数量。

**示例 1:**

```
输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。
```

**示例 2:**

```
输入: 5
输出: 1
解释: 5! = 120, 尾数中有 1 个零.
```

**说明:** 你算法的时间复杂度应为 *O*(log *n*) 。

---

#### 英文题目

Given an integer *n*, return the number of trailing zeroes in *n*!.

**Example 1:**

```
Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
```

**Example 2:**

```
Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
```

**Note:** Your solution should be in logarithmic time complexity.

---

#### 解题方法

- 我首先想的是直接判断，遇到个位有0时除以10，但是提交的时候很快就爆炸了，样例到了16就爆炸了！！！

**代码：**

```c
int trailingZeroes(int n) {
    int count = 0;
    int sum = 1;
    while(n != 0) {
        sum *= n;
        if (sum % 10 == 0) {
            count++;
            sum /= 10;
        }
        n--;
    }
    return count;
}
```

- 之后看了个[题解](https://blog.csdn.net/TommyZht/article/details/46309563)。。。统计2和5的个数即可达到目的
- 因为产生10的条件为偶数与5的乘积，又因为偶数出现次数肯定是足够的，所以只需要统计5倍数的数字个数即可
- 直接统计5的倍数的数字的个数即可，但是 25 50 75 100 产生两个0，也就是每隔25个数就会多出1个0，隔125也多出1个0

所以有如下算法：

**代码：**

```c
int trailingZeroes(int n) {
    int res = 0;
    while(n) {
        res += n/5;
        n /= 5;
    }
    return res;
}
```

**注：** 运行时间 8ms，不服的我看了4ms的代码

**代码：**

```c
int trailingZeroes(int n) {
    int ans=0;
    while(n)
        ans+=n/=5;
    return ans;
}
```

好吧！我服了