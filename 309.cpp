class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rest = 0, hold = rest - prices[0], sold = hold + prices[0];
        //only an action a day (cd = 1)
        //hold => sell or rest, sold => rest, rest => buy or rest
        for(int i = 1; i < prices.size(); ++i)
        {
            int preSold = sold;
            sold = hold + prices[i];            //sold[i] = hold[i-1] + prices[i]
            hold = max(hold, rest - prices[i]); //hold[i] = max(hold[i-1], rest[i-1] - prices[i])
            rest = max(rest, preSold);          //rest[i] = max(rest[i-1], sold[i-1])
            cout<<sold <<" "<< hold << " "<< rest << endl;
        }
        return max(sold, rest);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <  2) return 0;
        
        vector<vector<int>>dp(prices.size(),vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = max(dp[0][1], -prices[1]);
        
        for(int i=2;i<prices.size();i++){
            dp[i][0]=max(dp[i-1][0],prices[i]+dp[i-1][1]);
            dp[i][1]=max(dp[i-1][1],-prices[i]+dp[i-2][0]);
        }
        return dp[prices.size()-1][0];
    }
};