class Solution {
public:
    // Variable to keep track of the last visited node's value during inorder traversal.
    // Helps ensure the values are in strictly increasing order (property of BST).
    int variable = INT_MIN;

    // Final answer flag; remains true only if all checks pass.
    bool ans = 1;

    /*
        Function: isBST
        ----------------
        Recursively checks whether a binary tree is a Binary Search Tree (BST) or not
        using inorder traversal.

        Logic:
        - Inorder traversal of a BST always gives sorted values in ascending order.
        - So we traverse in inorder (Left → Node → Right).
        - At each node, we compare its value with the previous one.
        - If current node's value is not greater than previous, it's not a BST.

        Parameters:
        - Node* root: pointer to the current node of the binary tree.

        Returns:
        - true if the tree is a valid BST, false otherwise.
    */
    bool isBST(Node* root) {
        if (root) {
            // Traverse the left subtree
            ans = isBST(root->left);

            // Check if current node violates the BST property
            if (root->data > variable)
                variable = root->data; // Update variable to current node's value
            else
                return 0; // Not a BST if values are not in strictly increasing order

            // Only check the right subtree if left subtree was valid
            if (ans != 0)
                ans = isBST(root->right);
        }

        return ans;
    }
};
