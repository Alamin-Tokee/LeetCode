
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                if(x->left && !x->left->left && !x->left->right){
                    sum+=x->left->val;
                }
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
            }
        }
        return sum;
    }
};




class Solution {
public:
    int sum=0;
    void dfs(TreeNode* root){
        if(!root) return;
        
        if(root->left && !root->left->left && !root->left->right){
            sum+=root->left->val;
        }
        dfs(root->left);
        dfs(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        this->sum=sum;
        if(!root) return 0;
        dfs(root);
        return sum;
    }
};



class Solution {
public:
    void dfs(TreeNode* root,int &sum){
        if(root){
            if(root->left){
                dfs(root->left,sum);
                if(root->left->left==NULL && root->left->right==NULL)
                    sum+=root->left->val;
            }
            dfs(root->right,sum);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(!root) return 0;
        dfs(root,sum);
        return sum;
    }
};