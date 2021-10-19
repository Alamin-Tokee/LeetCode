class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i=1;i<=32;i++){
            ans<<=1;
            ans=ans|(n&1);
            n>>=1;
        }
        return ans;
    }
};


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        #define BIT(x)  (1 << x)
        int i = 31;
        int j = 0;
        uint32_t result = n;

        while (j < i) {
            bool r = result & BIT(j);
            bool l = result & BIT(i);

            if (r)
                result |= BIT(i);
            else
                result &= ~BIT(i);

            if (l)
                result |= BIT(j);
            else
                result &= ~BIT(j);

            j++;
            i--;
        }

        return result;
    }
};


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0; 
        for (int i = 0; i < 32; ++i) 
            if (n & 1 << i) ans ^= 1 << 31-i; 
        return ans; 
    }
};

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {

    uint32_t reverse = 0;   
    uint8_t power = 31;     
                            
    
    while(n && power >= 0) {
        if(n%2 != 0) reverse += pow(2.0, power); 
        --power;        
        n = n >> 1;     
    }
    
    return reverse;
}
};
