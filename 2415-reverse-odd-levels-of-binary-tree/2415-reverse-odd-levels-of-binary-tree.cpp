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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root){
            return nullptr;
        }

        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> nodes;

            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(level % 2 != 0){
                    nodes.push_back(curr);
                }

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            int n = nodes.size();
            for(int i=0; i<n/2; i++){
                swap(nodes[i]->val, nodes[n-i-1]->val);
            }

            level++;
        }

        return root;
    }
};