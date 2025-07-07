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
    void traverse(TreeNode* root, vector<int>& arr){
        if(!root){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            arr.push_back(root->val);
        }
        traverse(root->left, arr);
        traverse(root->right, arr);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;

        traverse(root1, leaves1);
        traverse(root2, leaves2);

        return leaves1 == leaves2;
    }
};