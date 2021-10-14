//BFS Solution
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
//Memoization Tecnique

class Solution {
public: 
    int dp[101][10001];
    int knapsack(int W, int n){
        if(W==0 || n==0)
            return INT_MAX;
        if(dp[n][W]!=-1)
            return dp[n][W];
        int ps=n*n;
        if(ps<=W){
            int temp=knapsack(W-ps, n);
            return dp[n][W]=min(1+(temp==INT_MAX?0:temp),knapsack(W,n-1));
        }
        else
            return dp[n][W]=knapsack(W,n-1);
    }
    int numSquares(int n){
        memset(dp, -1, sizeof(dp));
        return knapsack(n,(int)sqrt(n));
    }
};

//Tabular Method
class Solution {
public: 
    int numSquares(int n){
        int sq_root=(int)sqrt(n);
        int dp[sq_root+1][n+1];
        
        for(int i=0;i<=sq_root;i++)
            for(int j=0;j<=n;j++)
                if(i==0 || j==0)
                    dp[i][j]=INT_MAX;
        
        for(int i=1;i<=sq_root;i++){
            for(int j=1;j<=n;j++){
                int ps=i*i;
                if(ps<=j)
                    dp[i][j]=min(1+(dp[i][j-ps]==INT_MAX?0:dp[i][j-ps]), dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }       
        return dp[sq_root][n];
    }
};

