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
    long long kthLargestLevelSum(TreeNode* root, int k){
        if (!root) return -1;

        queue<TreeNode*> q;
        q.push(root);
        vector<long long> levelSums;

        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;

            for (int i = 0; i < size; i++){
                TreeNode* node = q.front(); 
                q.pop();
                sum += node->val;
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }

            levelSums.push_back(sum);
        }

        if (levelSums.size() < k) return -1;

        sort(levelSums.rbegin(), levelSums.rend());
        return levelSums[k - 1];
    }
};