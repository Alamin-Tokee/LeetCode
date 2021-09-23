class Solution {
public:
    void bfs(vector<vector<char>>& g,int r,int c){
        int offsets[] = {0, 1, 0, -1, 0};
        queue<pair<int,int>>q;
        int cnt=0;
        q.push({r,c});
        g[r][c]='0';
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int u = x + offsets[k], v = y + offsets[k + 1];
                if (u >= 0 && u < g.size() && v >= 0 && v < g[0].size() && g[u][v] == '1') {
                    g[u][v] = '0';
                    q.push({u, v});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    bfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};



