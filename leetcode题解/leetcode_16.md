### 16. 最接近的三数之和（3Sum Closest）

#### 中文题目

给定一个包括 *n* 个整数的数组 `nums` 和 一个目标值 `target`。找出 `nums` 中的三个整数，使得它们的和与 `target` 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

```
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
```

#### 英文题目

Given an array `nums` of *n* integers and an integer `target`, find three integers in `nums` such that the sum is closest to `target`. Return the sum of the three integers. You may assume that each input would have exactly one solution.

**Example:**

```
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

#### 解法一：

此题与**15**题颇为相似，做过了15题之后面对此题，我想，二者的解题思路应该一致，即排序后再进行匹配寻找，已知了较为快速的解法，我刚开始索性就先采用了暴力求解的策略，结果。。。过了。。。

**代码：**

```c
int threeSumClosest(int* nums, int numsSize, int target) {
    int i, j, k, sum, max = 62233;
    for (i = 0; i < numsSize-2; i++) {
        for (j = i + 1; j < numsSize-1; j++) {
            for (k = j + 1; k < numsSize; k++) {
                if (abs(nums[i] + nums[j] + nums[k] - target) < max) {
                    max = abs(nums[i] + nums[j] + nums[k] - target);
                    sum = nums[i] + nums[j] + nums[k];
                }
            }
        }
    }
    return sum;
}
```

直接采用三循环的暴力求解，让人意外的是，通过了。。。虽然用时感人

![16.1](F:\LeetCode题解\week1\图片\leetcode16.1.png)

#### 解法二：

同第十五题，先进行一次排序，之后再进行处理

**代码：**

```c
void Merge(int a[], int l, int r, int rightEnd, int temp[]){
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


void Merge_sort(int a[], int n){
    int* tmpA;
    tmpA = malloc(n * sizeof(int));
    if (tmpA != NULL){
        MergeSort(a, 0, n-1, tmpA);
        free(tmpA);
    } else {
        printf("ERROR");
    }
}


int threeSumClosest(int* nums, int numsSize, int target) {
    int i = 0, j, k, temp = 65533, sum;
    Merge_sort(nums, numsSize);
    for (i = 0; i < numsSize; i++){
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        j = i+1;
        k = numsSize-1;
        while (j < k){
            if (abs(nums[i]+nums[j]+nums[k]-target) < temp){
                temp = abs(nums[i]+nums[j]+nums[k]-target);
                sum = nums[i] + nums[j] + nums[k];
                if (nums[i]+nums[j]+nums[k] > target) {	// 之和过大 k--
                    k--;
                    continue;
                }
                else if (nums[i]+nums[j]+nums[k] < target) {// 之和过小 j++
                    j++;
                    continue;
                }
                else	// 等于直接返回即可
                    return sum;
            }
            if (nums[i]+nums[j]+nums[k] > target)// 之和过大 k--
                k--;
            else if (nums[i]+nums[j]+nums[k] < target)// 之和过小 j++
                j++;
        }
    }
    return sum;
}
```

**代码说明：**

基本原理和15题相同，只是在判断之时略有改动，所以不再赘述

改进之后时间也算是快了许多，如下：

![16.2](F:\LeetCode题解\week1\图片\leetcode16.2.png)