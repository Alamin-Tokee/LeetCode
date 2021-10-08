class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>num;
        vector<int>zero;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]) num.push_back(nums[i]);
            else zero.push_back(nums[i]);
        }
        nums.clear();
        for(int i=0;i<num.size();i++){
            nums.push_back(num[i]);
        }
        
        for(int i=0;i<zero.size();i++){
            nums.push_back(zero[i]);
        }
    }
};


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        
        int i=0,j=0;
        
        while(i < n){
            if(nums[i]){
                swap(nums[j++],nums[i++]);
            }else{
                i++;
            }
        }
    }
};


void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        
        int i=0,j=0;
        
        for(;i < n;){
            if(nums[i]){
                nums[j++]=nums[i++];
            }else{
                i++;
            }
        }
        
        for(int i=j;i<n;i++){
            nums[i]=0;
        }
    }
};


void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }
 	
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
    }
}