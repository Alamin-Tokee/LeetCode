//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0;
        while(i < nums.size()){
            int j = i;
            while(j < nums.size()-1 && nums[j]==nums[j+1]-1) j++;
            if(i==j){
                ans.emplace_back(to_string(nums[i]));
                i++;
            }else{
                ans.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
                i=j+1;
            }
        }
        return ans;
    }
};

//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int start, end;
        for(int i=0;i<nums.size();i++){
            start=nums[i], end=nums[i];
            string temp="";
            while(i+1<nums.size() && nums[i+1]==nums[i]+1){
                end=nums[++i];
            }
            if(start!=end)
                temp=to_string(start)+"->"+to_string(end);
            else
                temp=to_string(start);
            ans.push_back(temp);
        }
        
        return ans;
    }
};