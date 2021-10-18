class Solution {
public:
    int res=INT_MAX;
    void dfs(TreeNode* root,int level){
        if(!root) return;
        
        if(root->left==NULL and root->right==NULL){
            res=min(res,level);
        }

        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        this->res=res;
        dfs(root,1);
        return res;
    }
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        
        if(root->left == NULL || root->right == NULL)
            return max(l,r)+1;
        
        return min(l,r)+1;
    }
};


class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        if(root->left==NULL)
            return 1+minDepth(root->right);
        if(root->right==NULL)
            return 1+minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};


class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        queue<TreeNode*>Q;
        TreeNode* u;
        int ans=0,size;
		Q.push(root);
        while(!Q.empty())
        {
            ans++;
            size=Q.size();
            while(size--)
            {
                u=Q.front();
                Q.pop();
                if(u->left==NULL && u->right==NULL)
                    return ans;
                if(u->left)
                    Q.push(u->left);
                if(u->right)
                    Q.push(u->right);
            }
        }
        return ans;
    }
};