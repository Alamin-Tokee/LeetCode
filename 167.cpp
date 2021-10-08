class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n=num.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<n;i++){
            int val=target-num[i];
            if(mp.find(val)!=mp.end()){
                ans.push_back(mp[val]);
                ans.push_back(i+1);
                break;
            }else{
                mp[num[i]]=i+1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        vector<int> res;
    
        int n = numbers.size();
    
        int low=0,high = n-1;
    
        while(low<high){
            if(numbers[low]+numbers[high] == target){
                res.push_back(low+1);
                res.push_back(high+1);
                break;
            }else if(numbers[low]+numbers[high]>target){
                high--;
            }else{
                low++;
            }
       }
       return res;
    }
};

