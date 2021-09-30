//DFS 
class Solution {
public:
    vector<int>ans;
    void dfs(Node* root){
        ans.push_back(root->val);
        
        for(auto x:root->children){
            dfs(x);
        }
    }
    vector<int> preorder(Node* root) {
        if(!root) return {};
        dfs(root);
        return ans;
    }
};

//BFS
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int>ans;
        stack<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            auto x=q.top();
            q.pop();
            ans.push_back(x->val);
             for(int i=x->children.size()-1;i>=0;i--)
                q.push(x->children[i]);
        }
        return ans;
    }
};