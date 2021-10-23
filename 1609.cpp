
class Solution {
public:
    void dfs(TreeNode* root,int level,bool &ans,vector<int>&contain){
        if(!root) return;
        if(level%2==0 and (root->val)%2==0) {
            ans=false;
            return;
        }
        if(level%2!=0 and (root->val)%2!=0) {
            ans=false;
            return;
        }
        if(level==contain.size()){
            contain.push_back(root->val);
        }else if(level%2==0){
            if(contain[level]>=root->val){
                ans=false;
                return;
            }
            contain[level]=root->val;
        }else if(level%2!=0){
            if(contain[level]<=root->val){
                ans=false;
                return;
            }
            contain[level]=root->val;
        }
        dfs(root->left,level+1,ans,contain);
        dfs(root->right,level+1,ans,contain);
        
    }
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return false;
        vector<int>contain;
        bool ans=true;
        dfs(root,0,ans,contain);
        
        return ans;
    }
};