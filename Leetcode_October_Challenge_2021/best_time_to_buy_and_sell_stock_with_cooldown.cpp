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
        }
        return max(sold, rest);
    }
};