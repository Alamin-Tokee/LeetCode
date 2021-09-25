class Solution {
public:
    int titleToNumber(string s) {
        int index=s.length()-1;
        int ans=0;
        long long int num=1;
        
        while(index >= 0){
            ans+=num*((s[index]-'A')+1);
            num*=26;
            index--;
        }
        return ans;
    }
};

class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;

        for(int i=0;i<s.length();i++){
            ans*=26;
            ans+=(s[i]-'A')+1;
        }
        
        return ans;
    }
};


class Solution {
public:
    int titleToNumber(string s) {
        int ans=0,val=0;
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            val=(s[i]-'A')+1;
            ans+=pow(26,n-i-1)*val;
        }
        
        return ans;
    }
};