class Solution {
public:
    int numSquares(int n) {
        unordered_set<int>visited;
        vector<int>vec;
        queue<int>q;
        int step=1;
        for(int i=1;i*i<=n;i++){
            if(i*i==n) return step;
            q.push(i*i);
            vec.push_back(i*i);
            visited.insert(i*i);
        }
        
        while(!q.empty()){
            step+=1;
            int size=q.size();
            for(int i=0;i<size;i++){
                int num=q.front();
                for(int key:vec){
                    int sum=num+key;
                    if(sum==n) return step;
                    if(sum < n and !visited.count(sum)){
                        q.push(sum);
                        visited.insert(sum);
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};


class Solution {
public:
    int solve(vector<int>&coins,int amount){
        int n=coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0) dp[i][j] = INT_MAX - 1;
                if(j==0) dp[i][j] = 0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1] <= j) {
                    dp[i][j] = min((dp[i][j-coins[i-1]]+1) , dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
    }
    vector<int>helper(int n){
        vector<int>v;
        for(int i=1;i*i<=n;i++){
            v.push_back(i*i);
        }
        return v;
    }
    int numSquares(int n) {
        vector<int>ans=helper(n);
        int res=solve(ans,n);
        return res;
    }
};



class Solution {
private:
    int solve(vector<int>& coins, int w,int n,vector<vector<int>>&memo){
        if(n==0 || w==0){
           return w==0? 0:INT_MAX - 1;
        }
        if(memo[w][n]!=-1) return memo[w][n];
        if(coins[n-1]>w){
            return memo[w][n] = 0 + solve(coins,w,n-1,memo);
        }
        else return memo[w][n] = min(0+solve(coins,w,n-1,memo),1+solve(coins,w-coins[n-1],n,memo));
    }
private:
    vector<int>helper(int n){
        vector<int>v;
        for(int i=1;i*i<=n;i++){
            v.push_back(i*i);
        }
        return v;
    }
public:
    int numSquares(int n) {
        vector<int>ans=helper(n);
        vector<vector<int>>memo(n+1,vector<int>(ans.size()+1,-1));
        int res=solve(ans,n,ans.size(),memo);
        return res;
    }
};