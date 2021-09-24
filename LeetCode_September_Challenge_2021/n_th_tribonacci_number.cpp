//General Approach
class Solution {
public:
    int dp[38]={0,1,1};
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        
        int a=0,b=1,c=1,d;
        for(int i=3;i<=n;i++){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return d;
    }
};

//Trabulization (Bottom up)
class Solution {
public:
    int tribonacci(int n) {
        vector<int>F(n+1,0);
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        F[0]=0;
        F[1]=F[2]=1;
        for(int i=3;i<=n;i++){
            F[i]=F[i-1]+F[i-2]+F[i-3];
        }
        
        return F[n];
    }
};

//Memoization (Top down approach)
class Solution {
public:
    int dp[38]={0,1,1};
    int tribonacci(int n) {
        if(!n || dp[n]) return dp[n];
        
        return dp[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};


