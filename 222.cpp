

class Solution {
public:
    int dfs(TreeNode* root){
        if(!root) return 0;
        
       return 1+dfs(root->left) + dfs(root->right);
        
    }
    int countNodes(TreeNode* root) {
        if(!root);
        return dfs(root);
    }
};


class Solution {
public:
    int ans=0;
    void dfs(TreeNode* root){
        if(!root) return;
        ans++;
        dfs(root->left);
        dfs(root->right);
    }
    int countNodes(TreeNode* root) {
        if(!root);
        dfs(root);
        return ans;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            ans++;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        return ans;
    }
};

//logn * logn
class Solution {
public:
    int leftHeight(TreeNode * root){
        int ans = 0;
        while(root){
            ans++;
            root = root->left;
        }
        return ans;
    }
    int rightHeight(TreeNode * root){
        int ans = 0;
        while(root){
            ans++;
            root = root->right;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


