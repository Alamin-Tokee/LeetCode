//Time Complexity O(n)
//Spacee Complexity O(n)

class Solution {
public:
    int dfs(vector<int>& nums,vector<bool>& visited,int x){
        if(visited[x]==true) return 0;
        visited[x]=true;
        return 1+dfs(nums,visited,nums[x]);
    }
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visited(n,false);
        int ans = 0;
        int temp = 0;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                temp=dfs(nums,visited,nums[i]);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};