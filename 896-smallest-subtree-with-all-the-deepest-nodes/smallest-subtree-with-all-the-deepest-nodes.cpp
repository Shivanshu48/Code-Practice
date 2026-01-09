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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;

        if(root->val == p->val || root->val == q->val) return root;

        TreeNode* leftlca = lca(root->left, p, q);
        TreeNode* rightlca = lca(root->right, p, q);

        if(leftlca && rightlca) return root;
        else if(leftlca != NULL) return leftlca;
        else return rightlca;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> lastlevel;

        while(!q.empty()){
            int size = q.size();
            lastlevel.clear();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                lastlevel.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        TreeNode* ans = lastlevel[0];
        for(int i = 1; i < lastlevel.size(); i++){
            ans = lca(root, ans, lastlevel[i]);
        }
        return ans;
    }
};