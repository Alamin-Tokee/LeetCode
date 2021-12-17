//Time Complexity O(m*n)
//Space Complexity O(m*n)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int dp[n][m];
        int ans=-1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) dp[i][j] = matrix[i][j]-'0';
                else if(i==n-1 || j==m-1) dp[i][j] = matrix[i][j]-'0';
                else{
                    if(matrix[i][j]=='0') dp[i][j] = 0;
                    else
                    dp[i][j]=1+min(dp[i+1][j+1],min(dp[i+1][j], dp[i][j+1]));
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};

class Solution {
public:
    int dp[302][302];
    int solve(vector<vector<char>>& matrix, int i, int j){
        if(i>=matrix.size() or j>=matrix[0].size() or matrix[i][j]=='0') return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = 1+min({solve(matrix,i+1,j), solve(matrix,i,j+1),solve(matrix,i+1,j+1)});
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int area=0;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]=='1') area=max(area,solve(matrix,i,j));
            }
        }
        return area*area;
    }
};

class Solution {
public:
    int solve(vector<vector<char>>&mat,int i,int j,vector<vector<int>>&dp){
        if(i<=0 or j<=0 or mat[i][j]=='0') return mat[i][j]=='1' ? dp[i][j]=1 : dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]=1+min({solve(mat,i-1,j-1,dp),solve(mat,i-1,j,dp),solve(mat,i,j-1,dp)});
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int area=0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]=='1') area=max(area,solve(matrix,i,j,dp));
            }
        }
        return area*area;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    if(i==0 || j==0) dp[i][j]=1;
                    else{
                        dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                    }
                    ans=max(ans,dp[i][j]*dp[i][j]);
                }
            }
        }
        return ans;
    }
};