//BFS Solution

class Solution {
public:
    void bfs(vector<vector<int>>&adj,int i,vector<bool>&vis){
        queue<int>q;
        q.push(i);
        vis[i]=true;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<adj[x].size();i++){
                if(!vis[adj[x][i]]){
                    q.push(adj[x][i]);
                    vis[adj[x][i]]=true;
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& con) {
        int m=con.size();
        if(m < 1) return m;
        
        if(m < n-1) return -1;
        
        // vector<int>adj[n];
        vector<vector<int>>adj(n);
        for(int i=0;i<m;i++){
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
        }
        
        vector<bool>vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                bfs(adj,i,vis);
            }
        }
        return count-1;
    }
};