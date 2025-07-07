/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void backtracking(TreeNode* root, vector<vector<int>>& res,
                      vector<int>& temp, int target, int sum) {
        if (!root) {
            return;
        }
        temp.push_back(root->val);
        sum += root->val;
        if (!root->left && !root->right && sum == target) {
            res.push_back(temp);
        } else {
            backtracking(root->left, res, temp, target, sum);
            backtracking(root->right, res, temp, target, sum);
        }
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        backtracking(root, res, temp, targetSum, 0);
        return res;
    }
};