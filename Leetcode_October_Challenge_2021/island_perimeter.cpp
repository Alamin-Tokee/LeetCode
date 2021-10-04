//Approach 1
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>>d={{1,0},{0,1},{-1,0},{0,-1}};
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count+=4;
                    for(auto it:d){
                        int x=i+it.first;
                        int y=j+it.second;
                        
                        if(x>=0 and y>=0 and x<n and y<m and grid[x][y]==1){
                            count--;
                        }
                    }
                }
            }
        }
        return count;
    }
};

//Approach 2
class Solution {
public:
    int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int i, j, ans = 0, l, n = grid.size(), m = grid[0].size(), pos_i, pos_j, temp;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(grid[i][j] && !vis[i][j]){
                    q.push({i, j});
                    vis[i][j] = true;
                    while(!q.empty()){
                        auto t = q.front();
                        q.pop();
                        temp = 4;
                        for(l = 0; l < 4; l++){
                            pos_i = t.first + dir[l][0];
                            pos_j = t.second + dir[l][1];
                            if(pos_i >= 0 && pos_i < n && pos_j >= 0 && pos_j < m && grid[pos_i][pos_j]){
                                temp--;
                                if(!vis[pos_i][pos_j]){
                                    vis[pos_i][pos_j] = true;
                                    q.push({pos_i, pos_j});
                                }
                            }
                            
                        }
                        ans += temp;
                    }
                    break;
                }
            }
        }
        return ans;
        
    }
};