class Solution {
public:
    char findTheDifference(string s, string t) {
        map<int,int>m;
        for(int i=0;i<t.size();i++) m[t[i]]++;
        for(int i=0;i<s.size();i++) m[s[i]]--;
        for(auto c:m){
            if(c.second > 0) return c.first;
        }
        return '-';
    }
};