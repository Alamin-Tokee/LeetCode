class Solution {
public:
    void dfs(TreeNode* root,vector<int>&post){
        if(!root) return;
        dfs(root->left,post);
        dfs(root->right,post);
        post.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>post;
        dfs(root,post);
        
        return post;
    }
};