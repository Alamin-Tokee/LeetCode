//First Approach

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int f1=0,f2=0;
        
        for(int i=0;i<n;i++){
            int f3=cost[i]+min(f1,f2);
            f2=f1;
            f1=f3;
        }
        
        return min(f1,f2);
    }
};