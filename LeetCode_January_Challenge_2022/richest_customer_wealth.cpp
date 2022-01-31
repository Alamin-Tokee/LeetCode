//TC O(M*N)
//SC O(1)

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi=INT_MIN;
        for(int i=0;i<accounts.size();i++){
            int sum=0;
            for(int j=0;j<accounts[i].size();j++){
                sum += accounts[i][j];
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};

//TC O(M*N)
//SC O(1)
class Solution{
public:
    int maximumWealth(vector<vector<int>> &accounts){
        int rich = 0, cashCount;
        for (auto &&bank : accounts){
            cashCount = 0;
            for (auto &&cash : bank)
                cashCount += cash;
            rich = max(rich, cashCount);
        }
        return rich;
    }
};


//TC O(M*N)
//SC O(1)
class Solution{
public:
    int maximumWealth(vector>& accounts) {
        int ans = 0;
        for(auto it:accounts){
            int sum = accumulate(it.begin(),it.end(),sum);
            ans = max(ans,sum);
        }
        return ans;
    }
};