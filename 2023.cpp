class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    mp[nums[i]+nums[j]]++;
                }
            }
        }
        
        return mp[target];
    }
};


class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> freq;
        for (auto num : nums) if (num.size() < target.size()) freq[num]++;
        
        int res = 0;
        for (auto [s, frq] : freq) {
            
            if (target.find(s) == 0) {
                
                if (s + s == target) 
                    res += frq*(frq-1);
                
                else 
                    res += frq * freq[target.substr(s.size())];
            }
        }
        
        return res;
    }
};
   