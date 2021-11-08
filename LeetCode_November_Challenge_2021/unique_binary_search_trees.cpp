class Solution {
public:
    int dp[20];
    int solve(int n){
        if(n <= 1) return 1;
        if(dp[n]!=-1) return dp[n];
        
        int ans=0;
        for(int i=0;i<n;i++){
             ans += (solve(i) * solve(n - i - 1));
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};


class Solution {
public:
    int numTrees(int n) {
        vector<int>catalan(n+1,0);
        catalan[0]=catalan[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                catalan[i]+=catalan[j]*catalan[i-j-1];
            }
        }
        return catalan[n];
    }
};

//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int numTrees(int n) {
        long double ans = 1;
	    for (int k = 2; k <= n; k++)
            ans *= (n + k), ans /= k;
        return ans;
    }
};

