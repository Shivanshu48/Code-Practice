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
    vector<vector<int>> path;
    vector<int> currpath;
    void dfs(TreeNode* root, int target){
        if(!root) return;
        
        currpath.push_back(root->val);
        target -= root->val;

        if(!root->left && !root->right && target == 0){
            path.push_back(currpath);
        }
        dfs(root->left, target);
        dfs(root->right, target);

        currpath.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return path;

    }
};