// DP solution
// Time Complexity O(N^2)
// Space Complexity o(N)

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        
        vector<long>dp(n+1);
        dp[0]=startFuel;
        
        for(int i = 0; i < n; i++){
            for(int j = i; j >= 0; j--){
                if(dp[j] >= stations[i][0]){
                    dp[j+1] = max(dp[j+1], dp[j]+stations[i][1]);
                }
            }
        }
        
        
        for(int i=0;i<dp.size();i++){
            if(dp[i]>=target) return i;
        }
        return -1;
	}
};

// Priority Queue solution(Max Heap)
// Time Complexity O(NlogN)
// Space Complexity o(N)

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int distance=startFuel;
        int i=0,ans=0;
        
        while(distance < target){
            while(i < stations.size() && stations[i][0] <= distance){
                pq.push(stations[i++][1]);
            }
            if(pq.empty()) return -1;
            distance+=pq.top();
            pq.pop();
            ans++;
        }
        
        return ans;
    }
};
