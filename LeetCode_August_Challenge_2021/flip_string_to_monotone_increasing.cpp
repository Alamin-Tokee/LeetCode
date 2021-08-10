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


//Second Approach(DP)
//Time Complexity O(n)
//Space Complexity O(b)
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        //Keep track of left one's and right Zeroes for each element.
        // Now for every element, total flips are (leftOnes + rightZeroes)
        // i.e, leftOnes are flipped from 1 to 0, rightZeroes are flipped from 0 to 1
        //Don't require to bother about current element
        // Find the minimum.
        int n=s.size();
        vector<int>leftOnes(n, 0);
        vector<int>rightZeroes(n,0);
        for(int i=1;i<n;i++)
            leftOnes[i]=leftOnes[i-1]+((s[i-1]=='1')?1:0);
        for(int i=n-2;i>=0;i--) {
            rightZeroes[i]=rightZeroes[i+1]+((s[i+1]=='0')?1:0);
        }
        for(int i=0;i<n;i++){
            cout<< leftOnes[i] << " ";
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++) {
            res=min(res, leftOnes[i]+rightZeroes[i]);
        }
        return res;
    }
};