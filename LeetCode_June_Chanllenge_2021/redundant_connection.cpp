//DFS solution 

class Solution {
public:
    bool dfs(vector<vector<int>> &m,int node, vector<int>visited, int parent){
        if(find(visited.begin(),visited.end(),node)!=visited.end())return true;
        
        visited.push_back(node);
        
        for(int v:m[node]){
            if(v==parent) 
                continue;
            if(dfs(m,v,visited,node)) {
                return true;
            }
        }
        
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>visited;
        
        vector<vector<int>> m(n+1);
        
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            m[u].push_back(v);
            m[v].push_back(u);
            
            if(dfs(m,u,visited,-1))         
            {
              return {u,v};
            }
            visited.clear();
        }
        
        return {};
    }
};


