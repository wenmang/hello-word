### 31. 下一个排列（Next Permutation）

#### 中文题目

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须**原地**修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 `1,2,3` → `1,3,2`
 `3,2,1` → `1,2,3`
 `1,1,5` → `1,5,1`

------

#### 英文题目

Implement **next permutation**, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be **in-place** and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

`1,2,3` → `1,3,2`
`3,2,1` → `1,2,3`
`1,1,5` → `1,5,1`

------

#### 解题方法

首先要需要清晰地理解下一个排列的定义，我刚开始也是由于没有透彻理解其定义以至于初代代码出了许多问题

之后便有了一个大体的思路：

- 首先从后往前遍历，若遇到某数字比前一个数字大，则停止遍历（此时该数字后面的数字均小于该数字）
- 寻找数组中该数字后面的数字是否有比该数字前一个数字大的，如有则直接交换，如无就交换该数字与其前一个数字
- 顺序排列交换之后该数后面的数字
- 若该数列直接为逆序排列，将其转换为顺序排列

**代码：**

```c
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void nextPermutation(int* nums, int numsSize) {
    int i, j, temp;
    for (i = numsSize-1; i > 0; i--)
        if (nums[i] > nums[i-1]) {	// 第一步
            /* 第二步 */
            j = numsSize-1;
            while (nums[j] <= nums[i-1])
                j--;
            swap(&nums[j], &nums[i-1]);
            /* 第三步 */
            temp = numsSize-1;
            for (j = i; j < temp; ++j) {
                swap(&nums[j], &nums[temp]);
                temp--;
            }
            return;
        }
	/* 第四步 */
    temp = numsSize-1;
    for (j = 0; j < temp; ++j) {
        swap(&nums[j], &nums[temp]);
        temp--;
    }
}
```

**代码分析：**

与一致思路，无甚可分析，注意交换函数即可

**提交结果：**

![leetcode31](F:\LeetCode题解\week1\图片\leetcode31.png)

