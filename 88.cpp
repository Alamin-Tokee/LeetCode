class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        // vector<int>num(nums1.begin(),nums1.end());
        vector<int>num(n+m);
        int k=0;
         while(i<m and j<n)
        {
            if(nums1[i]<nums2[j]){
                num[k++]=nums1[i++];
            }
            else{
                num[k++]=nums2[j++];
            }
        }
        while (i < m) num[k++]=nums1[i++];
        while (j < n) num[k++]=nums2[j++];
        for(int i=0;i<nums1.size();i++){
            nums1[i]=num[i];
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 and j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k--]=nums1[i--];
            }
            else
            {
                nums1[k--]=nums2[j--];
            }
        }
        while(i>=0)
        {
            nums1[k--]=nums1[i--];
        }
        while(j>=0)
        {
            nums1[k--]=nums2[j--];
        }
    }
};

