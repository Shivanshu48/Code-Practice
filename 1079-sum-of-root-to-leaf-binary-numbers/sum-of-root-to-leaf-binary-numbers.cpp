class Solution {
public:
    int convert2dec(string s){
        int num = 0;
        for(char c : s){
            num = num*2 + (c - '0');
        }
        return num;
    }

    int sum = 0;

    void dfs(TreeNode* root, string path){

        if(!root) return;

        path += to_string(root->val);

        if(!root->left && !root->right){
            sum += convert2dec(path);
            return;
        }

        dfs(root->left, path);
        dfs(root->right, path);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, "");
        return sum;
    }
};