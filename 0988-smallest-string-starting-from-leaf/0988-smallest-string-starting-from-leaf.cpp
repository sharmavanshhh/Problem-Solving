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
    void traversal(TreeNode* root, string path, string& ans){
        if(!root) return;

        path = char('a' + root->val) + path;

        if(!root->left && !root->right){
            ans = min(ans, path);
        }

        traversal(root->left, path, ans);
        traversal(root->right, path, ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "~";
        traversal(root, "", ans);
        return ans;
    }
};