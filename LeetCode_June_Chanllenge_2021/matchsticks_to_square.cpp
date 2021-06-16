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

// Important Note
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        
        if (nums.size() == 0)
            return false;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum % 4 != 0) return false;
        
        int target = sum / 4;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        if (any_of(nums.begin(), nums.end(), [&](int v) { return v > target; }))
            return false;
        
        int n = nums.size();
        
        vector<bool> visited(n, false);
        
        return find(nums, 4, target, 0, 0, visited);
    }
    
    bool find(vector<int>& nums, int k, int target, int sum, int start, vector<bool>& visited)
    {
        if (k == 1) return true;
        
        if (sum > target)
            return false;
        else if (sum == target)
        {
            return find(nums, k-1, target, 0, 0, visited);
        }
        
        for (int i = start; i < nums.size(); i++)
        {
            if (sum + nums[i] > target) continue;
            
            if (visited[i]) continue;
            
            visited[i] = true;
            
            if (find(nums, k, target, sum + nums[i], i+1, visited) ) return true;
            
            visited[i] = false;
        }
        
        return false;
    }
};