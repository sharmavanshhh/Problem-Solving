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
    // void postOrder(TreeNode* root, vector<int>& tree){
    //      if(!root){
    //         return;
    //     }
    //     postOrder(root->left, tree);
    //     postOrder(root->right, tree);
    //     tree.push_back(root->val);
    // }
    
    void treeSize(TreeNode* root, int& nodes){
        if(!root){
            return;
        }
        treeSize(root->left, nodes);
        treeSize(root->right, nodes);
        nodes++;
    }
    int countNodes(TreeNode* root) {
        // vector<int> tree;
        // postOrder(root, tree);
        // return tree.size();
        
        int nodes = 0;
        treeSize(root, nodes);
        return nodes;
    }
};