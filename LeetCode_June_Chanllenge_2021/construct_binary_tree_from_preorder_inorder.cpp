class Solution {
public:
    int preIndex;
    unordered_map<int,int>inorderMap;
    
    TreeNode* constructTree(vector<int>& preorder,int left,int right){
        if(left>right) return NULL;
        
        int val=preorder[preIndex++];
        TreeNode* root=new TreeNode(val);
        root->left=constructTree(preorder,left,inorderMap[val]-1);
        root->right=constructTree(preorder,inorderMap[val]+1,right);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex=0;
        for(int i=0; i<inorder.size();i++){
            inorderMap[inorder[i]] = i;
        }
        
        return constructTree(preorder,0 , preorder.size()-1);
    }
};