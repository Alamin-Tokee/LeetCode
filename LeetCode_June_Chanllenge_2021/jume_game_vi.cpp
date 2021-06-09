class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        pq.push({nums[0],0});
        for(int i=1;i<n;i++){
            nums[i]+=pq.top().first;
            pq.push({nums[i],i});
            
            if(i-k>=0)
                while(pq.top().second <= i-k) pq.pop();
            
        }
        return nums[n-1];
    }
};