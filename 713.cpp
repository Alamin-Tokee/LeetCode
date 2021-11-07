
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& A, int k) {
        if(k<=1) return 0;
        int prod=1,ans=0,left=0;
        for(int right=0;right<A.size();right++){
            prod *= A[right];
            while(left <= right && prod >= k) prod /= A[left++];
            ans+=(right-left)+1;
        }
        return ans;
    }
};
