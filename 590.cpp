
//Recusive (DFS)
class Solution {
public:
    void dfs(Node* root,vector<int>&ans){
        if(!root) return;
        
        for(auto x:root->children){
            dfs(x,ans);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int> ans;
        
        dfs(root,ans);
        
        return ans;
    }
};


//Iterative 1
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int> ans;
        
        stack<Node*>st;
        st.push(root);

        while(!st.empty()){
            auto x=st.top();
            st.pop();
            ans.push_back(x->val);
            for(auto child:x->children){
                st.push(child);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//Iterative 2
class Solution {
public:
    vector<int> ans;
    vector<int> postorder(Node* root) {
        if (!root) return {};
        vector<Node*> stk{root};
        for (; !stk.empty();) {
            auto r = stk.back();
            if (r->children.empty()) {
                ans.push_back(r->val);
                stk.pop_back();
            }
            for (int i = r->children.size() - 1; i >= 0; i--)
                stk.push_back(r->children[i]);
            r->children.clear();
        }
        return ans;
    }
};