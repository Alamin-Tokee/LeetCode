
class Solution {
public:
    map<int,int>mp;
    void dfs(TreeNode* root, int h){
        if(!root) return;
        mp[h]+=root->val;
        dfs(root->left,h+1);
        dfs(root->right,h+1);
    }
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        dfs(root,1);
        
        auto it=mp.begin();
        int level=1;
        int maxSum=INT_MIN;
        while(it!=mp.end()){
            if(maxSum < it->second){
                maxSum=it->second;
                level=it->first;
            }
            it++;
        }
        return level;
    }
};