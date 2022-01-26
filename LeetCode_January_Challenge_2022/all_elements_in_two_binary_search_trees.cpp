
class Solution {
public:
    void dfs(TreeNode* root,vector<int>&res){
        if(!root) return;
        res.push_back(root->val);
        dfs(root->left,res);
        dfs(root->right,res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>res;
        dfs(root1,res);
        dfs(root2,res);
        sort(res.begin(),res.end());
        
        return res;
    }
};


    // vector<int> helper(TreeNode* root){
    //     vector<int> ans;
    //     stack<TreeNode*>s;
    //     TreeNode* curr = root;
    //     while(!s.empty() or curr!=NULL){
    //         if(curr!=NULL){
    //             s.push(curr);
    //             curr = curr->left;
    //         }else{
    //             curr = s.top();
    //             s.pop();
    //             ans.push_back(curr->val);
    //             curr = curr->right;
    //         }
    //     }
    //     return ans;
    // }




class Solution {
public:
    void dfs(TreeNode* root,vector<int>&res){
        if(!root) return;
        dfs(root->left,res);
        res.push_back(root->val);
        dfs(root->right,res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>r1,r2,r;
        dfs(root1,r1);
        dfs(root2,r2);
        
        int m,n;
        m=r1.size();
        n=r2.size();
        int i=0,j=0;
        while(i<m && j<n){
            if(r1[i] <= r2[j]){
                r.push_back(r1[i++]);
            }else{
                r.push_back(r2[j++]);
            }
        }
        
        for(int k=i;k<m;k++){
            r.push_back(r1[k]);
        }
        
        for(int k=j;k<n;k++){
            r.push_back(r2[k]);
        }
        
        return r;
    }
};



class Solution {
public:
    void dfs(TreeNode* root,vector<int>&res){
        if(!root) return;
        dfs(root->left,res);
        res.push_back(root->val);
        dfs(root->right,res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>a,b;
        dfs(root1,a);
        dfs(root2,b);
        
        int m=a.size();
        int n=b.size();
        vector<int>res(n+m);
        int i=0,j=0,idx=0;
        while(i<m and j<n){
            if(a[i]<b[j]){
                res[idx++]=a[i++];
                // idx++;
                // i++;
            }else{
                res[idx++]=b[j++];
                // idx++;
                // j++;
            }
        }
        while(i<m)
        {
            res[idx++]=a[i++];
            // idx++;
            // i++;
        }
        while(j<n)
        {
            res[idx++]=b[j++];
            // idx++;
            // j++;
        }
        return res;
    }
};


class Solution{
    public:
    void inOrder(TreeNode* root, vector<int>&v){
        if(root){
            inOrder(root->left, v);
            v.push_back(root->val);
            inOrder(root->right, v);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
        vector<int>v;
        inOrder(root1, v);
        inOrder(root2, v);
        sort(v.begin(), v.end());
        
        return v;
    }
};




