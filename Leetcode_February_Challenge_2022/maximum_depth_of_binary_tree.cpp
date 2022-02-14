//TC O(n)
//SC O(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(!q.empty()){
            int sz=q.size();
            count++;
            while(sz--){
                auto x=q.front();
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        return count;
    }
};

//TC O(n)
//SC O(1)
class Solution {
public:
    int ma=INT_MIN;
    void dfs(TreeNode* root,int level){
        if(!root) return;
        
        // if(level  > ma){
        //     ma=level;
        // }
        ma=max(ma,level);
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(root,1);
        return ma;
    }
};

//TC O(n)
//SC O(1)
class Solution {
public:
    int dfs(TreeNode* root){
        if(!root) return 0;
        
        return 1+max(dfs(root->left),dfs(root->right));
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return dfs(root);
    }
};

//TC O(n)
//SC O(1)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};

//TC O(n)
//SC O(1)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        function<int(TreeNode*)> dfs=[&](TreeNode* root){
            if(!root) return 0;
            return max(dfs(root->left),dfs(root->right))+1;
        };
        return dfs(root);
    }
};