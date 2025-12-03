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
    void dfs(TreeNode* n, string s, vector<string>& res) {
        if (!n) return;
        s += s.empty() ? to_string(n->val) : "->" + to_string(n->val);
        if (!n->left && !n->right) {
            res.push_back(s);
            return;
        }
        dfs(n->left, s, res);
        dfs(n->right, s, res);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};