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
    TreeNode* helper(vector<int>& nums, int s, int e){
        if(s > e) return NULL;
        int mid = s + (e - s)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, s, mid-1);
        root->right = helper(nums, mid+1, e);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int st = 0;
        int end = nums.size()-1;
        return helper(nums, st, end);
    }
};