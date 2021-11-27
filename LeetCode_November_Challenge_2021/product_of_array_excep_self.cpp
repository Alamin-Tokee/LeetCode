class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int zeroCount=0;
        int total=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) zeroCount++;
            else total*=nums[i];
        }
        if(zeroCount > 1) return vector<int>(size(nums));
        for(int i=0;i<n;i++){
            if(zeroCount) nums[i] = nums[i] ? 0 : total;
            else nums[i] = total / nums[i];
        }
        return nums;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftProduct(n),rightProduct(n);
        leftProduct[0]=1;
        for(int i=1;i<n;i++){
            leftProduct[i]=leftProduct[i-1]*nums[i-1];
        }
        rightProduct[n-1]=1;
        for(int i=n-2;i>=0;i--){
            rightProduct[i]=rightProduct[i+1]*nums[i+1];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=leftProduct[i]*rightProduct[i];
        }
        return ans;
    }
};