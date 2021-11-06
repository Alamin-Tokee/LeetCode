class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>>vec;
        for(int i=0;i<=n;i++){
            vec.push_back(vector<int>());
            for(int j=0;j<=i;j++){
                if(j==0){
                    vec[i].push_back(1);
                }
                else if(i==j){
                    vec[i].push_back(1);
                }
                else{
                    vec[i].push_back(vec[i-1][j]+vec[i-1][j-1]);
                }
            }
        }
        return vec[n];
    }
};

class Solution {
public:
    vector<int> getRow(int n) {
        std::vector<std::vector<int>> dp;
        for (int i = 0; i <= n; i++){
            std::vector<int> row(i + 1);
            dp.push_back(row);
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=i;j++){
                if(j==0 or j==i) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
        return dp[n];
    }
};
