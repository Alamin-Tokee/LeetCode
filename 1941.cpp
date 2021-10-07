class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        auto it=mp.begin();
        int x=it->second;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second != x ) return false;
        }
        return true;
    }
};