class Solution {
public:
    int happyCheck(int n){
        int s=0;
        while(n!=0){
            s+=pow((n%10),2);
            n=n/10;
        }
        return s;
    }
    bool isHappy(int n) {
        //w=happyCheck(n);
        //int w;
        if(n==1 || n==7){
            return true;
        }
        if(n<=9 || n==11){
            return false;
        }
        while(n!=0){
            n=happyCheck(n);
            if(n==1){
                return true;
            }
            if(n==4){
                return false;
            }
        }
        return false;
    }
};


class Solution {
public:
    int getNext(int n){
        int totalSum = 0;
        while(n>0){
            int d=n%10;
            n=n/10;
            totalSum += d*d;
        }
        return totalSum;
    }
    bool isHappy(int n) {
        unordered_set<int>st;
        while(n!=1 && !st.count(n)){
            st.insert(n);
            n=getNext(n);
        }
        return n==1;
    }
};