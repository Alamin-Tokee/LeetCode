//BFS Solution
//Time Complexity O(n)
//Space Complexity O(H)

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>>result;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>vec;
            for(int i=0;i<sz;i++){
                Node* node=q.front(); q.pop();
                vec.push_back(node->val);
                for(auto child:node->children){
                    q.push(child);
                }
            }
            result.push_back(vec);
        }
        
        return result;
    }
};

//BFS Solution
//Time Complexity O(n)
//Space Complexity O(H)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>>result;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            result.emplace_back();
            for(int i=0;i<sz;i++){
                Node* node=q.front(); q.pop();
                result.back().push_back(node->val);
                for(auto child:node->children){
                    q.push(child);
                }
            }
        }
        
        return result;
    }
};

//DFS Solution
//Time Complexity O(n)
//Space Complexity O(H)
class Solution {
public:
    void dfs(Node* root,int level){
        if(!root) return;
        
        if(level == res.size()) res.push_back({});//res.emplace_back();
        res[level].push_back(root->val);
        for(Node* curr:root->children)
            dfs(curr,level+1);
    }
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        
        dfs(root,0);
        
        return res;
    }
private:
    vector<vector<int>>res;
};
