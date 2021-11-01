//Optimal Solution
//Time O(n)
//Space O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minprice=INT_MAX;
        int maxprofit=0;
        for(int i=0;i<n;i++){
            if(minprice > prices[i]){
                minprice=prices[i];
            }
            if(prices[i]-minprice > maxprofit){
                maxprofit=max(maxprofit,prices[i]-minprice);
            }
        }
        return maxprofit;
    }
};

//Brute Force Solution
//Worst case 
//n(n-1)/2
//O(n)
//O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
        return maxprofit;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)return 0;
        int n=prices.size();
        vector<int> aux(n);
        aux[n-1]=prices[n-1];
        for(int i=prices.size()-2;i>=0;i--)
        {
            aux[i] = max(prices[i],aux[i+1]);
        }
        int mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(mx < (aux[i]-prices[i]))
            {
                mx = aux[i]-prices[i];
            }
        }
        return mx;
    }
};