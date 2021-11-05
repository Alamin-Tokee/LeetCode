
//Gives TLE
class Solution {
public:
    int partitionFunction(vector<int>&nums,int start,int end){
        int pivotValue=nums[end];
        int partitionIndex=start;
        for(int i=start;i<end;i++){
            if(nums[i] <= pivotValue){
                swap(nums[partitionIndex],nums[i]);
                partitionIndex++;
            }
        }
        swap(nums[partitionIndex],nums[end]);
        
        return partitionIndex;
    }
    void quickSort(vector<int>&nums,int start,int end){
        if(start < end){
            int partitionIndex=partitionFunction(nums,start,end);
            quickSort(nums,start,partitionIndex-1);
            quickSort(nums,partitionIndex+1,end);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        
        return nums;
    }
};

//Better Solution
class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r){
        vector<int> tmp(r - l + 1);
        int i = l; 
        int j = m + 1; 
        int k = 0; 
        while(i <= m && j <= r){
            if(nums[i] <= nums[j]) tmp[k++] = nums[i++]; 
            else tmp[k++] = nums[j++];
        }
        while(i <= m) tmp[k++] = nums[i++];
        while(j <= r) tmp[k++] = nums[j++]; 
        for(i = 0; i < k; i++) nums[l + i] = tmp[i];
    }
	void mergeSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int m = l + (r - l) / 2; 
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        
        return nums;
    }
};



