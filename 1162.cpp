class Solution {
public:
    int bfs(vector<vector<int>>& g,queue<pair<int,int>>&q,int &cnt){
        int offsets[] = {0, 1, 0, -1, 0};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int u = x + offsets[k], v = y + offsets[k + 1];
                    if (u >= 0 && u < g.size() && v >= 0 && v < g[0].size() && g[u][v] == 0) {
                        g[u][v]=1;
                        q.push({u, v});
                    }
                }
            }
            cnt++;
        }
        return cnt;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        queue<pair<int,int>>q;
        int ma=0;
        //vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push(make_pair(i,j));
                }
            }
        }
        if (q.size() == 0 || q.size() == n * n)
		return -1;
        int cnt = -1;
        bfs(grid,q,cnt);
        return cnt;
    }
};




