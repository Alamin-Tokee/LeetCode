class Solution {
public:
    vector<vector<int>>path;
    void dfs(int u,vector<int>& vec,int n,vector<vector<int>>& graph){
        if(u==n-1){
            path.push_back(vec);
            return;
        }
        for(int i=0;i<graph[u].size();i++){
            vec.push_back(graph[u][i]);
            dfs(graph[u][i],vec,n,graph);
            vec.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vec;
        vec.push_back(0);
        
        dfs(0,vec,n,graph);
        
        return path;
    }
};


class Solution {
public:
    vector<vector<int>>path;
    void dfs(int u,vector<int>& vec,int n,vector<vector<int>>& graph){
        if(u==n-1){
            path.push_back(vec);
            return;
        }
            
        for(auto v:graph[u]){
            vec.push_back(v);
            dfs(v,vec,n,graph);
            vec.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vec;
        vec.push_back(0);
        
        dfs(0,vec,n,graph);
        return path;
    }
};