class Solution {
public:
    int dfs(TreeNode* root,int &d){
        if(!root) return 0;
        
        int lh=dfs(root->left,d);
        int rh=dfs(root->right,d);
        d=max(d,lh+rh);
        
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int d=0;
        dfs(root,d);
        
        return d;
    }
};