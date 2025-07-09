class Solution {
public:
    bool traversal(TreeNode* root, int val) {
        if (!root)
            return true;
        if (root->val != val)
            return false;
        return traversal(root->left, val) && traversal(root->right, val);
    }

    bool isUnivalTree(TreeNode* root) {
        return traversal(root, root->val);
    }
};
