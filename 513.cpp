class Solution {
public:
    int maxlevel=-1;
    int val=0;
    void dfs(TreeNode* root,int h){
        if(!root) return;
        if(maxlevel < h){
            maxlevel=h;
            val=root->val;
        }
        dfs(root->left,h+1);
        dfs(root->right,h+1);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        dfs(root,0);
        
        return val;
    }
};