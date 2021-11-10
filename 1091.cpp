class Solution {
public:
    vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
    int bfs(vector<vector<int>>& g,int r,int c,int &n,int &m){
        queue<pair<int,int>>q;
        int cnt=0;
        q.push({r,c});
        g[r][c]=1;
        while(!q.empty()){
            int sz = q.size();
            cnt++;
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x==n-1 and y==m-1) return cnt;
                for (int k = 0; k < 8; k++) {
                    int u = x + dir[k][0], v = y + dir[k][1];
                    if (u >= 0 && u < n && v >= 0 && v < m && g[u][v] == 0) {
                        g[u][v] = 1;
                        q.push({u, v});
                    }
                 }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        if(grid[0][0]==1) return -1;
        ans = bfs(grid,0,0,n,m);
        return ans;
    }
};



#define pi pair<int,int> 
#define f first
#define s second 
class Solution {
public:
    int dis[101][101];
    int vis[101][101];
    int n,m;
    int dx[8] = {-1,1,-1,1,1,0,-1,0};
    int dy[8] = {-1,1,1,-1,0,1,0,-1};
    //DFS give TLE
//     void dfs(int x, int y, vector<vector<int>>& grid){
//         for(int i=0;i<8;i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
            
//             if(nx < 0 || ny < 0 || nx >=n || ny >= m){
//                 continue;
//             } else {
//                 if(grid[nx][ny]==0 && dis[nx][ny]==-1 || dis[nx][ny] > dis[x][y] + 1){
//                     dis[nx][ny] = dis[x][y] + 1;
//                     dfs(nx,ny,grid); 
//                 }
//             }
//         }
//     }
    void bfs(vector<vector<int>>& grid) {
        queue<pi> q;
        pi cur = {0,0};
        q.push(cur);
        vis[cur.f][cur.s] = 1;
        
        while(!q.empty()){
            pi cur = q.front(); q.pop();
            
            for(int i=0; i<8; i++) {
                int nx = cur.f + dx[i];
                int ny = cur.s + dy[i];
                
                if(nx>-1 && ny>-1 && nx<n && ny < m && !vis[nx][ny] && !grid[nx][ny]){
                    vis[nx][ny] = 1; 
                    dis[nx][ny] = dis[cur.f][cur.s] + 1; 
                    q.push({nx,ny});
                }
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(grid[0][0]==1) return -1;
        memset(dis,-1,sizeof(dis));
        dis[0][0]=1;
        //dfs(0,0,grid);
        bfs(grid);
        return dis[n-1][m-1];
    }
};


