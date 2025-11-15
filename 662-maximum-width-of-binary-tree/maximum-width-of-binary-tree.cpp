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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxwid = 0;
        while(q.size() > 0){
            int currsize = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;
            maxwid = max(maxwid, (int)(endIdx-stIdx+1));

            for(int i=0; i<currsize; i++){
                auto currNode = q.front();
                q.pop();
                if(currNode.first->left){
                    q.push({currNode.first->left, currNode.second*2+1});
                }
                if(currNode.first->right){
                    q.push({currNode.first->right, currNode.second*2+2});
                }
            }
        }
        return maxwid;
    }
};