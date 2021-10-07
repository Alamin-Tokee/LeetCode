class Solution {
public:
    bool checkIfPangram(string s) {
        int n=s.length();
        int mp[26]={0};
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }
        
        for(auto x:mp){
            if(x == 0) return false;
        }
        
        return true;
    }
};