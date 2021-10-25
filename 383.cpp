class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>v(26,0);
        
        for(int i=0;i<magazine.length();i++){
            v[magazine[i]-'a']++;
        }
        
        for(int i=0;i<ransomNote.length();i++){
            if(!v[ransomNote[i]-'a']){
                return false;
            }
            v[ransomNote[i]-'a']--;
        }
        return true;
    }
};