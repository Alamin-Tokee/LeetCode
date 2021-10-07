//DFS
class Solution {
public:
    int total=0;
    void dfs(TreeNode* root,int sum){
        if(!root) return;
        sum=(sum <<1) | root->val;
        if(root->left==NULL and root->right==NULL) total+=sum;
        dfs(root->left,sum);
        dfs(root->right,sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        this->total=total;
        dfs(root,0);
        
        return total;
    }
};

//BFS
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        int total=0;
        int curSum=0;
        stack<pair<TreeNode*,int>>st;
        st.push({root,0});
        while(!st.empty()){
            TreeNode* x=st.top().first;
            curSum=st.top().second;
            st.pop();
            curSum=(curSum<<1)|x->val;
            if(x->left==NULL and x->right==NULL) total+=curSum;
            
            if(x->left) st.push(make_pair(x->left,curSum));
            if(x->right) st.push(make_pair(x->right,curSum));
            
        }
        
        return total;
    }
};