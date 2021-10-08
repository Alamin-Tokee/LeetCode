
class Solution {
public:
    void dfs(TreeNode* root,vector<int>&ans,int &ml,int l){
        if(!root) return;
        if(ml < l){
            ans.push_back(root->val);
            ml=l;
        }
        dfs(root->right,ans,ml,l+1);
        dfs(root->left,ans,ml,l+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) {};
        vector<int>ans;
        int ml=-1;
        dfs(root,ans,ml,0);
        return ans;
    }
};



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();
                if(sz==0)ans.push_back(x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }

        return ans;
    }
};