class Solution {
public:
    int bfs(vector<vector<char>>& g,vector<int>& e){
        int offsets[] = {0, 1, 0, -1, 0};
        queue<pair<int,int>>q;
        int cnt=-1;
        q.push({e[0],e[1]});
        g[e[0]][e[1]]='+';
        while(!q.empty()){
            int sz=q.size();
            cnt++;
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if((e[0]!=x || e[1]!=y) && (x==0 || y==0 || x==g.size()-1 || y==g[0].size()-1)) return cnt;
                for (int k = 0; k < 4; k++) {
                    int u = x + offsets[k], v = y + offsets[k + 1];
                    if (u >= 0 && u < g.size() && v >= 0 && v < g[0].size() && g[u][v] == '.') {
                        g[u][v] = '+';
                        q.push({u, v});
                    }
                }
            }
        }
        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        int ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]=='1'){
        //             ans++;
        //             bfs(grid,i,j);
        //         }
        //     }
        // }
        ans=bfs(maze,entrance);
        return ans;
    }
};






