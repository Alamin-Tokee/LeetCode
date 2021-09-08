//Time complexity O(n^2)(Bruth force)
//Space Complexity O(1)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int sum=0,k=1,c=1;
            for(int j=i;j<arr.size();j++){
                sum+=arr[j];
                if(c==k){
                    ans+=sum;
                    c+=2;
                }
                k++;
            }
        }
        return ans;
    }
};
//Time complexity O(n^2)(Bruth force)
//Space Complexity O(1)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int sum=0,c=0;
            for(int j=i;j<arr.size();j++){
                sum+=arr[j];
                c+=1;
                if(c%2){
                    ans+=sum;
                }
            }
        }
        return ans;
    }
};

//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            res+=((i+1)*(n-i)+1)/2*arr[i]; 
        }
        return res;
    }
};