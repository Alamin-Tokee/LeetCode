//DFS + Memoization
//Time Complexity O(M*N)
//Space Complexity O(M*N)
class Solution {
public:
    int dfs(vector<vector<int>>& g,int row,int col,vector<vector<int>>& m){ 
        if(row<0 || col<0 || row>=g.size() || col>=g[0].size() ||g[row][col]==1)
            return m[row][col]=0;
        
         if(row==g.size()-1 && col==g[0].size()-1 )
            return m[row][col]=1;
        
        if(m[row][col]!=-1)
            return m[row][col];
        
        return m[row][col]=dfs(g,row+1,col,m)+dfs(g,row,col+1,m);;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>>mem(m+1,vector<int>(n+1,-1));
        return dfs(obstacleGrid,0,0,mem);

    }
};

//Tabulization
//Time Complexity O(M*N)
//Space Complexity O(M*N)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else{
                    if(i==m-1 and j==n-1) dp[i][j]=1;
                    else if(i==m-1) dp[i][j]=dp[i][j+1];
                    else if(j==n-1) dp[i][j]=dp[i+1][j];
                    else dp[i][j]=dp[i+1][j]+dp[i][j+1];
                }
            }
        }
        return dp[0][0];

    }
};

