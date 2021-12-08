class Solution {
public:
    int dfs(TreeNode* root,int &sum){
        if(!root) return 0;
        int l=dfs(root->left,sum);
        int r=dfs(root->right,sum);
        sum=sum+abs(r-l);
        
        return root->val+l+r;
    }
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        int sum=0;
        dfs(root,sum);
        return sum;
    }
};