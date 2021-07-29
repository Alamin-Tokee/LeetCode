//BFS Solution
//Time Complexity O(r*c)
//Space Complexity O(r*c)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=curr.first+dir[i][0];
                int y=curr.second+dir[i][1];
                if(x >= 0 && y >= 0 && x < n && y < m && dist[x][y] == -1){
                    dist[x][y] = dist[curr.first][curr.second] + 1;
                    q.push({x,y});
                }
            }
        }
        return dist;
    }
};

//BFS Solution
//Time Complexity O(r*c)
//Space Complexity O(1)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e4));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dp[i][j]=mat[i][j];
                }else{
                    if(i > 0) dp[i][j]=min(dp[i][j],1+dp[i-1][j]);
                    if(j > 0) dp[i][j]=min(dp[i][j],1+dp[i][j-1]);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
   
                if(i+1 < n) dp[i][j]=min(dp[i][j],1+dp[i+1][j]);
                if(j+1 < m) dp[i][j]=min(dp[i][j],1+dp[i][j+1]);

            }
        }
        return dp;
    }
};


//DFS Solution(TLE)
//Time Complexity O(r*c)
//Space Complexity O(1)
class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int r, int c)
    {
        if(r<0 || c<0 || r >=matrix.size() || c >=matrix[0].size() || matrix[r][c]==-1)
            return 10000;
        if(matrix[r][c]==0 || matrix[r][c]==1)
            return matrix[r][c];
        int t = matrix[r][c];
        matrix[r][c] = -1;
        int l = 1+dfs(matrix, r, c-1);
        int ri= 1+dfs(matrix, r, c+1);
        int d = 1+dfs(matrix, r-1, c);
        int u = 1+dfs(matrix, r+1, c);
        matrix[r][c] = min({t, l, ri, d, u});
        return matrix[r][c];
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j])
                    matrix[i][j] = 10000;
        
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j])
                    dfs(matrix, i, j);
        return matrix;
        
    }
};