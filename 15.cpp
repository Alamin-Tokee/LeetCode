//TLE

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<pair<int,int>,pair<int,int>>mp;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i!=j){
                    mp[{nums[i],nums[j]}]={i,j};
                }
            }
        }
        set<vector<int>>v;
        for(int k=0;k<nums.size();k++){
            for(auto m:mp){
                vector<int>temp;
                if(k!=m.second.first and k!=m.second.second and m.first.first+m.first.second+nums[k]==0){
                    temp.push_back(m.first.first);
                    temp.push_back(m.first.second);
                    temp.push_back(nums[k]);
                    sort(temp.begin(),temp.end());
                    v.insert(temp);
                }
            }
        }
        vector<vector<int>> res;
        for(auto i=v.begin(); i!=v.end(); i++){
            res.push_back(*i);
        }
        return res;
    }
};



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>v;
        int l,r;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            l=i+1;
            r=n-1;
            
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    v.insert({nums[i],nums[l],nums[r]});
                    l++,r--;
                }
                else if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }else{
                    l++;
                }
            }
            
        }
        vector<vector<int>> res;
        for(auto i=v.begin(); i!=v.end(); i++){
            res.push_back(*i);
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i==0 || nums[i]!=nums[i-1])
            //if(idx > 0 && nums[idx] == nums[idx - 1]) continue;
            {int l=i+1;
            int r=n-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    res.push_back({nums[i],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1]) ++l;
                    while(l<r && nums[r]==nums[r-1]) --r;
                    ++l,--r;
                }
                else if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }else{
                    l++;
                }
            }
            }
            
        }
        return res;
    }
};