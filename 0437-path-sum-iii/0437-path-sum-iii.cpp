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
    void dfs(TreeNode* root, long long currSum, int target, int& count){
        if(!root){
            return;
        }
        currSum += root->val;
        if(currSum == target){
            count++;
        }
        dfs(root->left, currSum, target, count);
        dfs(root->right, currSum, target, count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        int count = 0;

        // Start DFS from every node
        dfs(root, 0, targetSum, count);
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};