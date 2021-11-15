class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>len(n+5,0);
        vector<int>parent(n+5,0);
        
        for(int i=0;i<n;i++){
            len[i]=1;
            parent[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && len[i] < len[j]+1){
                    len[i]=len[j]+1;
                    parent[i]=j;
                }
            }
        }
        int node=0,mx=0;
        for(int i=0;i<n;i++){
            if(len[i]>=mx){
                mx=len[i];
                node=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[node]);
        while(parent[node]!=node){
            ans.push_back(nums[parent[node]]);
            node=parent[node];
        }
        
        return ans;
    }
};