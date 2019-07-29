---
title: leetcode104
data: 2018-12-8 23:15
tag: [leetcode,树]
---

### 104. 二叉树的最大深度

#### 中文题目

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

**说明:** 叶子节点是指没有子节点的节点。

**示例：**
给定二叉树 `[3,9,20,null,null,15,7]`，

```
    3
   / \
  9  20
    /  \
   15   7
```

返回它的最大深度 3 。

---

#### 英文题目

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Note:** A leaf is a node with no children.

**Example:**

Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

return its depth = 3.

---

#### 题目解答

- 看了下大家的解答，思路都差不多一致
- `三变量` `左树高` `右树高` `总高` 递归求解左右树高之后将大者赋予总高即可

**代码：**

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int HLeft, HRight, HMax;
    if (root) {
        HLeft = maxDepth(root->left);
        HRight = maxDepth(root->right);
        HMax = HLeft > HRight ? HLeft : HRight;
        return (HMax + 1);
    } else 
        return 0;
}
```

- 还有就是两变量，递归完之后返回大点的子树高

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(NULL == root)
        return 0;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
```

