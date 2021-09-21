//BFS Approach
//Time Complexity O(m*n)
//Space Complexity O(m*n)

class Solution {
public:
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    int bfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int r,int c){
        queue<pair<int,int>>q;
        q.push({r,c});
        bool corner=true;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            if(x.first==0 || x.second==0 || x.first==grid.size()-1 || x.second==grid[0].size()-1) corner=false;
            vis[x.first][x.second]=true;
            for(int i=0;i<4;i++){
                int u=x.first+dir[i][0];
                int v=x.second+dir[i][1];
                
                if(u >= 0 && u < grid.size() && v >=0 && v < grid[0].size() && grid[u][v]==0 && vis[u][v]==false){
                    q.push({u,v});
                }
            }
        }
        if(corner) return 1;
        else return 0;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && visited[i][j]==false){
                    ans+=bfs(grid,visited,i,j);
                }
            }
        }
        return ans;
    }
};