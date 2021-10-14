//BFS Solution
class Solution {
public:
    int bfs(vector<vector<int>>& g,queue<pair<int,int>>&q){
        int offsets[] = {0, 1, 0, -1, 0};
        int cnt=0;
        bool flag=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int u = x + offsets[k], v = y + offsets[k + 1];
                    if (u >= 0 && u < g.size() && v >= 0 && v < g[0].size() && g[u][v] == 1) {
                        g[u][v] = 2;
                        q.push({u, v});
                        flag=1;
                    }
                }
            }
            if(flag) {
                cnt++;
                flag=0;
            }
            
        }
        return cnt;
    }
    int orangesRotting(vector<vector<int>>& grid) {  
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        ans+=bfs(grid,q);
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    c++;
                }
            }
        }
        return c ? -1 : ans; 
    }
};



//DFS Solution
class Solution {
public:
    //int offsets[] = {0, 1, 0, -1, 0};
    void dfs(vector<vector<int>>& g,int r,int c,int l){
        if(r<0 || c<0 || r>=g.size() || c>=g[0].size() || g[r][c]==0 || (1<g[r][c]&&g[r][c]<l)) return;
        
        g[r][c]=l;
        dfs(g,r+1,c,l+1);
        dfs(g,r-1,c,l+1);
        dfs(g,r,c+1,l+1);
        dfs(g,r,c-1,l+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {  
        int n=grid.size();
        int m=grid[0].size();
        int ans=2,c=0;
        if(grid.size() == 0) return -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    dfs(grid,i,j,2);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    c++;
                }
                ans=max(ans,grid[i][j]);
            }
        }
        return c ? -1 : ans-2; 
    }
};





