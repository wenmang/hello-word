---
title: leetcode876
data: 2018-12-6 23:06
tag: [leetcode,链表]
---

### 876. 链表的中间结点

#### 中文题目

给定一个带有头结点 `head` 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

**示例 1：**

```
输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
```

**示例 2：**

```
输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
```

 

**提示：**

- 给定链表的结点数介于 `1` 和 `100` 之间。

---

#### 英文题目

Given a non-empty, singly linked list with head node `head`, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

**Example 1:**

```
Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
```

**Example 2:**

```
Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
```

 

**Note:**

- The number of nodes in the given list will be between `1` and `100`.

---

#### 题目解答

- 首先我想到的就是先遍历一遍链表，数出总结点的个数
- 计算中间结点，再次遍历至中间结点，返回即可

**代码：**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* tmp;
    tmp = head;
    int count = 0;
    while (tmp){
        count++;
        tmp = tmp->next;
    }
    count = count/2 + 1;
    for (int i = 1; i < count; i++)
        head = head->next;
    return head;
}
```

- 提交后发现，后面的循环可以优化

**代码：**

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* tmp;
    tmp = head;
    int count = 0;
    while (tmp){
        count++;
        tmp = tmp->next;
    }
    count = count/2;
   	while (count--)
        head = head->next;
    return head;
}
```

- 之后看了别人的代码，发现可以只进行一次遍历，代码写的很优美

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    while (fast != NULL) {
        fast = fast->next;
        if (fast == NULL) {
            break;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
```

- 多设立一个结点，让一个结点每次循环之时，前进两个结点
- 另一个每次前进一个结点
- 在前者到头之后，后者也就到了中间位置