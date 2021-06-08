//Time Complexity O(n)
//Space Complexity O(n)

class Solution {
public:
    int postIndex;
    unordered_map<int,int>inorderMap;
    
    TreeNode* constructTree(vector<int>& postorder,int left,int right){
        if(left>right) return NULL;
        
        int val=postorder[postIndex--];
        TreeNode* root=new TreeNode(val);
        root->right=constructTree(postorder,inorderMap[val]+1,right);
        root->left=constructTree(postorder,left,inorderMap[val]-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex=postorder.size()-1;
        for(int i=0; i<inorder.size();i++){
            inorderMap[inorder[i]] = i;
        }
        
        return constructTree(postorder,0 , postorder.size()-1);
    }
};