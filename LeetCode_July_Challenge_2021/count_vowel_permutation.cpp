//Time Complexity O(n)
//Space Complexty O(1)

class Solution {
public:
    int countVowelPermutation(int n) {
        long aCount=1,eCount=1,iCount=1,oCount=1,uCount=1;
        int MOD = 1e9+7;
        for(int i=1;i<n;i++){
            long aCountNew=(eCount+iCount+uCount) % MOD;
            long eCountNew=(aCount+iCount) % MOD;
            long iCountNew=(eCount+oCount)  % MOD;
            long oCountNew=(iCount)  % MOD;
            long uCountNew=(iCount+oCount) % MOD;
            
            aCount=aCountNew;
            eCount=eCountNew;
            iCount=iCountNew;
            oCount=oCountNew;
            uCount=uCountNew;
        }
        
        long result=(aCount+eCount+iCount+oCount+uCount) % MOD;
        
        return result;
    }
};

//Bottom Up DP
//Time Complexity O(n)
//Space Comlexity O(n)
class Solution {
public:
    int countVowelPermutation(int n) {
        long a[n],e[n],i[n],o[n],u[n];
        a[0]=1;
        e[0]=1;
        i[0]=1;
        o[0]=1;
        u[0]=1;
        int MOD = 1e9+7;
        for(int x=1;x<n;x++){
            a[x]=(e[x-1]+i[x-1]+u[x-1]) % MOD;
            e[x]=(a[x-1]+i[x-1]) % MOD;
            i[x]=(e[x-1]+o[x-1])  % MOD;
            o[x]=(i[x-1])  % MOD;
            u[x]=(i[x-1]+o[x-1]) % MOD;
        }
        
        long result=(a[n-1]+e[n-1]+i[n-1]+o[n-1]+u[n-1]) % MOD;
        
        return result;
    }
};

class Solution {
public:
    using ll=long long;
    int mod=1e9+7;
    int countVowelPermutation(int n) {
        vector<vector<ll> >dp(n+1,vector<ll>(5));
        //dp[i][j]-> res for subproblem of length i ending with jth vowel
        //j=0 for 'a'
        //j=1 for 'e'
        //j=2 for 'i'
        //j=3 for 'o'
        //j=4 for 'u'
        dp[1][0]=dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i][0]=((dp[i-1][1]%mod+dp[i-1][2]%mod)%mod+dp[i-1][4]%mod)%mod;
            dp[i][1]=(dp[i-1][0]%mod+dp[i-1][2]%mod)%mod;
            dp[i][2]=(dp[i-1][1]%mod+dp[i-1][3]%mod)%mod;
            dp[i][3]=dp[i-1][2]%mod;
            dp[i][4]=(dp[i-1][2]%mod+dp[i-1][3]%mod)%mod;
            
        }
        return (dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4])%mod;
    }
};