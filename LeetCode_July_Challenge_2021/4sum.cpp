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



//Using hash and set
//Time complexity O(n^3)
//Space compleixty O(n)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target2=target-(nums[i]+nums[j]);
                int left=j+1;
                int right=n-1;
                while(left < right){
                    int two_sum=nums[left]+nums[right];
                    if(two_sum < target2) left++;
                    else if(two_sum > target2) right--;
                    else{
                        vector<int>res(4,0);
                        res[0]=nums[i];
                        res[1]=nums[j];
                        res[2]=nums[left];
                        res[3]=nums[right];
                        ans.push_back(res);
                        
                        while(left < right && nums[left]==res[2]) left++;
                        
                        while(left < right && nums[right]==res[3]) right--;
                    }
                }
                while(j+1 < n && nums[j+1]==nums[j]) ++j;
            }
            while(i+1 < n && nums[i+1]==nums[i]) ++i;
        }
        return ans;
    }
};


//Using hash and set
//Time complexity O(n^3)
//Space compleixty O(n)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<tuple<int,int,int,int>> vec;
        int d,q;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                d=j+1;
                q=n-1;
                while(d < q){
                    if((nums[i]+nums[j]+nums[d]+nums[q])==target){
                        vec.insert(make_tuple(nums[i],nums[j],nums[d],nums[q]));
                        d++;
                        q--;
                    }else if((nums[i]+nums[j]+nums[d]+nums[q]) < target){
                        d++;
                    }else{
                        q--;
                    }
                }
            }
        }
        int sz=vec.size();
        vector<vector<int>> v(sz,vector<int>(4));
        int i=0;
        for(auto it:vec){
           v[i][0]=get<0>(it);
           v[i][1]=get<1>(it); 
           v[i][2]=get<2>(it);
           v[i][3]=get<3>(it);
           i++; 
        }
        
        return v;
    }
};