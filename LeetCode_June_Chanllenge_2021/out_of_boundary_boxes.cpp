//Using Recursion(Brute Force)
//Time Complexity:O(4^n)
//Space Complexity O(n)

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(startRow==m || startColumn==n || startRow < 0 || startColumn < 0) return 1;
        
        if(maxMove==0) return 0;
        
        return findPaths(m,n,maxMove-1,startRow-1,startColumn)
            +findPaths(m,n,maxMove-1,startRow+1,startColumn)
            +findPaths(m,n,maxMove-1,startRow,startColumn-1)
            +findPaths(m,n,maxMove-1,startRow,startColumn+1);
    }
};

//Using Memoization(Top Down)
//Time Complexity:O(mnN)
//Space Complexity O(mnN)

class Solution {
public:
    int dp[51][51][52];
    int mod=1e9+7;
    int countPaths(int m, int n, int x, int i, int j){
        if(i==m || j==n || i < 0 || j < 0) return 1;
        
        if(x==0) return 0;
        if(dp[i][j][x]!=-1) return dp[i][j][x];
        
        int ans=0;
        ans=(ans+countPaths(m,n,x-1,i-1,j))%mod;
        ans=(ans+countPaths(m,n,x-1,i+1,j))%mod;
        ans=(ans+countPaths(m,n,x-1,i,j-1))%mod;
        ans=(ans+countPaths(m,n,x-1,i,j+1))%mod;
        
        return dp[i][j][x]=ans;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        
        return countPaths(m,n,maxMove,startRow,startColumn);
    }
};

//Using Tabulation(Bottm Up)
//Time Complexity:O(mnN)
//Space Complexity O(mnN)

class Solution {
public:
    vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
    int mod = 1e9 + 7;
    
    int fn_memo(int m,int n,int sr,int sc,int msf,int maxMoves,vector<vector<vector<int>>>& dp){
        
        if(msf > maxMoves) return 0;
        
        if(msf <= maxMoves)
            if(sr < 0 || sc < 0 || sr == m || sc == n) return 1;
        
        if(dp[sr][sc][msf] != -1) return dp[sr][sc][msf];
        
        long count = 0;
        for(int d=0; d < 4; d++){
            int r = sr + dir[d][0];
            int c = sc + dir[d][1];
            
            if(msf <= maxMoves)
                count = (count + fn_memo(m,n,r,c,msf + 1,maxMoves,dp) % mod) % mod;
        }
        
        return dp[sr][sc][msf] = count % mod;
    }
    
    int findPaths(int m, int n, int maxMoves, int x, int y) {
        if(m == 1 && n == 1) return 4;
        if(maxMoves == 0) return 0;
        
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMoves + 1,-1)));
        int ans = fn_memo(m,n,x,y,0,maxMoves,dp);
        return ans;
    }
};


class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        auto dp=vector<vector<int>>(m,vector<int>(n,0));
        auto temp=dp;
        
        int M=1e9+7;
        
        for(int k=0;k<N;k++){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    long a=(i-1<0) ? 1: dp[i-1][j];
                    long b=(i+1>=m) ? 1: dp[i+1][j];
                    long c=(j-1<0) ? 1: dp[i][j-1];
                    long d=(j+1>=n) ? 1: dp[i][j+1];
                    
                    temp[i][j]=(a+b+c+d)%M;
                }
            }
            dp=temp;
        }
        return dp[i][j];
    }
};

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m, vector<int>(n));
        
        vector<int> dirs{0, -1, 0, 1, 0};
        
        int mod = 1e9 + 7;
        
        for (int k = 0; k < maxMove; ++k) {   
            vector<vector<int>> tmp(m, vector<int>(n));
            
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int x = 0; x < 4; ++x) {
                        auto dx = i + dirs[x];
                        auto dy = j + dirs[x + 1];
                        
                        if (dx < 0 || dy < 0 || dx >= m || dy >= n) {
                            tmp[i][j] += 1;
                        } else {
                            tmp[i][j] = (tmp[i][j] + dp[dx][dy]) % mod;
                        }
                    }
                }
            }
            
            dp = tmp;
        }
        
        return dp[startRow][startColumn];
    }
};

