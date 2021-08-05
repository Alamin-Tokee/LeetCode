//Math Solution
//Time Complexity O(1)
//Space Complexity O(1)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

//Math Solution
//Time Complexity O(n*n)
//Space Complexity O(n*n)
class Solution {
public:
    int dp[1005][1005];
    
    int f(int l, int r, vector <int> &piles) {
        if(l == r-1) return max(piles[l], piles[r]);
        
        if(dp[l][r] != -1) return dp[l][r];
        
        int ifleft = piles[l] + max(f(l+2, r, piles), f(l+1, r-1, piles));
        int ifright = piles[r] + max(f(l+1, r-1, piles), f(l, r-2, piles));
        
        return dp[l][r] = max(ifleft, ifright);
    }
    bool stoneGame(vector<int>& piles) {
        int l = 0, r = piles.size()-1;
        memset(dp, -1, sizeof(dp));
        int alex = f(l, r, piles);
        int sum = 0;
        for(int i=0;i<piles.size();i++) sum += piles[i];

        return alex > (sum - alex);
    }
};


class Solution {
public:
    unordered_map<int, int> memo;
    int dfs(vector<int> &piles, int index) {
        if (index == piles.size() / 2) return 0;
        if (memo.count(index)) return memo[index];
        int n = piles.size() - 1;
        int l = piles[index] + dfs(piles, index + 1);
        int r = piles[n - index] + dfs(piles, index + 1);
        return memo[index] = max(l, r);
    }
    bool stoneGame(vector<int>& piles) {
        return dfs(piles, 0) * 2 > accumulate(begin(piles), end(piles), 0);
    }
};
