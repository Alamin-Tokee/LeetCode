class Solution {
public:
    int hammingDistance(int x, int y) {
        int xy=x^y;
        
        return __builtin_popcount(xy);
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        int xy=x^y;
        while(xy){
            xy&=xy-1;
            count++;
        }
        return count;
    }
};