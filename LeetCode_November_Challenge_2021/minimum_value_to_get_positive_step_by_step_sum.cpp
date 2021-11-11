class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int count;
        bool flag;
        for(int ii=1;ii<2000;ii++){
            count=ii;
            flag=true;
            for(auto n:nums){
                count+=n;
                if(count<1){
                    flag=false;
                    break;
                }
            }
            if(flag==true) return ii;
        }
        return NULL;
    }
};


class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mi=INT_MAX;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mi=min(mi,sum);
        }
        return mi >= 1 ? 1 : 1-mi;
    }
};