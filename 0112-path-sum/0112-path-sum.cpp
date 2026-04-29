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
    void solve(TreeNode* node, int target, int currSum, bool& ans){
        if(!node) return;

        if(!node->left && !node->right){
            if(currSum + node->val == target){
                ans = true;
                return;
            }
        }

        solve(node->left, target, currSum + node->val, ans);
        solve(node->right, target, currSum + node->val, ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        solve(root, targetSum, 0, ans);
        return ans;
    }
};