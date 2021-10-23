class Solution {
public:
    bool matchConsistent(string& word,vector<int>&v){
        for(int i=0;i<word.size();i++){
            if(!v[word[i]-'a']) return false;
        }
        return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>v(26,0);
        for(int i=0;i<allowed.size();i++){
            v[allowed[i]-'a']++;
        }
        int count=0;
        for(auto word:words){
            bool match=matchConsistent(word,v);
            if(match) count++;
        }
        return count;
    }
};