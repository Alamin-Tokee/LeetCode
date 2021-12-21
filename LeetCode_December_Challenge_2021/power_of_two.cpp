class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n==0) return false;
        int count=0;
        while(n!=0){
            if(n&1 && n!=1) count++;
            n=n/2;
        }
        if(count==0) return true;
        else return false;
        
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0||n%2!=0&&n>2) return 0;
        if(n==1)  return 1;
        return isPowerOfTwo(n/2);
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        f(n<=0) return false;
        return !(n&n-1);
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)return false;
        return ceil(log2(n))==floor(log2(n));
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
       if(n<1) return false;
        else if(__builtin_popcount(n)==1) return true;
        else return false;        
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
       if(n == 0) return false;
        int count = 0;
        while(n){
            if(n & 1){
                count++;
            }
            if(count > 1) return false;
            n = n >> 1;
        }
        return true;
    }
};


class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool isPower = false;
        if(n==0 or n==INT_MIN) return false;
        for(int i=0;i<32;i++){
            if(((n>>i)&1)==1){
                if(isPower) return false;
                isPower = true;
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==-2147483648) return false;
        bitset<32>power(n);
        return power.count()==1;
    }
};



class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 and (1 << 31) % n == 0;
    }
};