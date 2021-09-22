//Time Complexity O(m*nM+N);
//Space Complexity O(m*n)
class Solution {
public:
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    void bfs(vector<vector<int>>& g, vector<vector<int>>& g1,vector<vector<bool>>& v,int r,int c,bool &subGrid){
        queue<pair<int,int>>q;
        v[r][c]=true;
        q.push({r,c});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(g[x][y]!=g1[x][y]){
                subGrid=false;
            }
        
            for(int i=0;i<4;i++){
                int ii=x+dir[i][0];
                int jj=y+dir[i][1];
                
                if(ii >= 0 and ii < g.size() and jj >= 0 and jj < g[0].size() and g[ii][jj]==1 and v[ii][jj]==false){
                    v[ii][jj]=true;
                    q.push({ii,jj});
                }
            }
            
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid1[i][j]==1 && grid2[i][j]==1){
                    bool subGrid=true;
                    bfs(grid2,grid1,vis,i,j,subGrid);
                    if(subGrid) ans++;
                }
            }
        }
        return ans;
    }
};

//Time Complexity O(m*nM+N);
//Space Complexity O(1)
class Solution {
    vector<vector<int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int M = grid2.size();
        int N = grid2[0].size();
        int subIslandCount = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid2[i][j] == 1) {
                    bool hasSubIslandFound = bfs(i, j, M, N, grid1, grid2);
                    subIslandCount += hasSubIslandFound;
                }
            }   
        }
        return subIslandCount;
    }
    
    bool bfs(int i, int j, int &M, int &N, vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        queue<vector<int>> todo;
        todo.push({ i, j });
        grid2[i][j] = 0; // Mark the cell
        bool hasSubIslandFound = true;
        while (!todo.empty()) {
            vector<int> cur = todo.front();
            todo.pop();
            // Check if grid1 has also same cell?
            if (grid1[cur[0]][cur[1]] != 1) {
                hasSubIslandFound = false; // Not found, but keep BFS anyways
            }
            for (vector<int> &dir : directions) {
                int nx = dir[0] + cur[0];
                int ny = dir[1] + cur[1];
                if (inside(nx, ny, M, N) && grid2[nx][ny] == 1) {
                    todo.push({ nx, ny });
                    grid2[nx][ny] = 0; // Mark the cell
                }
            }
        }
        return hasSubIslandFound;
    }
    
    bool inside(int i, int j, int &M, int &N) {
        if (i < 0 || i >= M || j < 0 || j >= N) {
            return false;
        }
        return true;
    }
};