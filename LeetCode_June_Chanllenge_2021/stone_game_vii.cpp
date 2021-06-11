//Top Down Approach 
//Time Complexity O(n^2)
//Space complexity O(n^2)
class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>& st,int i,int j,int sum){
        if(i>=j) return 0;
        
        if(sum<=0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int choose_front=sum-st[i]-solve(st,i+1,j,sum-st[i]);
        int choose_back=sum-st[j]-solve(st,i,j-1,sum-st[j]);
        
        int profit=max(choose_front,choose_back);
        return dp[i][j]=profit;
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        // for(int i=0;i<n;i++){
        //     sum+=stones[i];
        // }
        sum=accumulate(stones.begin(),stones.end(),0);
        
        memset(dp ,-1,sizeof(dp));
        
        int val=solve(stones,0,n-1,sum);
        
        return val;
    }
};

//Bottom Up Approach 
//Time Complexity O(n^2)
//Space complexity O(n^2)
class Solution {
public:
    int stoneGameVII(vector<int>& A) {
        int N = A.size();
        vector<int> store(N + 1);
        for (int i = 0; i < N; ++i) store[i + 1] = store[i] + A[i];
        vector<vector<int>> dp(N, vector<int>(N));
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i <= N - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = max(store[j + 1] - store[i + 1] - dp[i + 1][j], store[j] - store[i] - dp[i][j - 1]);
            }
        }
        return dp[0][N - 1];
    }
};
