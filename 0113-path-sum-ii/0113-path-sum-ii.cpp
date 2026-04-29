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
    void solve(TreeNode* node, vector<vector<int>>& result, vector<int>& paths, int targetSum){
        if(!node) return;

        paths.push_back(node->val);

        if(!node->left && !node->right && targetSum == node->val) {
            result.push_back(paths);
        }

        solve(node->left, result, paths, targetSum - node->val);
        solve(node->right, result, paths, targetSum - node->val);

        paths.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> paths;
        solve(root, result, paths, targetSum);
        return result;
    }
};