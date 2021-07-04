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


//Top Down Dp Solution
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    const int mod = (int)1e9 + 7;
    int helper(int n, char i, unordered_map<char,vector<char>>& vc,vector<vector<long long>>& dp){
        if(n==0) return 1;
        if (dp[n][i-'a']!=0) return dp[n][i-'a']%mod;
        for(int j=0;j<vc[i].size();j++){
            dp[n][i-'a']+=(helper(n-1,vc[i][j],vc,dp))%mod;
        }
        return dp[n][i-'a']%mod;
    }
    
    int countVowelPermutation(int n) {
        unordered_map<char,vector<char>> vc;
        vc['a'].push_back('e');
        vc['e'].push_back('a');vc['e'].push_back('i');
        vc['i'].push_back('a');vc['i'].push_back('e');vc['i'].push_back('o');vc['i'].push_back('u');
        vc['o'].push_back('i');vc['o'].push_back('u');
        vc['u'].push_back('a');        
        vector<vector<long long>> dp(n+1,vector<long long>(26,0));
        long long c=0;
        for(auto it = vc.begin();it!=vc.end();it++){
            dp[n][it->first-'a']+=(helper(n-1,it->first,vc,dp))%mod;
            c += (dp[n][it->first-'a'])%mod;
        }
        return c%mod;
    }
};



//Matrix exponentiaton
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    const long long M= 1e9+7;
    vector<vector<long long>> matrixExponen(vector<vector<long long>>& A,vector<vector<long long>>& B){
        long long m=A.size(), n=A[0].size(),p=B[0].size();
        vector<vector<long long>> R(m, vector<long long> (p));
        for(long long i=0; i<m; i++){
            for(long long j=0;j<n;j++){
                for(long long k=0;k<p;k++){
                    R[i][k]+=A[i][j]*B[j][k];
                    R[i][k] %= M;
                }
            }
        }
        
        return R;
    }
    int countVowelPermutation(int n) {
        vector<vector<long long>> A({{0,1,1,0,1},
                                    {1,0,1,0,0},
                                    {0,1,0,1,0},
                                    {0,0,1,0,0},
                                    {0,0,1,1,0}
                                    });
        
        vector<vector<long long>> R({{1,0,0,0,0},
                                    {0,1,0,0,0},
                                    {0,0,1,0,0},
                                    {0,0,0,1,0},
                                    {0,0,0,0,1}
                                    });
    
        n--;
        while(n){
            if(n & 1){
                R=matrixExponen(R,A);
            }
            A=matrixExponen(A,A);
            n >>= 1;
        }

        //Using Recusion Tos Solve the matrix exponentiation
        // vector<vector<int>>power(vector<vector<int>>& a,int k){
        // if(k==1)return a;
        // vector<vector<int>>res=power(a,k/2);
        // if(k&1)
        // {
        //         return multiply(multiply(a,res),res);
        // }
        // else
        // {
        //         return multiply(res,res);
        // }
        // }
        
        
        
        long long res=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                res+=R[i][j];
                res%=M;
            }
        }
        return res;
    }
};