class Solution {
public:
    void dfs(TreeNode* root,vector<vector<int>>&ans,int l){
        if(!root) return;
        if(ans.size() <= l)ans.push_back(vector<int>());
        ans[l].push_back(root->val);
        dfs(root->left,ans,l+1);
        dfs(root->right,ans,l+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        dfs(root,ans,0);
        
        return ans;
    }
};



class Solution {
public:
    int getHeight(TreeNode* root){
        if(!root) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    void dfs(TreeNode* root,vector<vector<int>>&ans,int l){
        if(!root) return;
        ans[l].push_back(root->val);
        dfs(root->left,ans,l+1);
        dfs(root->right,ans,l+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        int height = getHeight(root);
        vector<vector<int>> ans(height, vector<int>());

        dfs(root,ans,0);
        
        return ans;
    }
};


int getHeight(TreeNode* root){
    if(!root) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

void dfs(TreeNode* root, int index, vector<vector<int>> &solve){
    if(root){
        solve[index].push_back(root->val);
        dfs(root->left, index+1, solve);
        dfs(root->right, index+1, solve);
    }
}

vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return {};
    int height = getHeight(root);
    vector<vector<int>> solve(height, vector<int>());
    dfs(root, 0, solve);
    return solve;
}





class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int sz=q.size();
            vector<int>level;
            while(sz--){
                auto x=q.front();
                q.pop();
                level.push_back(x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            ans.push_back(level);
        }

        return ans;
    }
};