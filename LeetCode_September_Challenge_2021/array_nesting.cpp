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

//Time Complexity O(n)
//Spacee Complexity O(1)
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visited(n,false);
        int ans = 0;
        for(int x:nums){
            int cnt = 0;
            while(!visited[x]){
                cnt+=1;
                visited[x] = true;
                x = nums[x];
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};