class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int node,vector<vector<int>>&g,vector<int>&v){
        v.push_back(node);
        if(node==g.size()-1){
            ans.push_back(v);
            v.pop_back();
            return;
        }
        for(auto x:g[node]){
            dfs(x,g,v);
        }
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>v;
        dfs(0,graph,v);
        return ans;                  
    }
};


class Solution {
public:
    int n;
    void helper(vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>& minians,int curr){
        if(curr==n-1){
            ans.push_back(minians);
            return;
        }
        for(int i=0;i<graph[curr].size();i++){
            minians.push_back(graph[curr][i]);
            helper(graph,ans,minians,graph[curr][i]);
            minians.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        vector<vector<int>>ans;
        vector<int>minians;
        minians.push_back(0);
        helper(graph,ans,minians,0);
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        queue<vector<int>>q;
        q.push({0});
        
        while(size(q)){
            auto path=move(q.front());q.pop();
            if(path.back()==size(graph)-1) ans.push_back(move(path));
            else
                for(auto child:graph[path.back()]){
                    path.push_back(child);
                    q.push(path);
                    path.pop_back();
                }
        }
        return ans;
    }
};


