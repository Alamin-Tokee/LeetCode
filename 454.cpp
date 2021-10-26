class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[nums1[i]+nums2[j]]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=mp[-(nums3[i]+nums4[j])];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> s;
        for(int i=0; i<nums3.size(); i++)
            for(int j=0; j<nums4.size(); j++)
                s[nums3[i] + nums4[j]]++;
        
        int count = 0;
        for(int i=0; i<nums1.size(); i++)
            for(int j=0; j<nums2.size(); j++)
                if(s.find(- nums1[i] - nums2[j]) != s.end())
                    count += s[- nums1[i] - nums2[j]];
        
        return count;    
    }
};


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
       unordered_map<int, int> hmap; 
       for( auto a: nums1){
           for(auto b: nums2){
               ++hmap[a+b]; 
           }
       }
        
      int count = 0;
      for(auto c: nums3){
          for(auto d: nums4){
              auto iter = hmap.find(0-c-d);
              if(iter != hmap.end() ){ 
                  count+= iter->second; 
              }
          }
      }
    return count;
    }
};