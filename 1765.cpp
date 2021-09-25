//BFS solution
//Time Complexity O(n*m)
//Space Complexity O(n*m)
class Solution {
public:
    void bfs(vector<vector<int>>& g,queue<pair<int,int>>&q,vector<vector<bool>>&vi){
        int offsets[] = {0, 1, 0, -1, 0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vi[x][y]=true;
            for (int k = 0; k < 4; k++) {
                int u = x + offsets[k], v = y + offsets[k + 1];
                if (u >= 0 && u < g.size() && v >= 0 && v < g[0].size() && g[u][v] == 0 && vi[u][v]==false) {
                    g[u][v]=g[x][y]+1;
                    q.push({u, v});
                }
            }
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        int ans=0;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    isWater[i][j]=0;
                    vis[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        bfs(isWater,q,vis);
        
        return isWater;
    }
};





