class Solution {
public:
    int trailingZeroes(int n) {
        int sum=0;
        if(n<0) return -1;
        for(int i=5;n/i>=1;i*=5){
            sum+=n/i;
        }
        return sum;
    }
};


class Solution {
public:
    int trailingZeroes(int n){
        int p = 5, ans = 0;
        while (n / p){
            ans += n / p;
            p *= 5;
        }
        return ans;
     }
};