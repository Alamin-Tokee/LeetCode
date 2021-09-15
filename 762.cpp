//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    bool isPrime(int number){
        for(int i=2; i*i<=number; i++){
            if(number%i == 0){
                return false;
            }
        }
        return number > 1;
    }
    int countPrimeSet(int num){
        int cnt=0;
        while(num>0){
            cnt+=num%2;
            num=num/2;
        }  
        return cnt;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int countSet=countPrimeSet(i);
            ans+=isPrime(countSet);
        }
        return ans;
    }
};