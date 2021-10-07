class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        //vector<vector<int>>dp(m,vector<int>(n,0));
        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0 && j>0 && matrix[i][j]>0)
                    matrix[i][j]=min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]})+1;
                sum+=matrix[i][j];
            }
        }
        
        return sum;
    }
};


class Solution {
public:
   int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size(), ans=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]==0){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=1+min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
                    ans+=dp[i][j];
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        for(int i = n - 1 ;i >= 0 ; i--){
            for(int j = m - 1 ; j >= 0 ; j--){
                if(i == n - 1 && j == m - 1) dp[i][j] = matrix[i][j];
                else if(i == n - 1 || j == m - 1) dp[i][j] = matrix[i][j];
                else{
                    if(matrix[i][j] == 0) dp[i][j] = 0;
                    else
                    dp[i][j] = 1 + min(dp[i + 1][j + 1],min(dp[i + 1][j], dp[i][j + 1]));
                }
            }
        } 
        int ans = 0;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans += dp[i][j];
            }
        }
        return ans;
    }
};


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        int sq = 0;
        for(int i = 0; i < m; i++)
        {
            for(int  j = 0; j < n; j++)
            {
                if(matrix[i][j] && !dp[i][j])
                {
                    maxSq(matrix, i, j, m, n, dp);
                }
                
                // Number of squares with i,j as the starting vertex will be equal to the maximum size of square possible at i,j
                sq += dp[i][j];
            }
        }
        
        
        return sq;
    }
    
    // TO find the maximum size square possible at this point
    int maxSq(vector<vector<int>>& matrix,int i , int j, int m, int n, vector<vector<int>>& dp)
    {
        if(i >= 0 && j >= 0 && i < m && j < n && matrix[i][j])
        {
            if(dp[i][j])
                return dp[i][j];
            
            int a = maxSq(matrix, i+1,j,m,n,dp);
            int b = maxSq(matrix, i,j+1,m,n,dp);
            int c = maxSq(matrix, i+1,j+1,m,n,dp);
            
            // MAx Square at this point will be mininum of the a,b,c + 1
            dp[i][j] = min(a,min(b,c)) + 1;
            

            return dp[i][j];
                
        }
        return 0;
    }
};