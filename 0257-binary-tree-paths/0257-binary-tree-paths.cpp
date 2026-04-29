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
    void paths(TreeNode* node, string currPath, vector<string>& ans){
        if(!node) return;

        if(!currPath.empty()) currPath += "->";
        currPath += to_string(node->val);

        if(!node->left && !node->right){
            ans.push_back(currPath);
            return;
        }

        paths(node->left, currPath, ans);
        paths(node->right, currPath, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        paths(root, "", ans);
        return ans;
    }
};