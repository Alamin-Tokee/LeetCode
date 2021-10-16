class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>ans;
        int lsf=INT_MAX,hsf=INT_MIN;  ////lowestSoFar and highestSoFar
        int profit1=0,profit2=0;
        for(int i=0;i<prices.size();i++){
            lsf=min(lsf,prices[i]);
            profit1=max(profit1,prices[i]-lsf);
            ans.push_back(profit1);
        }
        for(int i=prices.size()-1;i>=0;i--){
            hsf=max(hsf,prices[i]);
            profit2=max(profit2,hsf-prices[i]);
            ans[i]+=profit2;
        }
        return *max_element(ans.begin(),ans.end());
    }
};
