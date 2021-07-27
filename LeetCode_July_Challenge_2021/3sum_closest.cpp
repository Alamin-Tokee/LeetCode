// Two Pointer Approach
//Time Complexity O(n^2)
//Space Complesity O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int diff=INT_MAX,n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            int left = i+1,right = n-1;
            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];
                if(abs(target-sum) < abs(diff)){
                    diff=target-sum;
                }
                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return target - diff;
    }
};


class Solution {
public:
   int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(), nums.end());
         int minDis = INT_MAX;
         int minRes = INT_MAX;
         for(int i = nums.size()-1; i >= 2; --i){
             int left = 0;
             int right = i-1;
             while(left < right){
                 int total = nums[left] + nums[right] + nums[i];
                 if(total == target) 
                     return target;
                 else if(total < target)
                     left ++;
                 else
                     right--;
                        
                 if(abs(target-total) < minDis){
                        minRes = total;
                        minDis = abs(target-total);
                 }
             }
         }
         return minRes;
     } 
};

//Binary Search
//O(n^2 logn)
//Space Complexity O(n)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result=0;
        int distance=INT_MAX;
        for(int i=0; i<nums.size()-2; i++){
            for(int j=i+1; j<nums.size()-1; j++){
                int tong=nums[i]+nums[j];
                int end=nums.size()-1;
                int start=j+1;
                while(start<=end){
                    int mid=(start+end)/2;
                    int check=tong+nums[mid];
                    if(check<target){
                        start=mid+1;
                        if(distance>abs(check-target)){
                            distance=abs(check-target);
                            result=check;
                        }
                    }
                    else{
                        end=mid-1;
                        if(distance>abs(check-target)){
                            distance=abs(check-target);
                            result=check;
                        }
                    }
                }
                
            }
        }
        return result;
    }
};    


//Binary Search STL
// TIME COMPLEXITY:- O(N^2LOG(N))
// SPACE COMPLEXITY:- O(N)


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        pair<int,int> ans = {INT_MAX,INT_MAX};
        multiset<int> s(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                s.erase(s.find(nums[i]));
                s.erase(s.find(nums[j]));
                int required = target - (nums[i]+nums[j]);
                auto itr = s.upper_bound(required);
                if(itr!=s.end()){
                    if(abs(required-(*itr))<ans.first){
                        ans.first = abs(required-(*itr));
                        ans.second = nums[i] + nums[j] + (*itr);
                    }
                }
                itr--;
                if(abs(required-(*itr))<ans.first){
                    ans.first = abs(required-(*itr));
                    ans.second = nums[i] + nums[j] + (*itr);
                }
                s.insert(nums[i]);
                s.insert(nums[j]);
            }
        }
        return ans.second;
    }
};

