//Brute Force Solution
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int i=0;
        int j=0;
        int n=a.size();
        int zero=0;
        int ans=INT_MIN;
        
        while(j<n){
            if(zero < k){
                if(!a[j]) zero++;  
                j++;
            }
            else if(zero==k){
                if(a[j]) j++;
                else if(a[i]) i++;
                else if(!a[i]){
                    zero--;
                    i++;
                }
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};