---
title: leetcode67
data: 2018-12-4 21:46
tag: [leetcode,回溯算法]
---

### 46. 全排列（Add Binary）

#### 中文题目

给定一个**没有重复**数字的序列，返回其所有可能的全排列。

**示例:**

```
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

---

#### 英文题目

Given a collection of **distinct** integers, return all possible permutations.

**Example:**

```
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

---

#### 题目解答

- 本题的首先一眼就能看出是回溯算法，但是因为好奇心，我搜了一下，发现了[维基百科](https://zh.wikipedia.org/wiki/%E5%85%A8%E6%8E%92%E5%88%97%E7%94%9F%E6%88%90%E7%AE%97%E6%B3%95)的说明
- 对于第一个字典序算法，我开始了疯狂的实现，结果还是没实现出来，描述不得不说是太模糊了
- 然后还是最后采用了回溯的方式来实现

```c
void Swap (int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void DFS(int *nums, int size, int start, int **results, int *count){
    if (start == size){
        results[*count] = malloc(size * sizeof(int*));
        memcpy(results[*count], nums, size * sizeof(int));
        (*count)++;
    } else {
        for (int i = start; i < size; ++i) {
            Swap(nums + start, nums + i);
            DFS(nums, size, start + 1, results, count);
            Swap(nums + start, nums + i);
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize) {
    int** res = malloc(5000 * sizeof(int*));
    *returnSize = 0;
    DFS(nums, numsSize, 0, res, returnSize);
    
    return res;
}
```

- 递归直到数组的元素全进入排列
- 否则就交换排列元素的数字`Swap(nums + start, nums + i);`
- 主函数中只对其进行初始化