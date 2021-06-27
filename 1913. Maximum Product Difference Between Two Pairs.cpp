class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        return (nums[n-1]*nums[n-2])-(nums[0]*nums[1]);
        
        
        // int firstMin=INT_MAX,secondMin=INT_MAX,firstMax=INT_MIN,secondMax=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]>firstMax){
        //         secondMax=firstMax;
        //         firstMax=nums[i];
        //     }else if(nums[i]>secondMax){
        //         secondMax=nums[i];
        //     }
        //     if(nums[i]<firstMin){
        //         secondMin=firstMin;
        //         firstMin=nums[i];
        //     }else if(nums[i]<secondMin)
        //         secondMin=nums[i];
        // }
        // return (firstMax*secondMax-firstMin*secondMin);

    }
};