class Solution {
public:
    int diameter = 0;

    int depth(TreeNode* node) {  
        if (!node) return 0;
        int left = depth(node->left);   // how deep left side is
        int right = depth(node->right); // how deep right side is
        diameter = max(diameter, left + right); // update max path
        return 1 + max(left, right);    // return depth to parent
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
};
