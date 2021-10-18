
class Solution {
public:
    vector<vector<int>>ans;
    void dfs(TreeNode* root,int level){
        if(!root) return;
        if(ans.size()<=level) ans.push_back(vector<int>());
        if(level%2==0){
            ans[level].push_back(root->val);
        }else{
            ans[level].insert(ans[level].begin(),root->val);
        }
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        dfs(root,0);
        
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        deque<TreeNode*>q;
        q.push_back(root);
        int level=0;
        //bool zigzag=false;
        while(!q.empty()){
            int sz=q.size();
            vector<int>tem;
            for(int i=0;i<sz;i++){
                TreeNode* x;
                if(level%2==1){
                    x=q.back();
                    q.pop_back();
                    tem.push_back(x->val);
                    if(x->right) q.push_front(x->right);
                    if(x->left) q.push_front(x->left);
                }else{
                    x=q.front();
                    q.pop_front();
                    tem.push_back(x->val);
                    if(x->left) q.push_back(x->left);
                    if(x->right) q.push_back(x->right);
                }
            }
            ans.push_back(tem);
            level++;
        }
        
        return ans;
    }
};

class Solution {
public:
   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        bool l2r=true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp(sz);
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                int idx=(l2r)?i:sz-1-i;
                temp[idx]=x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
              }
            l2r=!l2r;
            ans.push_back(temp);
           }        
        return ans;
    }
};