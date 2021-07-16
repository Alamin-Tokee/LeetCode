//Using hash and set
//Time complexity O(n^2)
//Space compleixty O(n)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>s;
        vector<vector<int>>ans;
        unordered_map<int,vector<pair<int,int>>>mp;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++) mp[nums[i]+nums[j]].push_back({i,j});
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(mp.find(target-(nums[i]+nums[j]))!=mp.end()){
                    vector<pair<int,int>>vec=mp[target-(nums[i]+nums[j])];
                    for(auto p:vec){
                        if(p.first!=i && p.first!=j && p.second!=i && p.second!=j){
                            vector<int>v={nums[p.first],nums[p.second],nums[i],nums[j]};
                            sort(v.begin(),v.end());
                            s.insert(v);
                        }
                    }
                }
            }
        }
        for(auto i:s) ans.push_back(i);
        return ans;
    }
};