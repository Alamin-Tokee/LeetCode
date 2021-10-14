//BFS Solution
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


//DFS Solution (TLE)
class Solution {
public:
    void dfs(vector<vector<int>>&mat,vector<vector<int>>&res,int i,int j,int curDistance){
        if(i < 0 or j < 0 or i>=mat.size() or j>=mat[0].size()) return;
        
        if(curDistance==0 or mat[i][j]==1 and (res[i][j]==0 or res[i][j] > curDistance)){
            res[i][j]=curDistance;
            dfs(mat,res,i+1,j,curDistance+1);
            dfs(mat,res,i-1,j,curDistance+1);
            dfs(mat,res,i,j+1,curDistance+1);
            dfs(mat,res,i,j-1,curDistance+1);
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>result(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) {
                    dfs(mat,result,i,j,0);
                }
            }
        }
        return result;
    }
};


//DP Solution 

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.size() == 0){
            return mat;
        }
        int rows = mat.size(), cols = mat[0].size();  
        // no overflow
        vector<vector<int>> dp(rows,vector<int> (cols, INT_MAX-2));
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (mat[i][j] == 0){
                    dp[i][j] = 0;
                }
                if (i > 0){
                    dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
                }
                if (j > 0){
                    dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
                }
            }
        }
        for (int i = rows-1; i > -1; i--){
            for (int j = cols-1; j > -1; j--){
                if (i < rows-1){
                    dp[i][j] = min(dp[i][j],dp[i+1][j]+1);
                }
                if (j < cols-1){
                    dp[i][j] = min(dp[i][j],dp[i][j+1]+1);
                }
            }
        }
     return dp;   
    }
};