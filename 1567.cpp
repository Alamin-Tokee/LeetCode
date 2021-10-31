class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size();
        int lastZero=-1;
        int firstNeg=-1;
        int maxLen=0;
        int noOfNeg=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                noOfNeg++;
                if(firstNeg==-1){
                    firstNeg=i;
                }
            }
            if(nums[i]==0){
                noOfNeg=0;
                firstNeg=-1;
                lastZero=i;
            }
            
            if(noOfNeg%2==0){
                maxLen=max(maxLen,i-lastZero);
            }else{
                maxLen=max(maxLen,i-firstNeg);
            }
        }
        return maxLen;
    }
};


class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int positiveProLen=0;
        int negativeProLen=0;
        int result=0;
        for(auto num:nums){
            if(!num){
                positiveProLen=negativeProLen=0;
            }else if(num < 0){
                swap(positiveProLen,negativeProLen);
                positiveProLen=positiveProLen ? positiveProLen+1 : 0;
                negativeProLen=negativeProLen+1;
            }else{
                positiveProLen=positiveProLen+1;
                negativeProLen=negativeProLen ? negativeProLen+1 : 0;
            }
            result=max(result,positiveProLen);
        }
        return result;
    }
};