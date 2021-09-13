//Time Complexity O(n*m) Here m=number
//Space Complexity O(n)

class Solution {
public:
    int countDigit(int num){
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num=num/10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        vector<int>v(46,0);
        for(int i=lowLimit;i<=highLimit;i++){
            int digit=countDigit(i);
            v[digit]+=1;
        }
        int ma=INT_MIN;
        for(int i=0;i<46;i++){
            ma=max(ma,v[i]);
        }
        return ma;
    }
};


//Time Complexity O(n*m) Here m=number
//Space Complexity O(n)
class Solution {
public:
    int countDigit(int num){
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num=num/10;
        }
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        map<int,int>mp;
        for(int i=lowLimit;i<=highLimit;i++){
            int digit=countDigit(i);
            mp[digit]++;
        }
        int ma=INT_MIN;
        for(auto it=mp.begin();it!=mp.end();it++){
            ma=max(ma,it->second);
        }
        return ma;
    }
};