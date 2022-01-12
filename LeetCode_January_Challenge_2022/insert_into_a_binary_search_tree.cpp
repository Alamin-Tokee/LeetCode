//Time Complexity O(n)
//Space Complexity O(H)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        
        if(val > root->val) root->right=insertIntoBST(root->right,val);
        else root->left=insertIntoBST(root->left,val);
        
        return root;
    }
};

//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
     TreeNode* insertIntoBST(TreeNode* root, int val) {
         if(root==NULL) return new TreeNode(val);
         TreeNode* curr = root;
         while(true){
             if(curr->val<val){
                 if(curr->right!=NULL) curr=curr->right;
                 else{
                     curr->right = new TreeNode(val);
                     break;
                 }
             }else{
                 if(curr->left!=NULL) curr=curr->left;
                 else{
                     curr->left = new TreeNode(val);
                     break;
                 }
             }
         }  
        return root;
    }
};

//Time Complexity O(n)
//Space Complexity O(H)
class Solution{
    public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if(root->val < val) {
            TreeNode* rightNode = insertIntoBST(root->right,val);
            root->right = rightNode;
            return root;
        }
        else{
            TreeNode* leftNode = insertIntoBST(root->left,val);
            root->left = leftNode;
            return root;
        }
        return root;
    }
};