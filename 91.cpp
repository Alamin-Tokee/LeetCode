class Solution {
public:
    int numDecodings(string s) {
        
        if(s.length()==0 || s[0]=='0') return 0;
        
        if(s.length()==1) return 1;
        
        int count1 = 1,count2 = 1;
        
        for(int i=1;i<s.length();++i){
            int d=s[i]-'0';
            int dd=((s[i-1]-'0')*10)+d;
            int count=0;
            if(d > 0) count+=count2;
            if(dd >= 10 && dd <= 26) count+=count1;
            count1=count2;
            count2=count;

        }
        return count2;
    }
};


class Solution { // 0 ms, faster than 100.00%
public:
    int numDecodings(const string& s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0') // Single digit
                dp[i] += dp[i+1];
            if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};


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



class Solution {
public:
    int numDecodings(string s) {
         int n = s.size();
    
        // int count[n+1];
        vector<int>count(n+1,0);
        count[0] = 1;
        count[1] = 1;
    
        if(s[0]=='0') return 0;
    
        for (int i = 2; i <= n; i++){
            if (s[i-1] > '0') 
                count[i] = count[i-1];
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7') )
                count[i] += count[i-2];
        }
        return count[n];
    }
};