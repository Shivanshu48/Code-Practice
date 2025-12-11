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
    int f(TreeNode* node) {
        if(node == NULL) return 0;

        int lh = f(node->left);
        if(lh == -1) return -1;

        int rh = f(node->right);
        if(rh == -1) return -1;

        if(lh - rh > 1 || rh - lh > 1) return -1;
        
        return 1 + (lh > rh ? lh : rh);
    }
    
    bool isBalanced(TreeNode* root) {
        return f(root) != -1;
    }
};