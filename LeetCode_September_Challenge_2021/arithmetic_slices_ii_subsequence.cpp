//Time Complexity O(n^2)
//Space Complexity O(n^2)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n < 3) return 0;
        int ans=0;
        vector<unordered_map<long long int,long long int>>dp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long int diff=(long long)nums[i] - (long long)nums[j];
                dp[i][diff]++;
                if(dp[j].find(diff)!=dp[j].end()){
                    dp[i][diff]+=dp[j][diff];
                    ans+=dp[j][diff];
                }
            }
        }
        return ans;
    }
};


//Dfs Sample Solution (Invalid)
class Solution {
public:
    unordered_map<pair<int,long long>,int>mp;
    int dfs(int index,int last,long long diff,vector<int>& A){
        if(index==A.size()) return 0;
        
        pair<int,long long> pr={last,diff};
        if(mp[pr]) return mp[pr];
        
        int local;
        for(int next=index;next<A.size();next++){
            if((long long)A[next]-A[last]==diff){
                local+=dfs(next+1,next,diff,A)+1;
            }
        }
        mp[pr]=local;
        return local;
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        if(n < 3) return 0;
        int total=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                total+=dfs(j+1,j,(long long)A[i]-A[j],A);
            }
        }
        return total;
    }
};

//Slow Slution
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int i, j, k, n = A.size(), ans = 0;
        vector<vector<int>> d(n, vector<int>(n, 0));
        for (i = 0; i < n - 2; i++) {
            for (j = i + 1; j < n - 1; j++) {
                for (k = j + 1; k < n; k++) {
                    if ((long long)A[i] - A[j] == (long long)A[j] - A[k]) {
                        d[j][k] = d[j][k] + d[i][j] + 1;
                    }
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                ans += d[i][j];
            }
        }
        return ans;
    }
};