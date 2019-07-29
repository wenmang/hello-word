### 24. 两两交换链表中的节点（）

#### 中文题目

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

**示例:**

```
给定 1->2->3->4, 你应该返回 2->1->4->3.
```

**说明:**

- 你的算法只能使用常数的额外空间。
- **你不能只是单纯的改变节点内部的值**，而是需要实际的进行节点交换。

#### 英文题目

Given a linked list, swap every two adjacent nodes and return its head.

**Example:**

```
Given 1->2->3->4, you should return the list as 2->1->4->3.
```

**Note:**

- Your algorithm should use only constant extra space.
- You may **not** modify the values in the list's nodes, only nodes itself may be changed.

---

刚看到本题之时，我开始动手做，脑残的我刚开始写了一个极为简练的代码，却发现自己只是在交换自己新建的结点，原链表并无变化，这里就不贴出了。。。

经查找，发现以下[解法](https://blog.csdn.net/guoziqing506/article/details/51295414)

#### 解法：

本题可以说是一个非常基本的题，考的是链表的结点交换，重点在于不丢失链表地址

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */     
struct ListNode* swapPairs(struct ListNode* head) { // LeetCode24
    if (head == NULL || head->next == NULL)	// 仅有0或1个结点 直接返回
        return head;
    
    struct ListNode* newHead, *p, *q, *temp;
    /* 下面的开空间必不可少 否则会报错 */
    newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newHead->next = head;
    /* 初始化 */
    temp = newHead;
    p = head;
    q = head->next;
    while (q){
        /*交换操作*/
        temp->next = q;
        p->next = q->next;	/* 整个交换的重点 将q之后的结点挂在p之后 */
        q->next = p;
        /*为下次操作准备*/
        temp = p;
        p = p->next;
        if (p)
            q =  p->next;
        else
            q = NULL;
    }
    
    return newHead->next;
}
```

**代码说明：**

- 首先，为链表设置一个头结点，防止链表丢失
- 初始化p，q，temp结点
- 开始交换，直至q结点为空
- 返回交换后的链表

**提交结果：**

![leetcode24](F:\LeetCode题解\week1\图片\leetcode24.png)