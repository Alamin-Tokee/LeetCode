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

//Intution Solution
vector<int> adj[(int) 1e5 + 10];
    bool visited[(int) 1e5 + 10];
  
    int cc_size; // stores the size of the current connected component
    void dfs(int node) {
      visited[node] = true;
      cc_size++;
      for (auto &child: adj[node]) {
        if (!visited[child]) {
          dfs(child);
        }
      }
    }
  
    int arrayNesting(vector<int>& nums) {
      const int N = 1e5 + 10;
      fill(visited, visited + N, false);
      
      // build the graph
      for (int i = 0; i < nums.size(); i++) {
        if (visited[nums[i]]) continue;
        for (int node = nums[i]; !visited[node]; node = nums[node]) {
          visited[node] = true;
          adj[node].push_back(nums[node]);
        } 
      }       
      
      fill(visited, visited + N, false);
      int ans = 0;
      for (auto &ai: nums) {
        if (visited[ai]) continue;
        cc_size = 0;
        dfs(ai);
        ans = max(ans, cc_size);
      }
      
      return ans;
    }

//Time Complexity O(n)
//Spacee Complexity O(n)
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

//Time Complexity O(n)
//Spacee Complexity O(1)
class Solution {
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int ans = 0;
        for(int x:nums){
            if(x == -1) continue;
            int cnt = 0;
            while(nums[x]!=-1){
                cnt+=1;
                int prev=x;
                x = nums[x];
                nums[prev] = -1;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};

