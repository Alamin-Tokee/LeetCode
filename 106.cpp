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

//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
     TreeNode* constructTree(vector<int>& postorder,int pl,int pr,vector<int>& inorder,int il,int ir){
         if(pl > pr || il > ir) return NULL;
         
         int i=0;
         for(i=il;i<=ir;i++){
             if(postorder[pr]==inorder[i]) break;
         }
         
         TreeNode* root=new TreeNode(postorder[pr]);
         
         root->left=constructTree(postorder,pl,pl+i-il-1,inorder,il,i-1);
         root->right=constructTree(postorder,pl+i-il,pr-1,inorder,i+1,ir);
         
         return root;
     }
    
     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         return constructTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
     }
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = size(inorder), postIdx = n-1;
        return build(inorder, postorder, 0, n-1, postIdx);
    }

    TreeNode* build(vector<int>& in, vector<int>& post, int inStart, int inEnd, int& postIdx) {
        if(inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(post[postIdx--]);
        int inIdx = find(begin(in), end(in), root -> val) - begin(in);
        root -> right = build(in, post, inIdx+1, inEnd, postIdx);
        root -> left  = build(in, post, inStart, inIdx-1, postIdx);
        return root;
    }
};
