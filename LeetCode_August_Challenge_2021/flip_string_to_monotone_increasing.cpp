//First Approach
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.length();
        int oneCount=0,zeroCount=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zeroCount++;
            }else{
                oneCount++;
            }
            zeroCount=min(zeroCount,oneCount);
        }
        return zeroCount;
    }
};