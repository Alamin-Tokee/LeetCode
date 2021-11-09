//DFS + Backtraking (TLE)

class Solution {
public:
    int ans=0;
    void dfs(vector<vector<int>>&g,int row,int col){
        if(row < 0 || col < 0 || row >= g.size() || col >= g[0].size() || g[row][col]==0) return;
        
        if(g[row][col]==1){
            ans++;
            return;
        }
        g[row][col]=0;
        
        dfs(g,row+1,col);
        dfs(g,row,col+1);
        
        g[row][col]=-1;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>g(m,vector<int>(n,-1));
        g[m-1][n-1]=1;
        
        dfs(g,0,0);
        
        return ans;
    }
};

// DFS + Memoization
//Time Complexity O(M*N);
//Space Complexity O(M*N)
class Solution {
public:
    int dfs(vector<vector<int>>&g,int row,int col,int m,int n){
        if(row==m-1 && col==n-1) return 1;
        if(row < 0 || col < 0 || row > m-1 || col > n-1) return 0;
        if(g[row][col]!=-1) return g[row][col];
         
        return g[row][col]=dfs(g,row+1,col,m,n)+dfs(g,row,col+1,m,n);

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>g(m+1,vector<int>(n+1,-1));

        return dfs(g,0,0,m,n);
    }
};

//Tabular Method
//Time Complexity O(M*N);
//Space Complexity O(M*N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table(m,vector<int> (n,-1));
        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                    table[i][j]=1;
                else if(i==m-1)
                    table[i][j]=table[i][j+1];
                else if(j==n-1)
                    table[i][j]=table[i+1][j];
                else
                    table[i][j]=table[i+1][j]+table[i][j+1];
            }
        }
        return table[0][0];
        
    }
};