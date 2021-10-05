

class Solution {
public:
    void dfs(Node* root,vector<int>&ans){
        if(!root) return;
        
        for(auto x:root->children){
            dfs(x,ans);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int> ans;
        
        dfs(root,ans);
        
        return ans;
    }
};