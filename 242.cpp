class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
             return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        if(s!=t) return false;
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        
        int mpS[26] = {0}, mpT[26] ={0};
        for(int i=0;i<s.length();i++){
            mpS[s[i]-'a']++;
            mpT[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(mpS[i]!=mpT[i]) return false;
        }
        return true;
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        
        int mpS[26] = {0};
        for(int i=0;i<s.length();i++){
            mpS[s[i]-'a']++;
            mpS[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(mpS[i] > 0) return false;
        }
        return true;
    }
};