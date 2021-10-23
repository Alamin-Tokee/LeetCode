class Solution {
public:
    void dfs(TreeNode* root,vector<int>&pre){
        if(!root) return;
        pre.push_back(root->val);
        dfs(root->left,pre);
        dfs(root->right,pre);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>pre;
        dfs(root,pre);
        
        return pre;
    }
};