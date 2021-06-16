class Solution {
public:
    bool solve(int idx, vector <int>& sums, int target, vector <int>& nums){
        if(idx>=nums.size()){
            return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == target;
        }
        for(int i=0;i<4;i++){
            if(sums[i]+nums[idx] > target) continue;
            sums[i]+=nums[idx];
            if(solve(idx + 1, sums, target, nums)) return true;
            sums[i]-= nums[idx]; 
        }
        return false;
    } 
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()==0) return false;
        
        int x;
        for(int i=0;i<matchsticks.size();i++){
            x+=matchsticks[i];
        }
        
        if(x%4) return false;
        sort(matchsticks.rbegin(),matchsticks.rend());
        
        vector<int>sum(4);
        
        return solve(0,sum,x/4,matchsticks);
    }
};