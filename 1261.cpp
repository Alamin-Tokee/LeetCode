class FindElements {
public:
    TreeNode* node;
    FindElements(TreeNode* root) {
        node=dfs(root,0);
    }
    
    TreeNode* dfs(TreeNode* root,int val){
        if(!root) return NULL;
        root->val=val;
        
        root->left=dfs(root->left,2*val+1);
        root->right=dfs(root->right,2*val+2);
        
        return root;
        
    }
    
    bool search(TreeNode* root,int t){
        if(!root) return false;
        
        if(root->val==t) return true;
        
        return (search(root->left,t) || search(root->right,t));
    }
    
    bool find(int target) {
        return search(node,target);
    }
};