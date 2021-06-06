//Time complexity O(nlogn) and for loop take O(n)
//Space complexity O(n) or O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        
        //At first solve simple test case
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2 && nums[0]==nums[1]) return 1;
        
        //Sort the array
        sort(nums.begin(),nums.end());
        
        //Unique valus store in a vector
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1])
                v.push_back(nums[i]);
        }
        
        //Count the consecutive sequence 
        int c=1;
        int ma=0;
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1]+1){
                c++;
            }else{
                c=1;
            }
            ma=max(ma,c);
        }
        
        return ma;
    }
};