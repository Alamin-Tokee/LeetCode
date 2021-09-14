//Run Time Error(Intution)

class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long int product=1;
        for(int i=0;i<nums.size();i++){
            product*=nums[i];
        }
        
        return product <= 0 ? product == 0 ? 0 : -1 : 1;
    }
};

//Better Approach
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) return 0;
            if(nums[i] < 0) count++;
        }
        
        return count % 2 == 0 ? 1 : -1;
    }
};