
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

// #SegmentTree #Segment #Trees #MergeSort
// Time Complexity: Sum: O(logn), Update: O(logn)
// Space Complexity: O(n) for the segment tree
class NumArray {
public:
    vector<int>seg;
    int n;
    void buildTree(vector<int>&nums,int pos,int left,int right){
        if(left==right){
            seg[pos]=nums[left];
            return;
        }
        int mid=(left+right)/2;
        buildTree(nums,2*pos+1,left,mid);
        buildTree(nums,2*pos+2,mid+1,right);
        seg[pos]=seg[2*pos+1]+seg[2*pos+2];
    }
    int rangeUtil(int qlow,int qhigh,int low,int high,int pos){
        if(qlow <= low && qhigh>=high){
            return seg[pos];
        }
        if(qlow > high || qhigh < low) return 0;
        
        int mid=low+(high-low)/2;
        
        return (rangeUtil(qlow,qhigh,low,mid,2*pos+1)+rangeUtil(qlow,qhigh,mid+1,high,2*pos+2));
    }
    NumArray(vector<int>& nums) {
        if(nums.size()>0){
            n=nums.size();
            seg.resize(4*n,0);
            buildTree(nums,0,0,n-1);
        }
    }
    
    int sumRange(int left, int right) {
        if(n==0) return 0;
        return rangeUtil(left,right,0,n-1,0);
    }
};
