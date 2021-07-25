//Brute Force Solution
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int check(int n){
        int i = 31;
        while(i > 0){
            if((n&(1<<i))!=0 && (n&(1<<(i-1)))!=0) return false;
            i--;
        }
        return true;
    }
    int findIntegers(int n) {
        int count = 0;
        for(int i=0;i<n;i++){
            if(check(i))
                count++;
        }

        return count;
    }
};
//Recursive Solution
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
private:
    int countValidInteger(int number,int limit){
        if(number>limit) return 0;
        
        if(number & 1){
            return 1 + countValidInteger((number << 1) | 0, limit);
        }else{
            return 1 + countValidInteger((number << 1) | 0, limit) + countValidInteger((number << 1) | 1, limit);
        }
    }
public:
    int findIntegers(int n) {
        return 1+countValidInteger(1,n);
    }
};