//Recursive and Memoization Solution
//TC O(n)
//SC O(n)
class Solution { // 0 ms, faster than 100.00%
public:
    int n;
    vector<int>dp;
    int helper(string s,int index){
        if(index >= n) return 1;
        
        if(dp[index]!=-1) return dp[index];
        
        if(s[index]=='0') return 0;
        
        dp[index]=helper(s,index+1);
        
        if(index+1<n){
            int number=0;
            number += (s[index]-'0');
            number *= 10;
            number += (s[index+1]-'0');
            if(number >= 10 && number <= 26){
                dp[index] += helper(s,index+2);
            }
        }
        return dp[index];
    }
    int numDecodings(const string& s) {
        n=s.size();
        dp.resize(n+1,-1);
        return helper(s,0);
    }
};


class Solution { // 12 ms, faster than 9.19%
public:
    int memo[100] = {};
    int numDecodings(const string& s) {
        return dp(s, 0);
    }
    int dp(const string& s, int i) {
        if (i == s.size()) return 1;
        if (memo[i] != 0) return memo[i];
        int ans = 0;
        if (s[i] != '0') // Single digit
            ans += dp(s, i+1);
        if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
            ans += dp(s, i+2);
        return memo[i] = ans;
    }
};