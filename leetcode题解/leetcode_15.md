### 15. 三数之和（3Sum）

#### 中文题目

给定一个包含 *n* 个整数的数组 `nums`，判断 `nums` 中是否存在三个元素 *a，b，c ，*使得 *a + b + c =* 0 ？找出所有满足条件且不重复的三元组。

**注意：**答案中不可以包含重复的三元组。

```
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

#### 英文题目

Given an array `nums` of *n* integers, are there elements *a*, *b*, *c* in `nums` such that *a* + *b* + *c* = 0? Find all unique triplets in the array which gives the sum of zero.

**Note:**

The solution set must not contain duplicate triplets.

**Example:**

```
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

#### 解法一：

直接暴力求解，三变量，逐个循环，算法时间复杂度大致为$n^3$，超时应该是没有任何问题，所以我并未尝试，后来看网上相关题解，直接暴力的的确会超时

#### 解法二：

既然暴力会直接超时，那么如何优化呢？

—— 排序后再求解如何，排序作为重要且非常常用的算法，确实可以将许多问题变得简单化

选用何种排序？

—— 为了降低时间复杂度，为之后的操作留下空间，所以，选择快排或者归并

**原始思路：**

我刚开始想的是：

- 将两个指针指向数组两边，直至左边大于右边（此用while构成一组循环）

- 再一指针置于左右的中间（此用for 构成一重循环），直至等于`右边-1`

但是在提交过程中遇到了困难，后经 [博客](https://blog.csdn.net/jack_c_monkey/article/details/80469345)提点，发现自己的写法不甚理想，遂改之

**最终通过代码如下：**

```c
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Merge(int a[], int l, int r, int rightEnd, int temp[]) {
    int leftEnd = r-1 ;
    int left = l, tmp = l;

    while (l <= leftEnd && r <= rightEnd){ // 当左右子序列均不空
        if (a[l] > a[r])
            temp[tmp++] = a[r++];
        else
            temp[tmp++] = a[l++];
    }
    while (l <= leftEnd)
        temp[tmp++] = a[l++];
    while (r <= rightEnd)
        temp[tmp++] = a[r++];
    for (int i = left; i < rightEnd + 1; i++)
        a[i] = temp[i];
}


void MergeSort(int a[], int l, int rightEnd, int temp[]) {
    int center;
    if (l < rightEnd) {
        center = (l + rightEnd) / 2;
        MergeSort(a, l, center, temp);
        MergeSort(a, center + 1, rightEnd, temp);
        Merge(a, l, center+1, rightEnd, temp);
    }
}


void Merge_sort(int a[], int n) {
    int* tmpA;
    tmpA = malloc(n * sizeof(int));
    if (tmpA != NULL){
        MergeSort(a, 0, n-1, tmpA);
        free(tmpA);
    } else {
        printf("ERROR");
    }
}


int** threeSum(int* nums, int numsSize, int* returnSize) {
    if (numsSize < 3)
        return NULL;
    int i = 0, j, k, temp, count = 0;
    int** result=(int**)malloc(sizeof(int*)*(numsSize*(numsSize-1)*(numsSize-2))/6);
    Merge_sort(nums, numsSize);
    for (i = 0; i < numsSize; i++){
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i-1])	// 跳过重复负数
            continue;
        j = i+1;
        k = numsSize-1;
        while (j < k){
            temp = nums[i]+nums[j]+nums[k];
            if (temp == 0){
                result[count] = (int*)malloc(sizeof(int)*3);
                result[count][0] = nums[i];
                result[count][1] = nums[j];
                result[count][2] = nums[k];
                count++;
                j++;    k--;
                while (j <k && nums[j] == nums[j-1])	// 跳过重复数字
                    j++;
                while (j < k && nums[k] == nums[k+1])	// 跳过重复数字
                    k--;
            } else if (temp > 0)	// 右边数字过大 
                k--;
            else	// 左边数字过小
                j++;
        }
    }
    
    *returnSize = count;
    return result;
}
```

**代码解释：**

首先前三个函数实现归并排序，`void Merge_sort(int a[], int n)`函数简化函数接口，相关代码实现借鉴 浙江大学慕课——数据结构 

主体函数采用二重循环，时间复杂度接近$n^2$

1. 初始化数据
2. 将数组`nums`从小到大排序
3. 第一重循环为取出所有负数`nums[i]`
4. 第二重循环为从`i+1`开始`numsSize-1`结束，查找是否存在三数之和为0

**代码说明：**

- 注意用指针的指针表示动态数组时的`malloc()`过程

![提交结果](F:\LeetCode题解\week1\图片\LeetCode15.png)