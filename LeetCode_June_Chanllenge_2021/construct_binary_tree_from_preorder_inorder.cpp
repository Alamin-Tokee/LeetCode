//First Approach 
//Time Complexity O(n)\
//Space Complexity O(n)

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

//Second Approach Without extra space
//Time Complexity O(n)\
//Space Complexity O(1)
class Solution {
public:
     TreeNode* constructTree(vector<int>& preorder,int pl,int pr,vector<int>& inorder,int il,int ir){
         if(pl > pr || il > ir) return NULL;
         
         int i=0;
         for(i=il;i<=ir;i++){
             if(preorder[pl]==inorder[i]) break;
         }
         
         TreeNode* root=new TreeNode(preorder[pl]);
         
         root->left=constructTree(preorder,pl+1,pl+i-il,inorder,il,i-1);
         root->right=constructTree(preorder,pl+i-il+1,pr,inorder,i+1,ir);
         
         return root;
     }
    
     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         return constructTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
     }
};