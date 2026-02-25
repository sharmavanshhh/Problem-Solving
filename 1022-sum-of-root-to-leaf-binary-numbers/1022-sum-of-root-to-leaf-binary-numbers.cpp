class Solution {
public:
    int dfs(TreeNode* root, int curr){
        if(!root) return 0;

        // current number build karo
        curr = (curr << 1) | root->val;

        // agar leaf hai toh return number
        if(!root->left && !root->right)
            return curr;

        // left + right ka sum
        return dfs(root->left, curr) + dfs(root->right, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};