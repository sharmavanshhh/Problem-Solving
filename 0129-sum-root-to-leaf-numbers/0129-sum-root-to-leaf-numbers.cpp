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
    void backtracking(TreeNode* root, int& ans, int curr){
        if(!root){
            return;
        }
        curr = curr*10 + root->val;
        if(!root->left && !root->right){
            ans += curr;
            return;
        }
        backtracking(root->left, ans, curr);
        backtracking(root->right, ans, curr);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        backtracking(root, ans, 0);
        return ans;
    }
};