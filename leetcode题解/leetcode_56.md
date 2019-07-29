---
title: leetcode56
data: 2018-12-15 16:54
tag: [leetcode,排序,数组]
---

### 55. 合并区间（Merge Intervals）

#### 中文题目

给出一个区间的集合，请合并所有重叠的区间。

**示例 1:**

```
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```

**示例 2:**

```
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
```

---

#### 英文题目

Given a collection of intervals, merge all overlapping intervals.

**Example 1:**

```
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

**Example 2:**

```
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

---

#### 题目解答

- 首先我抱着侥幸的心理，没有排序，事实证明行不通
- 排序后，大致思路就是将前者`end`大于 后者`start`的两个数，进行处理后，赋值给结果数组
- 然后我就黏黏糊糊写了一堆

**代码：**

```c
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    int i, j;
    struct Interval* res = (struct Interval*)malloc(intervalsSize * sizeof(struct Interval));
    // Insertion Sort
    for (i = 0; i < intervalsSize; i++) {
        struct Interval tmp = intervals[i];
        for (j = i; j > 0 && intervals[j-1].start > tmp.start; j--)
            intervals[j] = intervals[j-1];
        intervals[j] = tmp;
    }

    int count = 0, flag = -1;
    for (int i = 0; i < intervalsSize; i++) {
        int tmp = (flag == -1 ? i:flag);
        if (i == intervalsSize - 1 && flag == -1) {
            res[count].start = intervals[i].start;
            res[count].end = intervals[i].end;
            count++;
        }
        else if (intervals[tmp].end >= intervals[i+1].start && i != intervalsSize - 1) {
            intervals[tmp].end = (intervals[i+1].end > intervals[tmp].end ? intervals[i+1].end : intervals[tmp].end);
            if (flag == -1)
                flag = i;
        } else {
            if (flag != -1) {
                res[count].start = intervals[flag].start;
                res[count].end = intervals[flag].end;
                count++, flag = -1;
            } else {
                res[count].start = intervals[i].start;
                res[count].end = intervals[i].end;
                count++;
            }
            
        }
    }
    *returnSize = count;
    return res;
}
```

- 真正体现了我总结出的规律，算法不够，`if`来凑
- 提交之后，由于插入排序与自己冗长的代码的原因，速度奇慢