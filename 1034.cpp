class Solution {
public:
    bool isBorder(int &tx, int &ty, vector<vector<int>>& grid)
    {
        int rowOffset[] = {0,0,1,-1};
        int colOffset[] = {1,-1,0,0};
        int px,py;
        
        for(int i=0;i<4;i++){
            px = tx + rowOffset[i];
            py = ty + colOffset[i];
            if(px>=0 && px<grid.size() && py>=0 && py<grid[0].size() && grid[tx][ty]!=grid[px][py]) return true;
        }
        
        return (tx==0 || ty==0 || tx==grid.size()-1 || ty==grid[0].size()-1);
    }
    
    void bfs(vector<vector<int>>& g,int r,int c,int color,vector<vector<int>>&vi){
        int offsets[] = {0, 1, 0, -1, 0};
        queue<pair<int,int>>q;
        q.push({r,c});
        vi[r][c]=1;
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(isBorder(x,y,g)) vi[x][y]=2;
          
            for (int k = 0; k < 4; k++) {
                int u = x + offsets[k], v = y + offsets[k + 1];
                if (u >= 0 && u < g.size() && v >= 0 && v < g[0].size() && g[x][y]==g[u][v] && !vi[u][v]) {
                    vi[u][v]=1;
                    q.push({u, v});
                }
            }
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        bfs(grid,row,col,color,vis);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==2){
                    grid[i][j]=color;
                }
            }
        }
        return grid;
    }
};









