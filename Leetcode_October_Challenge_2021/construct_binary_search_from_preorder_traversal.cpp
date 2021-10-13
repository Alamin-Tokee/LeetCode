
class Solution {
private:
    TreeNode* bstFromPreorder(TreeNode* root,int data){
        if(!root){
            return new TreeNode(data);
        }
        if(data<=root->val){
            root->left=bstFromPreorder(root->left,data);
        }else{
            root->right=bstFromPreorder(root->right,data);
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=NULL;
        
        for(int i=0;i<preorder.size();i++){
            root=bstFromPreorder(root,preorder[i]);
        }
        
        return root;
    }
};




class Solution {
private:
    void bstFromPreorder(TreeNode* root,int data){
        if(data<=root->val){
            if(root->left==NULL){
                root->left=new TreeNode(data);
            }else{
                bstFromPreorder(root->left,data);
            }
        }else{
            if(root->right==NULL){
                root->right=new TreeNode(data);
            }else{
                bstFromPreorder(root->right,data);
            }
        }
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode();
        root->val=preorder[0];
        for(int i=1;i<preorder.size();i++){
            bstFromPreorder(root,preorder[i]);
        }
        
        return root;
    }
};



class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& p) {
        int id = 0;
        return build(p, id, INT_MAX);
    }
    
    TreeNode* build(vector<int>& p, int& id, int limit) {
        if(id == p.size() || p[id] > limit)
            return NULL;
        int val = p[id++];
        TreeNode* root = new TreeNode(val);
        root->left = build(p, id, val);    //root->left must be less than the root
        root->right = build(p, id, limit); //root->right must be less than the previous root
        return root;
    }
};




class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {      
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *p = root;
        stack<TreeNode*> S;
        int i = 1;
        while(i < preorder.size())
        {
            if(p->val > preorder[i])
            {
                p->left = new TreeNode(preorder[i]);
                S.push(p);
                p = p->left;
            }
            else
            {
                while(!S.empty() && S.top()->val < preorder[i])
                {
                    p = S.top();
                    S.pop();
                }
                p->right = new TreeNode(preorder[i]);
                p = p->right;
            }
            i++;
        }
        return root;
    }
};

