class Solution {
public:
    TreeNode* dfs(TreeNode* root){
        if(!root) return NULL;
        TreeNode* l=dfs(root->left);
        TreeNode* r=dfs(root->right);
        root->right=l;
        root->left=r;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        return dfs(root);
    }
};


class Solution {
public:
    void dfs(TreeNode* root){
        if(!root) return;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        dfs(root->left);
        dfs(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        dfs(root);
        return root;
    }
};


class Solution {
public:
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        dfs(root);
        return root;
    }
};

class Solution {
public:
    void dfs(TreeNode* root){
        if(!root) return;
        swap(root->left,root->right);
        dfs(root->left);
        dfs(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        dfs(root);
        return root;
    }
};


class Solution {
public:
    void swap(TreeNode **a,TreeNode **b){
        TreeNode * temp = *a;
        *a = *b;
        *b = temp;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        queue<TreeNode*> q;
        q.push(root);
       while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            swap(&temp->left,&temp->right);
            if(temp->left)
                q.push(temp->left);
            if(temp->right) 
                q.push(temp->right);
        }
        return root;
    }
};