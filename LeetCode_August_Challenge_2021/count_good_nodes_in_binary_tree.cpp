//TC O(n)
//SC O(n) If we consider recursion

class Solution {
public:
    int dfs(TreeNode* root,int v){
        if(!root) return 0;
        
        if(root->val >= v){
            return 1+dfs(root->left,max(root->val,v))+dfs(root->right,max(root->val,v));
        }else{
            return dfs(root->left,max(root->val,v))+dfs(root->right,max(root->val,v));
        }

    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count=1;
        count+=dfs(root->left,root->val)+dfs(root->right,root->val);
        
        return count;
    }
};
