/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//BFS Solution
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        queue<Node*>q;
        q.push(root);
        int count=0;
        while(!q.empty()){
            int sz=q.size();
            count++;
            while(sz--){
                auto x=q.front();
                q.pop();
                for(auto child:x->children){
                   q.push(child);
                }
            }
        }
        return count;
    }
};

//DFS solution
class Solution {
public:
    int ma=INT_MIN;
    void dfs(Node* root,int level){
        if(!root) return;
        
        // if(level  > ma){
        //     ma=level;
        // }
        ma=max(ma,level);
        for(auto child:root->children){
            dfs(child,level+1);
        }
    }
    int maxDepth(Node* root) {
        if(!root) return 0;
        dfs(root,1);
        return ma;
    }
};