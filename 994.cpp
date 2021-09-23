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






