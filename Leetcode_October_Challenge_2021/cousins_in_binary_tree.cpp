class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        int dx = depth(root,x,0), dy = depth(root,y,0);
        if(dx!=dy) return false;
        int px = parent(root,x), py = parent(root,y);
        return px==py ? false : true;
    }
    int parent(TreeNode* node,int n){
        if(node==NULL) return -1;
        if((node->left && node->left->val==n) || (node->right && node->right->val==n)) return node->val;
        return max(parent(node->left,n),parent(node->right,n));
    }
    int depth(TreeNode* node,int n,int d){
        if(node==NULL) return 0;
        if(node->val==n) return d;
        return max(depth(node->left,n,d+1),depth(node->right,n,d+1));
    }
};


class Solution {
public:
    TreeNode* xParent=NULL, *yParent=NULL;
    int xDepth=-1,yDepth=-1;
    void dfs(TreeNode* root,TreeNode* parent,int x,int y,int d){
        if(root==NULL) return;
        
        if(root->val==x){
            xParent=parent;
            xDepth=d;
        }
        if(root->val==y){
            yParent=parent;
            yDepth=d;
        }
        dfs(root->left,root,x,y,d+1);
        dfs(root->right,root,x,y,d+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,NULL,x,y,0);
        return xDepth==yDepth and xParent!=yParent;
    }
};

class Solution {
public:
    unordered_map<int, pair<int, int>>m;
    void dfs(TreeNode* root, int depth, int parent){
        if(root == NULL) return;
        m[root->val] = {depth, parent};
        dfs(root->left, depth+1, root->val);
        dfs(root->right, depth+1, root->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int>res;
        dfs(root, 0, -1);
        if(m[x].first == m[y].first ){
            if(m[x].second != m[y].second) return 1;
        }
        return 0;
    }
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> qq;
        qq.push(root);
        while(!qq.empty()){
            int size = qq.size();
            
            bool foundX = false;
            bool foundY = false;
            for(int i=0; i<size; ++i) {
                TreeNode* curr= qq.front(); qq.pop();
                if(curr->val == x )foundX=true;
                if(curr->val == y)foundY=true;
                if(curr->left && curr->right){ 
                    if( (curr->left->val==x && curr->right->val==y) || (curr->left->val==y && curr->right->val==x) ){
                        return false;
                    }
                }
                if(curr->left){
                    qq.push(curr->left);
                }
                if(curr->right){
                    qq.push(curr->right);
                }
                if(foundX && foundY)return true; 
            }
        }
        
        return false;
    }
};