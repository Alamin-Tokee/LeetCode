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




