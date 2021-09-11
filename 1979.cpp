//Aproach 1
class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int ma=INT_MIN;
        int mi=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mi=min(mi,nums[i]);
            ma=max(ma,nums[i]);
        }
        return gcd(ma,mi);
    }
};

//Approach 2
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int ma=INT_MIN;
        int mi=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mi=min(mi,nums[i]);
            ma=max(ma,nums[i]);
        }
        return __gcd(ma,mi);
    }
};

//Aproach 3
class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return __gcd(nums[0],nums[nums.size()-1]);
    }
};