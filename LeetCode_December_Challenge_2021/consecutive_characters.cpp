//Brite Force Approach 
//Time Complexity O(n^2)
//Space Complexity O(1)
class Solution {
public:
    int maxPower(string s) {
        int len=s.size();
        int ma=INT_MIN;
        int c=0;
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                if(s[i]==s[j]){
                    c++;
                    cout<<c<<endl;
                    ma=max(ma,c);
                }else{
                    c=0;
                }
            }
            c=0;
        }
        return ma;
    }
};


//Better Approach 
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    int maxPower(string s) {
        int n=s.length();
        char ch = s[0];
        int cnt = 1;
        int ans = 1;
        //if(n==1) return 1;
        for(int i=1;i<n;i++){
            if(ch == s[i]){
                cnt++;
            }else cnt = 1;
            
            ans = max(ans,cnt);
            ch = s[i];
        }
        return ans;
    }
};

class Solution {
public:
   int maxPower(string s) {
        if(s.size() == 1) return 1;
        int currMax = 0;
        int maxLen = 0;
        
        for(int i=1; i<s.size(); i++) {
            if(s[i] == s[i-1])
                currMax++;
            else
                currMax = 0;
            
            maxLen = max(maxLen, currMax+1);
        }
        
        return maxLen;
    }
};

class Solution {
public:
    int maxPower(string s) {
        int ans=1;
        int k=0;
        s += '*';
        for (int i = 0; i < s.length()-1; ++i)
            if (s[i] != s[i + 1]) {
                ans = max(ans, i + 1 - k);
                k = i + 1;
            }
        return ans;
    }
};