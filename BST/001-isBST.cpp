/*
📌 Question:
Given the root of a binary tree, check whether it is a valid
Binary Search Tree (BST) or not.

------------------------------------------------------------

🧠 Approach:
A key property of a BST is:
➡️ Inorder traversal of a BST produces a strictly increasing sequence.

Steps:
1. Perform an inorder traversal (Left → Root → Right).
2. Keep track of the previously visited node's value.
3. For every node:
   - If current node's value is less than or equal to the previous value,
     the BST property is violated.
4. Update the previous value and continue traversal.
5. If traversal completes without violations, the tree is a valid BST.

------------------------------------------------------------

🔍 Analogy:
Imagine checking if a list of exam roll numbers is sorted 📄:
- You read them one by one.
- If any number is smaller than or equal to the previous one,
  you immediately know the order is wrong.

BST validation works the same way.

------------------------------------------------------------

⏱️ Time Complexity:
- O(N), where N is the number of nodes
- Each node is visited exactly once

------------------------------------------------------------

💾 Space Complexity:
- O(H), where H is the height of the tree
- Due to recursive call stack
- Worst Case: O(N) (skewed tree)
- Average Case: O(log N)

------------------------------------------------------------
*/

class Solution {
  public:
    bool BST(Node* root, int &prev) {
        if (!root)
            return true;
        
        if (!BST(root->left, prev))
            return false;
        
        if (root->data <= prev)
            return false;
        
        prev = root->data;
        
        return BST(root->right, prev);
    }

    bool isBST(Node* root) {
        int prev = INT_MIN;
        return BST(root, prev);
    }
};
