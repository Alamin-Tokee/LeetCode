//DFS
class Solution {
public:
    int sum=0;
    void dfs(TreeNode* root){
        if(!root) return;
        
        if(root->val % 2==0 and root->left){
            if(root->left->left) sum+=root->left->left->val; 
            if(root->left->right) sum+=root->left->right->val;
        }
        
        if(root->val % 2==0 and root->right){
            if(root->right->left) sum+=root->right->left->val; 
            if(root->right->right) sum+=root->right->right->val;  
        }
        
        dfs(root->left);
        dfs(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        this->sum=sum;
        dfs(root);
        
        return sum;
    }
};



class Solution {
public:
   
    int sumEvenGrandparent(TreeNode* root) {
         int sum =0;
        inorder(root,1,1,sum);
        return sum;
    }
    
    void inorder(TreeNode* root,int parent,int grandparent,int &sum){
        if(!root){
            return;
        }
        if(root && grandparent%2==0){
            sum=sum+root->val;
        }
        inorder(root->left,root->val,parent,sum);
        inorder(root->right,root->val,parent,sum);
    }
};


//     void solve(TreeNode* root,int &sum,int par,int gpar){
//         if(!root){
//             return;
//         }
        
//         solve(root->left,sum,root->val,par);
//         solve(root->right,sum,root->val,par);
//         if(gpar!=-1 && gpar%2==0){
//             sum=sum+root->val;
//         }
        
        
//     }

//BFS
class Solution {
  public:
    int sumEvenGrandparent(TreeNode * root) {
      int ans = 0;
      queue < TreeNode * > q;
      q.push(root);

      while (!q.empty()) {
        TreeNode * parent = q.front();
        q.pop();
        if (parent -> val % 2 == 0) {
          if (parent -> left && parent -> left -> left) ans += parent -> left -> left -> val;
          if (parent -> left && parent -> left -> right) ans += parent -> left -> right -> val;
          if (parent -> right && parent -> right -> left) ans += parent -> right -> left -> val;
          if (parent -> right && parent -> right -> right) ans += parent -> right -> right -> val;
        }

        if (parent -> left) q.push(parent -> left);
        if (parent -> right) q.push(parent -> right);
      }

      return ans;
    }
};