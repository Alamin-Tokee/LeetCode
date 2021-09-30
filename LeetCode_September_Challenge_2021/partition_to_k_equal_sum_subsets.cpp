class Solution {
    int total;
    int target;
    vector<bool>used;
public:
    bool dfs(vector<int>&nums,int cur,int k,int sum){
        if(k==0) return true;
        
        if(sum > target) return false;
        else if(sum==target){
            --k;
            return dfs(nums,0,k,0);
        }
        
        for(int i=cur;i<nums.size();i++){
            if(!used[i]){
                used[i]=true;
                if(dfs(nums,i+1,k,sum+nums[i])){
                    return true;
                }
                used[i]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        total=accumulate(nums.begin(),nums.end(),0);
        
        if(total % k != 0) return false;
        
        target=total/k;
        
        sort(nums.rbegin(),nums.rend());
        
        used.resize(nums.size(),false);
        
        return dfs(nums,0,k,0);
    }
};



class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if (nums.size() < k || sum % k) return false;
        
        vector<int> visited(nums.size(), false);
        return backtrack(nums, visited, sum / k, 0, 0, k);
    }
    
    bool backtrack(vector<int>& nums,vector<int>visited, int target, int curr_sum, int i, int k) {
        if (k == 1) 
            return true;
        
        if (curr_sum == target) 
            return backtrack(nums, visited, target, 0, 0, k-1);
        
        for (int j = i; j < nums.size(); j++) {
            if (visited[j] || curr_sum + nums[j] > target) continue;
            
            visited[j] = true;
            if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k)) return true;
            visited[j] = false;
        }
        
        return false;
    }
};



class Solution {
public:
    bool possible(vector<int>&m,int i,int mask,int sum,int a,int c,int k)
    {
        if(c==k )return true;
        if(sum==a){
            return possible(m,0,mask,0,a,c+1,k);
        }
        if(i>=m.size())
            return false;
        for(;i<m.size();i++)
        {
            if(!(mask&(1<<i))&&(sum+m[i])<=a)
            {
                if(possible(m,i+1,mask|1<<i,sum+m[i],a,c,k))
                return true;
            }
        }
        return false;
        
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int N=nums.size();
        for(int i=0;i<N;i++)
        sum+=nums[i];
        if(sum%k!=0)
        return false;
         int a=sum/k;
        int mask=0;
        return (possible(nums,0,mask,0,a,0,k));
            
    }
};



class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        int c = sum / k;
        if (c * k != sum) return false;
        vector<int> dp(1 << n);
        for (int i = 1; i < 1 << n; i++) {
            dp[i] = sum;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) && dp[i ^ (1 << j)] + nums[j] <= c) {
                    auto a = dp[i ^ (1 << j)];
                    a = (a + nums[j]) % c;
                    dp[i] = min(dp[i], a);
                }
            }
        }
        return !dp.back();
    }
};