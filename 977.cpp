class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        
        sort(begin(nums),end(nums));
        
        return nums;
    }
};


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res(nums.size());
        int l=0;
        int r=nums.size()-1;
        int k=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(abs(nums[l])>abs(nums[r])){
                res[i]=nums[l]*nums[l];
                ++l;
            }
            else{
                res[i]=nums[r]*nums[r];
                --r;
            }
        }
        return res;
    }
};

       // while(l<=r){
       //      if(abs(nums[l])<abs(nums[r])){
       //          res[k]=pow(nums[r],2);
       //          k--;
       //          r--;
       //      }
       //      else
       //      {
       //          res[k]=pow(nums[l],2);
       //          k--;
       //          l++;
       //      }
       //  }