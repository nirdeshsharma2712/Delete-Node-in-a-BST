# 📊 LeetCode Problem: Delete Node in a BST

## 🧩 Problem Statement

Given a `root` node reference of a **BST** and a `key`, **delete** the **node** with the given `key` in the **BST**. Return the `root` node reference (possibly updated) of the **BST**.

> **Note :**
> - Basically, the deletion can be divided into two stages:
> - Search for a node to remove.
> - If the node is found, delete the node.



## 🧠 Approach: DFS Traversing + BST Searching 


- If the `node` has no children, simply remove it.
- If the `node` has one child, return that child to **replace the node**.
- If the `node` has two children, find the **minimum value** in the **right subtree**, replace the node’s value with it, and** recursively** delete that minimum node.
> Use standard **BST search rules**:
> - if `key < root->val`, go **left**
> - if `key > root->val`, go **right**
> - if **equal**, perform the deletion steps above.



## ✅ Example Walkthrough

### Example 1

##### Input: root = [5,3,6,2,4,null,7], key = 3
##### Output: [5,4,6,2,null,null,7]

##### Explanation: 
<pre> 
  - Given key to delete is 3. So we find the node with value 3 and delete it.
  - One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
  - Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
  
</pre>

### Example 2

##### Input: root = [5,3,6,2,4,null,7], key = 0
##### Output: [5,3,6,2,4,null,7]

##### Explanation: 
<pre> 
   - The tree does not contain a node with value = 0.
  
</pre>

### Example 3

##### Input: root = [], key = 0
##### Output: []


## 🛠️ Constraints

- The number of nodes in the tree is in the range `[0, 10^4]`
- `-10^5 <= Node.val <= 10^5`
- Each node has a **unique** value.
- `root` is a valid binary search tree.
- `-10^5 <= key <= 10^5`
