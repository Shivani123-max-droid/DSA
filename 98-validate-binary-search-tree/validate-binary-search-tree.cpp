class Solution {
public:
    // Function to check if a binary tree is a valid Binary Search Tree (BST)
    bool isValidBST(TreeNode* root) {
        // Call the helper function with initial min and max values set to the smallest and largest possible values
        return checkBST(root, INT64_MIN, INT64_MAX);
    }

    // Helper function to validate the BST by checking the allowed value range for each node
    bool checkBST(TreeNode* root, long long min, long long max) {
        // Base case: If the node's value is not within the allowed range, it's not a valid BST
        if (root->val <= min || root->val >= max) return false;

        // Recursively check the left subtree with an updated max value (should be less than the current node's value)
        bool left = root->left ? checkBST(root->left, min, root->val) : true;

        // Recursively check the right subtree with an updated min value (should be greater than the current node's value)
        bool right = root->right ? checkBST(root->right, root->val, max) : true;

        // The tree is a valid BST only if both left and right subtrees are valid
        return left && right;
    }
};