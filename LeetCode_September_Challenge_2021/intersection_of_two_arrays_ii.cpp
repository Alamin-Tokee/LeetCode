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


//Time Complexity O(logn)
//Space Complexity O(1)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(ans));
        return ans;
    }
}


//Time Complexity O(n) (Two Pointer Approach)
//Space Complexity O(1)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());   //sort the arrays
        sort(nums2.begin(),nums2.end());
        vector<int>ans;
        int i=0;
        int j=0;
        int m=nums1.size();
        int n=nums2.size();
        while(i<m and j<n){
            if(nums1[i]==nums2[j])          //if the values are equal , we insert the value into the array 
			{
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])      //else we keep on increasing the pointer accordingly 
			{                                               
                i++;
            }
            else
			{
                j++;
            }
        }
        return ans;
    }
};