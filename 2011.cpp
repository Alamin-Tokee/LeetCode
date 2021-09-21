class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int sum=0;
        for(auto x:operations){
            if(x[2]=='+') sum+=1;
            else if(x[0]=='+') sum+=1;
            else if(x[0]=='-') sum-=1;
            else sum-=1;
        }
        return sum;
    }
};