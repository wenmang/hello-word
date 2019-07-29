---
title: leetcode61
data: 2018-12-16 14:18
tag: [leetcode,链表,双指针]
---

### 61. 旋转链表（Rotate List）

#### 中文题目

给定一个链表，旋转链表，将链表每个节点向右移动 *k* 个位置，其中 *k* 是非负数。

**示例 1:**

```
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
```

**示例 2:**

```
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
```

---

#### 英文题目

Given a linked list, rotate the list to the right by *k* places, where *k* is non-negative.

**Example 1:**

```
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
```

**Example 2:**

```
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
```

---

#### 题目解答

- 本题还算基础，主要有两个“坑”
  - 特殊数据的处理，不过这也好像不算是坑了，每道题都必须要考虑到的事情
  - 关于超时
- 题目我刚开始想的是，按照规则，移动`k次`就行，但发现会超时
- 只能对链表先进行遍历，之后再移动`k % 表长`次即可

**代码：**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;
    
    struct ListNode* nHead;
    struct ListNode* tmp;
    int count = 1;
    tmp = head;
    while(tmp->next != NULL) {
        count++;
        tmp = tmp->next;
    }
    k = k % count;
    if (k == 0)
        return head;
    
    while(k--) {
        tmp = head;
        while (head->next->next != NULL)
            head = head->next;
        nHead = head->next;
        nHead->next = tmp;
        head->next = NULL;
        head = nHead;
    }
    return head;
}
```

- 提交之后，怎么也到不了最快，看了最快的代码，不由得想骂自己蠢
- 题目只要求输出最终结果，为啥要注意中间过程呢？直接只在最后进行一次调整不就行了吗

**代码：**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;
    
    struct ListNode* nHead;
    struct ListNode* tmp;
    struct ListNode* last;

    int count = 1;
    last = head;
    while(last->next != NULL) {
        count++;
        last = last->next;
    }
    k = k % count;
    if (k == 0)
        return head;
    
    tmp = head;
    while(k--) 
        head = head->next;
    last->next = tmp;
    nHead = head->next;
    head->next = NULL;
    
    return nHead;
}
```

- 改成这样后，报错了一组数据，`[1,2] 1`
- 发现这时应该不进行移动，参考了最快的示例代码后，做了修改

**代码：**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL)
        return head;
    
    struct ListNode* nHead;
    struct ListNode* tmp;
    struct ListNode* last;

    int count = 1;
    last = head;
    while(last->next != NULL) {
        count++;
        last = last->next;
    }
    k = k % count;
    if (k == 0)
        return head;
    
    tmp = head;
    while((count - k) != 1) {
        head = head->next;
        k++;
    } 
    last->next = tmp;
    nHead = head->next;
    head->next = NULL;
    
    return nHead;
}
```

