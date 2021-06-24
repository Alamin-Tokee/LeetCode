//Using Recursion
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
