class Solution {
public:
    bool dfs(vector<int>& arr,int cur,vector<bool>&vis){
        if(cur < 0 || cur >= arr.size() || vis[cur]) return false;
        
        if(arr[cur]==0) return true;
        vis[cur]=true;
        
        return dfs(arr,cur+arr[cur],vis) || dfs(arr,cur-arr[cur],vis);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool>visited(arr.size(),false);
        
        return dfs(arr,start,visited);
    }
};