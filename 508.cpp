class Solution {
public:
    int dfs(TreeNode* root){
        if(!root) return 0;

        return root->val+dfs(root->left)+dfs(root->right);
    }
    void find(TreeNode* root,map<int,int>&mp) {
        if(!root) return;
        int ans=dfs(root);
        mp[ans]++;
        find(root->left,mp);
        find(root->right,mp);
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root) return {};
        map<int,int>mp;
        find(root,mp);
        vector<int>ans;
        int ma=-1;
        for(auto it=mp.begin();it!=mp.end();it++){
            ma=max(ma,it->second);
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(ma==it->second){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int solve(TreeNode* root,map<int,int>&m)
    {
        if(!root)
            return 0;
        int l=solve(root->left,m);
        int r=solve(root->right,m);
        int s=l+r+root->val;
        m[s]++;
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int>m;
        solve(root,m);
        int ma=INT_MIN;
        for(auto it:m)
        {
            if(it.second>ma)
                ma=it.second;
        }
        vector<int>ans;
        for(auto it:m)
        {
            if(it.second==ma)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
            
    }
};