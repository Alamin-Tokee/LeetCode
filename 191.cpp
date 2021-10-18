class Solution {
public:
    int hammingWeight(uint32_t n) {

        int sum= __builtin_popcount(n);
        
        return sum;

    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bs(n);
        int count=0;
        for(int i=0;i<32;i++){
            if(bs[i]==1){
                count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int setBitCount = 0;
        
        while (n) { // equivalent to n != 0
            n &= (n - 1); // to clear the right most set bit
            ++setBitCount;
        }
        
        return setBitCount;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        
        while(n != 0) {
            if(n&1) 
                count++;
            
            n = n>>1; 
        }
        
        return count;
    }
};