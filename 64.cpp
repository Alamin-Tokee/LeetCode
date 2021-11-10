class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>&g,vector<vector<int>>&m){
        if(row < 0 || col < 0 || row >= g.size() || col >= g[0].size() ) return INT_MAX;
        
        if(row == g.size()-1 && col == g[0].size()-1) return g[row][col];
        
        if(m[row][col]!=-1) return m[row][col];
        
        return m[row][col]=g[row][col]+min(dfs(row+1,col,g,m),dfs(row,col+1,g,m));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>m(grid.size(),vector<int>(grid[0].size()+1,-1));
        return dfs(0,0,grid,m);
    }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dp[n][m];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if( i == n-1 && j == m-1){
                    dp[i][j] = grid[i][j];     
                }
                else if( i == n-1 ){
                    dp[i][j] = dp[i][j+1] + grid[i][j];   
                }
                else if( j == m-1 ){
                    dp[i][j] = dp[i+1][j] + grid[i][j]; 
                } 
                else{
                    dp[i][j] = grid[i][j] + min(dp[i][j+1],dp[i+1][j]); 
                }
            }
        }
        return dp[0][0];
    }
};