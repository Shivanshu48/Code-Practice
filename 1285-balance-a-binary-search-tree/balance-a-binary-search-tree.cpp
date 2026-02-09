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
    void inorder(vector<int>& arr, TreeNode* root){
        if(root == NULL) return;
        inorder(arr, root->left);
        arr.push_back(root->val);
        inorder(arr, root->right);
    }
    

    TreeNode* makeTree(vector<int>& arr, int left, int right){
        if(left > right) return nullptr;
        
        int mid = left + (right-left)/2;
        TreeNode* newroot = new TreeNode(arr[mid]);
        newroot->left = makeTree(arr, left, mid-1);
        newroot->right = makeTree(arr, mid+1, right);
        return newroot;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(arr, root);
        return makeTree(arr, 0, arr.size()-1);
    }
};