//TC O(n)
//SC O(n)

class Solution {
public:
    int countOrders(int n) {
        vector<long> dp(n+1,0);
        int mod = 1e9+7;
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            dp[i] = i*dp[i-1]*(2*i-1)%mod;
        }
        return dp[n];
    }
};

//TC O(n)
//SC O(1)
class Solution{
public:
    int countOrders(int n) {
        long ans = 1, mod = 1e9 + 7;
        for(int i=1;i<=n;i++){
            ans *= i; // ith pickup
            ans *= 2*i - 1; // ith delivery
            ans %= mod;
        }
        return ans;
    }
};


// i = 1*2+1 = 3;
// 3*4 = 12 / 2= 6;

// temp = 5
// temp = 5*6/2 = 30/2= 15 * 6 =  90

// ans = 1;
// ans = 1*(2*1)-1 = 1
// ans = 1

// ans = 1*2 = 2;
// ans = 2*3 = 6


//TC O(n)
//SC O(1)
class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9 + 7;
        long res = 1;
        for(int i = 1; i < n; i++){
            int temp = i*2+1;
            temp = (temp * (temp + 1))/2;
            res = (res * temp) % mod;
			res %= mod;
        }
        return res;
    }
};




