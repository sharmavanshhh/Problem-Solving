/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        dfs(ans, root);
        return ans;
    }

    int dfs(int& ans, TreeNode* root){
        if(!root) return 0;

        int left = dfs(ans, root->left);
        int right = dfs(ans, root->right);

        int leftPath = 0, rightPath = 0;

        if(root->left && root->val == root->left->val){
            leftPath = left + 1;
        }

        if(root->right && root->val == root->right->val){
            rightPath = right + 1;
        }

        ans = max(ans, leftPath + rightPath);

        return max(leftPath, rightPath);
    }
};