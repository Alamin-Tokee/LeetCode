//Time Complexity O(n)
//Space Complexity O(n)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums1[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]]){
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return ans;
    }
};

//Time Complexity O(n^2)
//Space Complexity O(1)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nums1[i]);
                    nums1[i]=-1;
                    nums2[j]=-2;
                    continue;
                }
            }
        }
        return ans;
    }
};
