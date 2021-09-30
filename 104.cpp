//BFS
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

//DFS
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