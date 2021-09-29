/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Bfs Solution
//Time Complexity O(v+e)
//Space O(1)
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            sum=0;
            while(sz--){
                auto p=q.front();
                q.pop();
                sum+=p->val;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        
        return sum;
    }
};

//DFS 1
class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        
        int a=height(root->left);
        int b=height(root->right);
        
        return max(a,b)+1;
    }
    void dfs(TreeNode* root,int &sum,int &h,int cur){
        if(!root) return;
        
        if(cur==h){
            sum+=root->val;
        }
        dfs(root->left,sum,h,cur+1);
        dfs(root->right,sum,h,cur+1);
    }

    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int h=height(root);
        int sum=0;
        dfs(root,sum,h,1);
        return sum;
    }
};

//DFS 2
class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        
        int a=height(root->left);
        int b=height(root->right);
        
        return max(a,b)+1;
    }
    void dfs(TreeNode* root,int &sum,int h){
        if(!root || h < 0) return;
        
        if(!root->left && !root->right && h==1){
            sum+=root->val;
        }
        dfs(root->left,sum,h-1);
        dfs(root->right,sum,h-1);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int h=height(root);
        int sum=0;
        dfs(root,sum,h);
        return sum;
    }
};