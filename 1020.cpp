class Solution {
public:
    //int offsets[] = {0, 1, 0, -1, 0};
    int bfs(vector<vector<int>>& g,int r,int c,vector<vector<bool>>& vi){
        int offsets[] = {0, 1, 0, -1, 0};
        queue<pair<int,int>>q;
        int cnt=0;
        q.push({r,c});
        vi[r][c]=true;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            cnt++;
            for (int k = 0; k < 4; k++) {
                int u = x + offsets[k], v = y + offsets[k + 1];
                if (u >= 0 && u < g.size() && v >= 0 && v < g[0].size() && g[u][v] == 1 && vi[u][v]==false) {
                    vi[u][v] = true;
                    q.push({u, v});
                }
            }
        }
        return cnt;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                    if((i==0 || j==0 || i==n-1 || j==m-1) && !vis[i][j]){
                        count+=bfs(grid,i,j,vis);
                    }
                }
            }
        }
        return ans-count;
    }
};