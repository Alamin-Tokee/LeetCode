class Solution {
public:
    bool enough(int x,int m,int n,int k){
        int count = 0;
        for(int i = 1; i <= m; i++){
            count+=min(x/i,n);
        }
        return count >= k;
    }
    int findKthNumber(int m, int n, int k) {
        int lo=1,hi=m*n;
        while(lo<hi){
            int mi=lo+(hi-lo)/2;
            if(!enough(mi,m,n,k)) lo=mi+1;
            else hi=mi;
        }
        return lo;
    }
};

//Memory Limit Exceded
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int dp[m*n];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[(i-1)*n+j-1] = i*j;
            }
        }
        sort(dp.begin(),dp.end());
        sort(dp,dp+(m*n);
        return lo;
    }
};