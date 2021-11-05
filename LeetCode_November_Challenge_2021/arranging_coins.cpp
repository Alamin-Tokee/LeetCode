//Iterative

class Solution {
public:
    int arrangeCoins(int n) {
        int m=n;
        for(int i=1;i<=n;i++){
            if(i > m) return i-1;
            else m=m-i;
        }
        return 0;
    }
};

//Recursive
class Solution {
public:
    int stairCase(int index,int n){
        if(index > n) return index-1;
        
        return stairCase(index+1,n-index);
    }
    int arrangeCoins(int n) {
       return stairCase(1,n);
    }
};