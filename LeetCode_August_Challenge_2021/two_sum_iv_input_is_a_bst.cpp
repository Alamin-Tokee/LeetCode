//First Appraoch

class Solution {
public:
    bool dfs(TreeNode* root,int k,unordered_set<int>&st){
        if(!root) return false;
        
        if(st.count(k-root->val)) return true;
        st.insert(root->val);
        
        return dfs(root->left,k,st) || dfs(root->right,k,st);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>st;
        
        return dfs(root,k,st);
    }
};

//Second Approach
class Solution {
public:
    vector<int>vec;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        vec.push_back(root->val);
        dfs(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int l=0, r=vec.size()-1;
        while(l<r){
            if(vec[l]+vec[r]==k) return true;
            else if(vec[l] < k-vec[r]){
                l++;
            }else if(vec[l] > k-vec[r]){
                r--;
            }
        }
        return false;
    }
};

//Third Apprach (BFS)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return true;
        unordered_map<int,int>mp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(mp.count(k-curr->val) > 0) return true;
            mp[curr->val]++;
            if(curr->left) q.push(curr->left);
            
            if(curr->right) q.push(curr->right);
        }
        
        return false;
    }
};




