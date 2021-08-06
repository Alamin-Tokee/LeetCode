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