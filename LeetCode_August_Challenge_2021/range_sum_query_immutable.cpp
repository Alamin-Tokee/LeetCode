
//TC O(n)
//Space O(1)
class NumArray {
public:
    vector<int>bt;
    NumArray(vector<int>& nums) {
        bt=nums;
       for(int i=0;i<nums.size();i++){
           if(i==0) bt.push_back(nums[i]);
           else bt[i]=bt[i-1]+nums[i];
       }
    }
    int sumRange(int left, int right) {
        if(left==0) return bt[right];
        
        return bt[right]-bt[left-1];
    }
};