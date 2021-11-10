class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            if(maxProfit > prices[i]){
                maxProfit=prices[i];
            }
            if(maxProfit < prices[i]){
                ans+=prices[i]-maxProfit;
                maxProfit=prices[i];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i < prices.size() - 1) {
            while (i < prices.length - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < prices.length - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }
};




class Solution {
public:
    int find(int idx,vector<int>&v,bool buy,vector<vector<int>>&m){
        if(idx>=v.size()) return 0;
        if(m[idx][buy]!=-1) return m[idx][buy];
        
        if(buy){
            return m[idx][buy]=max(-v[idx]+find(idx+1,v,!buy,m),find(idx+1,v,buy,m));
        }else{
            return m[idx][buy]=max(v[idx]+find(idx+1,v,!buy,m),find(idx+1,v,buy,m));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        vector<vector<int>>v(n+1,vector<int>(2,-1));
        
        return find(0,prices,1,v);
    }
};