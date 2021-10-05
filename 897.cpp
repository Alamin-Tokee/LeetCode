
class Solution {
public:
    TreeNode* cur;
    void dfs(TreeNode* root){
        if(!root) return;
        
        dfs(root->left);
        root->left=0;
        cur->right=root;
        cur=root;
        dfs(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* ans=new TreeNode(-1);
        cur=ans;
        dfs(root);
        
        return ans->right;
    }
};


class Solution {
public:
    vector<TreeNode*>inorder;
    void dfs(TreeNode* root){
        if(!root) return;
        
        dfs(root->left);
        inorder.push_back(root);
        dfs(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return NULL;
        dfs(root);
        TreeNode* ans=new TreeNode(-1);
        TreeNode* curr=ans;
        for(int i=0;i<inorder.size();i++){
            curr->right=new TreeNode(inorder[i]->val);
            curr=curr->right;
        }
        
        return ans->right;
    }
};


class Solution {
public:
    vector<int>inorder;
    void dfs(TreeNode* root){
        if(!root) return;
        
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return NULL;
        dfs(root);
        TreeNode* ans=new TreeNode(-1);
        TreeNode* curr=ans;
        for(int &v:inorder){
            curr->right=new TreeNode(v);
            curr=curr->right;
        }
        
        return ans->right;
    }
};