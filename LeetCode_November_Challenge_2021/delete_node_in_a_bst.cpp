
class Solution {
public:
    TreeNode* findMin(TreeNode* root){
        if(!root->left) return root;
        
        return findMin(root->left);
    }
    TreeNode* deleteValue(TreeNode* root,int val){
        if(!root) return root;
        else if(val > root->val)
            root->right=deleteValue(root->right,val);
        else if(val < root->val) 
            root->left=deleteValue(root->left,val);
        else{
            if(!root->left and !root->right){
                delete root;
                root=NULL;
            }else if(!root->left){
                TreeNode* temp=root;
                root=root->right;
                delete temp;
            }else if(!root->right){
                TreeNode* temp=root;
                root=root->left;
                delete temp;
            }else{
                TreeNode* temp=findMin(root->right);
                root->val=temp->val;
                root->right=deleteValue(root->right,temp->val);
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        return deleteValue(root,key);
    }
};