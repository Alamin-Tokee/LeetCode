class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int count=0;
        for(int i=0;i<t.length();i++){
            if(!mp[t[i]]){
                count++;
            }else if(mp[t[i]]){
                mp[t[i]]--;
            }
        }
        return count;
    }
};

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>v(26,0);
        for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<t.length();i++){
            if(!v[t[i]-'a']){
                count++;
            }else if(v[t[i]-'a']){
                v[t[i]-'a']--;
            }
        }
        return count;
    }
};