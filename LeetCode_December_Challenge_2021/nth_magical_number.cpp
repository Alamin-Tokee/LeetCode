//Time Complexity O(N*min(A,B))
//Space Complexity(1)

class Solution {
public:
    // int gcd(int x,int y){
    //     if(x==0) return y;
    //     return gcd(y%x,x);
    // }
    int gcd(int x,int y){
        if(y==0) return x;
        return gcd(y,x%y);
    }
    int nthMagicalNumber(int n, int a, int b) {
        int MOD=1e9+7;
        int lcm=a/gcd(a,b)*b;
        
        auto isMagic = [&](long x){return (x/a)+(x/b)-(x/lcm);};
        
        long lo=0;
        long hi=(long)n*min(a,b);
        
        while(lo<hi){
            long mi=lo+(hi-lo)/2;
            if(isMagic(mi) < n){
                lo=mi+1;
            }else{
                hi=mi;
            }
        }
        return (int)(lo % MOD);
    }
};
