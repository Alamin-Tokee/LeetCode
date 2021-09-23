class Solution {
public:
    int bfs(vector<vector<int>>& g,int r,int c){
        queue<pair<int,int>>q;
        int cnt=0;
        q.push({r,c});
        g[r][c]=0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            cnt++;
            for(int i=0;i<g[0].size();i++){
                if(g[x][i]==1){
                    q.push({x,i});
                    g[x][i]=0;
                }
            }
            for(int i=0;i<g.size();i++){
                if(g[i][y]==1){
                    q.push({i,y});
                    g[i][y]=0;
                }
            }
        }
        return cnt==1 ? 0 : cnt;
    }
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans+=bfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};


