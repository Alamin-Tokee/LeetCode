//Brute Force Solution
//Time Complexity O(n)
//Space Complexity O(1)

//1 << 0 = `0000 0001`
// 1 << 1 = `0000 0010`
// 1 << 2 = `0000 0100`
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

//Dp Solution
//Time Complexity O(log2(max_int)==32)
//Space Complexity O(log2(max_int)==32)
class Solution {
public:
    int findIntegers(int num) {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i)
            f[i] = f[i-1]+f[i-2];
        int ans = 0, k = 30, pre_bit = 0;
        while (k >= 0) {
            if (num&(1<<k)) {
                ans += f[k];
                if (pre_bit) return ans;
                pre_bit = 1;
            }
            else
                pre_bit = 0;
            --k;
        }
        return ans+1;
    }
};