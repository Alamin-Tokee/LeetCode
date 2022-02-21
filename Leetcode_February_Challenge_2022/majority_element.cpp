//TC O(n)
//SC O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int c=INT_MIN;
        int val;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        //for(auto& b:mp){
          //  cout<<b.first<< "  "<<b.second<<endl;
        //}
        //it=mp.begin();
        for(auto& a:mp){
            if(a.second>c){
                c=a.second;
                val=a.first;
            }
        }
        return val;
    }
};


//Boyer moore
//TC O(n)
//SC O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans, count = 0;
        for(auto &x:nums){
            if(count == 0) ans = x;
            
            if(x == ans) count++;
            else count--;
        }
        return ans;
    }
};