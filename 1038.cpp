
//Approach  1
class Solution {
public:
    // TreeNode* dfs(TreeNode* &root,int &sum){
    //     if(!root){
    //         return NULL;
    //     }
    //     dfs(root->right,sum);
    //     root->val=sum+root->val;
    //     sum=root->val;
    //     dfs(root->left,sum);
    //     return root;
    // }
    
    void dfs(TreeNode* root,int &curSum){
        if(!root) return;
        dfs(root->right,curSum);
        root->val+=curSum;
        curSum=root->val;
        dfs(root->left,curSum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return NULL;
        int sum=0;
        dfs(root,sum);
        
        return root;
    }
};

//Approach 2
class Solution {
public:
    void dfs(TreeNode* root,vector<TreeNode*>&v){
        if(!root) return;
        dfs(root->left,v);
        v.push_back(root);
        dfs(root->right,v);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return NULL;
        vector<TreeNode*>v;
        dfs(root,v);
        
        for(int i=v.size()-2;i>=0;i--){
            v[i]->val+=v[i+1]->val;
        }
        
        return root;
    }
};