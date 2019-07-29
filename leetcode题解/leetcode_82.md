---
title: leetcode82
data: 2018-12-27 14:00
tag: [leetcode,链表]
---

### 82. 删除排序链表中重复元素II（Remove Duplicates from Sorted List II）

#### 中文题目

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 *没有重复出现* 的数字。

**示例 1:**

```
输入: 1->2->3->3->4->4->5
输出: 1->2->5
```

**示例 2:**

```
输入: 1->1->1->2->3
输出: 2->3
```

#### 英文题目

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 *没有重复出现* 的数字。

**示例 1:**

```
输入: 1->2->3->3->4->4->5
输出: 1->2->5
```

**示例 2:**

```
输入: 1->1->1->2->3
输出: 2->3
```

#### 题目解答

- 此题我想出了合适的解法，也就是双指针，只不过自己写代码的时候跑偏了。。。
- 此题让我明白了，解决链表问题，还是一上来就搞个头指针（哨兵）比较好
- 双指针进行遍历链表，如果右边的指针没有遇到重复的结点，则两个指针共同进步，否则，只进右边的指针，直至节点不重复，将其右边的结点连在前一个指针的`next`上

**代码：**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    
    struct ListNode* guard = malloc(sizeof(struct ListNode));
    struct ListNode* p;
    struct ListNode* q;
    guard->next = head;
    p = guard;
    q = head;
    
    while (q != NULL) {
        int flag = 0;
        while (q->next != NULL && q->val == q->next->val) {
            q = q->next;
            flag = 1;
        }
        if (flag == 0)
            p = q;
        else
            p->next = q->next;
        q = q->next;
    }
    return guard->next;
}
```

- 这题折磨了不少时间，还是对于链表操作不够熟练啊！！！