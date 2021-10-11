class Solution {
public:
    vector<int>res;
    void dfs(TreeNode* root,int level){
        if(!root) return;
        if(res.size()<=level) res.push_back(root->val);
        else{
            res[level] = res[level] < root->val ? res[level]=root->val : res[level];
        }
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        dfs(root,0);
        
        return res;
    }
};