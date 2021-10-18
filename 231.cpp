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